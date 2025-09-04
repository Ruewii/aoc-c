#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/utils/sort.h"
#include "headers/utils/strings.h"

#define LINES 1000 + 1  // total lines + null

int cmp_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve(char *input) {
    // debug purposes
    FILE *fptr;
    fptr = fopen("logs/debug.1.log", "w");
    if (!fptr) {
        printf("can't save log file: %s\n", strerror(errno));
    }

    int nums_a[LINES];
    int nums_b[LINES];

    int count = 0;

    while (*input) {
        nums_a[count] = strtol(input, &input, 10);
        while (*input == ' ' || *input == '\n') input++;
        if (*input == '\0') break;
        nums_b[count] = strtol(input, &input, 10);
        count++;
    }

    // qsort ignores null so never include (-1)
    qsort(nums_a, LINES - 1, sizeof(int), cmp_int);
    qsort(nums_b, LINES - 1, sizeof(int), cmp_int);

    // write logs and close
    if (fptr) {
        for (int i = 0; i < count; i++) {
            fprintf(fptr, "[%d] %d  %d\n", i + 1, nums_a[i], nums_b[i]);
        }
        fclose(fptr);
    }
}
