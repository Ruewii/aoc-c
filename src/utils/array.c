#include "headers/utils/array.h"

#include <stdlib.h>

void init(StringArray *arr) {
    arr->length = 0;
    arr->size = 4;
    arr->data = malloc(arr->size * sizeof(char *));
}

void push(StringArray *arr, char *s) {
    if (arr->length == arr->size) {
        arr->size *= 2;
        arr->data = realloc(arr->data, arr->size * sizeof(char *));
    }
    arr->data[arr->length++] = s;
}
