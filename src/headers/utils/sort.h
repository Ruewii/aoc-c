#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

enum DataType { SORT_INT, SORT_FLOAT };

enum SortMode {
    SortMode_Asc,
    SortMode_Desc,
};

typedef struct SortArray {
    enum DataType type;
    size_t size;
    union {
        int *i_arr;
        float *f_arr;
    };
} SortArray;

int sort(SortArray *arr, enum SortMode mode);

#endif
