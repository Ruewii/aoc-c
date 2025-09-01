#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/utils/strings.h"
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

    int boundary = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            push(&arr, slice(str, boundary, i));
            boundary = i + 1;
        }
    }

    push(&arr, slice(str, boundary, strlen(str)));  // push last token
    push(&arr, NULL);                               // push terminator

    return arr.data;
}

char *trim(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
    return str;
}
