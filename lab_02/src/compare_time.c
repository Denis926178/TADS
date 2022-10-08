#include "../inc/compare_time.h"

uint64_t tick_count(void)
{
    uint32_t high, low;
    __asm__ __volatile__ (
        "rdtsc\n"
        "movl %%edx, %0\n"
        "movl %%eax, %1\n"
        : "=r" (high), "=r" (low)
        :: "%rax", "%rbx", "%rcx", "%rdx"
        );

    uint64_t ticks = ((uint64_t)high << 32) | low;

    return ticks;
}

short int compare_sorts()
{
    int64_t start1, end1, start2, end2, start4, end4;

    describtion_t array[MAX_SIZE_ARRAY];
    describtion_t array_copy[MAX_SIZE_ARRAY];
    keys_t keys[MAX_SIZE_ARRAY];
    keys_t keys_copy[MAX_SIZE_ARRAY];

    int counter = 0;

    int rc = make_table(array, &counter);
	if (rc != 0)
        return rc;
    
    for (int i = 0; i < counter; i++)
        array_copy[i] = array[i];

    printf("\n\nСортировка файла из %d записей\n\n", counter);
    puts("|----------------------------------------------------------------------------------|");

    start1 = tick_count();
    bubble_sort_age(array, counter);
    end1 = tick_count();

    printf("| Сортировка таблицы пузырьком         |");
    print_result(start1, end1);
    puts("|----------------------------------------------------------------------------------|");
 
    start2 = tick_count();
    bubble_sort_keys(keys, counter);
    end2 = tick_count();

    printf("| Сортировка таблицы ключей пузырьком  |");
    print_result(start2, end2);
    puts("|----------------------------------------------------------------------------------|");

    for (int i = 0; i < counter; i++)
    {
        array[i] = array_copy[i];
        keys[i] = keys_copy[i];
    }

    start2 = tick_count();
    qsort_table(array, counter);
    end2 = tick_count();

    printf("| Сортировка таблицы qsort             |");
    print_result(start2, end2);
    puts("|----------------------------------------------------------------------------------|");   
        
    start4= tick_count();
    qsort_table_keys(keys, counter);
    end4 = tick_count();

    printf("| Сортировка таблицы ключей qsort      |");
    print_result(start4, end4);
    puts("|----------------------------------------------------------------------------------|"); 
    

    printf("\n%lu размер таблицы (в байтах)\n\n", sizeof(*array) * counter);
    printf("\n%lu размер таблицы ключей (в байтах)\n\n", sizeof(*keys) * counter);
    
    return rc;
}
