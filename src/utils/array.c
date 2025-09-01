#include "headers/utils/array.h"

#include <stdlib.h>

void init(StringArray *arr) {
    arr->length = 0;
    arr->size = 16;
    arr->data = malloc(arr->size * sizeof(char *));
    if (arr->data == NULL) {
        arr->size = 0;
        return;
    }
    arr->data[0] = NULL;
}

void push(StringArray *arr, char *s) {
    if (arr->length + 1 == arr->size) {
        arr->size *= 2;
        char **nalloc = realloc(arr->data, arr->size * sizeof(char *));
        if (nalloc == NULL) {
            return;
        }
        arr->data = nalloc;
    }
    arr->data[arr->length++] = s;
    arr->data[arr->length] = NULL;
}

void *get(StringArray *arr, int i) {
    if (i < 0 || i >= arr->length) return NULL;
    return arr->data[i];
}

void destroy(StringArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->length = 0;
    arr->size = 0;
}
