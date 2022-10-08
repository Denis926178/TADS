#include "../inc/sorts.h"

void swap_ages(describtion_t a, describtion_t b)
{
    describtion_t temp = a;
    a = b;
    b = temp;
}

int bubble_sort_age(describtion_t *array, int counter)
{
    if (counter == 0)
        ERROR_EMPTY_TABLE;
    
    for (int i = 0; i < counter - 1; i++)
        for (int j = 0; j < counter - i - 1; j++)
            if (array[j].age > array[j + 1].age)
                swap_ages(array[j], array[j + 1]);

    return EXIT_SUCCESS;
}

void swap_keys(keys_t a, keys_t b)
{
    keys_t temp = a;
    a = b;
    b = temp;
}

int bubble_sort_keys(keys_t *keys, int counter)
{
    if (counter == 0)
        ERROR_EMPTY_TABLE;
    
    for (int i = 0; i < counter - 1; i++)
        for (int j = 0; j < counter - i - 1; j++)
            if (keys[j].age > keys[j + 1].age)
                swap_keys(keys[j], keys[j + 1]);

    return EXIT_SUCCESS;
}

int compare_table(const void *a, const void *b)
{
    return ((describtion_t*)(a))->age - ((describtion_t*)(b))->age;
}

int compare_keys(const void *a, const void *b)
{
    return ((keys_t*)(a))->age - ((keys_t*)(b))->age;
}

int qsort_table(describtion_t *array, int counter)
{
    if (counter == 0)
        ERROR_EMPTY_TABLE;
    
    qsort(array, counter, sizeof(describtion_t), compare_table);

    return EXIT_SUCCESS;
}

int qsort_table_keys(keys_t *keys, int counter)
{
    if (counter == 0)
        ERROR_EMPTY_TABLE;
    
    qsort(keys, counter, sizeof(keys_t), compare_keys);

    return EXIT_SUCCESS;
}
