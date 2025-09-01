#ifndef ARRAY_H
#define ARRAY_H

typedef struct StringArray {
    char **data;
    int length;  // amount of data stored, excluding the NULL terminator
    int size;    // total size / capacity
} StringArray;

void init(StringArray *arr);

void push(StringArray *arr, char *s);

void *get(StringArray *arr, int i);

void destroy(StringArray *arr);

#endif
