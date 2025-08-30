#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    char **data;
    int length;
    int size;
} StringArray;

void init(StringArray *arr);

void push(StringArray *arr, char *s);

#endif
