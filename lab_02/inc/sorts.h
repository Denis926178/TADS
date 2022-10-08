#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

#include "defines.h"
#include "struct.h"

void swap_ages(describtion_t a, describtion_t b);
int bubble_sort_age(describtion_t *array, int counter);
void swap_keys(keys_t a, keys_t b);
int bubble_sort_keys(keys_t *keys, int counter);
int compare_table(const void *a, const void *b);
int compare_keys(const void *a, const void *b);
int qsort_table(describtion_t *array, int counter);
int qsort_table_keys(keys_t *keys, int counter);

#endif
