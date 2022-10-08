#include <stdio.h>
#include <stdlib.h>

#include "../inc/defines.h"
#include "../inc/struct.h"
#include "../inc/sorts.h"
#include "../inc/options.h"
#include "../inc/compare_time.h"
#include "../inc/read.h"
#include "../inc/print.h"

int main(int argc, char **argv)
{
    print_options();
    int counter, mode, code_return;

    while ((code_return = select_mode(&mode)))
    {
        printf("%sВы ввели неверный номер действия, введите заново опцию, которую нужно выполнить!%s\n", RED, RESET);
        print_options();
    }

    describtion_t array[MAX_SIZE_ARRAY];
    keys_t keys[MAX_SIZE_ARRAY];

    while (mode)
    {
        switch (mode)
        {
        case 1:
            code_return = make_table(array, &counter);
            for (int i = 0; code_return == 0 && i < counter; i++)
            {
                keys[i].index = i;
                keys[i].age = array[i].age;
            }

            break;
        case 2:
            code_return = print_table(array, counter);
            break;
        case 3:
            code_return = add_record(array, &counter);
            for (int i = 0; code_return == 0 && i < counter; i++)
            {
                keys[i].index = i;
                keys[i].age = array[i].age;
            }
            break;
        case 4:
            code_return = delete_record(array, &counter);
            for (int i = 0; code_return == 0 && i < counter; i++)
            {
                keys[i].index = i;
                keys[i].age = array[i].age;
            }
            break;
            break;
        case 5:
            code_return = print_table_in_keys(array, counter);
            break;
        case 6:
            code_return = bubble_sort_age(array, counter);
            break;
        case 7:
            code_return = qsort_table(array, counter);
            break;
        case 8:
            code_return = bubble_sort_keys(keys, counter);
            break;
        case 9:
            code_return = qsort_table_keys(keys, counter);
            break;
        case 10:
            code_return = print_keys(keys, counter);
            break;
        case 11:
            code_return = compare_sorts();
            break;
        default:
            printf("%sНеверно введен номер действия!%s\n", RED, RESET);
            break;
        }

        print_options();

        while ((code_return = select_mode(&mode)))
        {
            printf("%sВы ввели неверный номер действия, введите заново опцию, которую нужно выполнить!%s\n", RED, RESET);
            print_options();
        }
    }

    return EXIT_SUCCESS;
}
