#include "headers/utils/strings.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/utils/array.h"

char *slice(const char *str, int start, int end) {
    if (end < start) return NULL;

    int len = end - start;
    char *out = malloc(len + 1);

    if (!out) return NULL;

    strncpy(out, str + start, len);
    out[len] = '\0';
    return out;
}

char **split(char *str, char sep) {
    StringArray arr;
    init(&arr);

    int b = 0;  // boundary
    int c = 0;  // cursor
    while (str[c] != '\0') {
        // skip leading separators
        while (str[c] != '\0' && str[b] == sep) b++;

        // oh it's the end of string? break.
        if (str[b] == '\0') break;
        c = b;

        // scan until next sep or end
        while (str[c] != '\0' && str[c] != sep) c++;

        // slice if not empty
        if (c > b) push(&arr, slice(str, b, c));

        // boundary skip after separator
        b = c + 1;
    }

    return arr;
}

char *trim(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
    return str;
}
