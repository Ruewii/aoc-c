#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *load_input(const char *filename) {
    FILE *f = fopen(filename, "r");  // open file from filename as read only
    if (!f) {
        // perror("failed to load input file");
        fprintf(stderr, "failed to load input file: %s\n", filename);
        exit(1);
    }
    fseek(f, 0, SEEK_END);  // stream full
    long size = ftell(f);   // get file size
    rewind(f);              // seek to 0

    char *buf = malloc(size + 1);  // create buffer for file
    fread(buf, 1, size, f);        // read chunks to *buf
    buf[size] = '\0';              // add NULL terminator for safety
    fclose(f);                     // close handle
    return buf;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <day>\n", argv[0]);
        return 1;
    }

    int day = atoi(argv[1]);

    // find solutions
    char *soldir = "src/solutions";
    struct dirent *e;
    DIR *dr = opendir(soldir);

    if (dr == NULL) {
        // perror("could not find solution directory");
        fprintf(stderr, "could not find solution dir: %s\n", soldir);
        return 1;
    }

    char *solname;
    while ((e = readdir(dr)) != NULL) {
        if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0) {
            continue;
        }

        char e_day[3];
        snprintf(e_day, sizeof(e_day), "%.2s", e->d_name);

        int i_day = atoi(e_day);
        if (i_day == day) {
            solname = e->d_name;
            break;
        }
    }

    if (solname == NULL) {
        fprintf(stderr, "solution does not exist: %d", day);
        return 1;
    }

    // build paths
    char solpath[256], inpath[256];
    snprintf(solpath, sizeof(solpath), "src/solutions/%s/module.so", solname);
    snprintf(inpath, sizeof(inpath), "src/inputs/%s.txt", solname);

    // loads input
    char *input = load_input(inpath);

    // load sol module from path
    void *handle = dlopen(solpath, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 1;
    }

    // declare function pointer type
    void (*solve)(char *);

    // load function reference to solve
    solve = (void (*)(char *))dlsym(handle, "solve");
    if (!solve) {
        fprintf(stderr, "dlsym error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    solve(input);

    // clean up
    free(input);
    dlclose(handle);
    return 0;
}
