#include "headers/utils/sort.h"

#include <stdio.h>

int compare_int_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_int_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int sort(SortArray *arr, enum SortMode mode) {
    if (!arr) return -1;

    if (arr->type == SORT_INT) {
        qsort(arr->i_arr, arr->size, sizeof(int),
              mode == SortMode_Asc ? compare_int_asc : compare_int_desc);
    }

    // TODO: float

    return 0;
}
