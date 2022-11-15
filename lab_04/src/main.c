#include <stdio.h>
#include <stdbool.h>

#include "menu.h"
#include "errors.h"
#include "arr_stack.h"
#include "list_stack.h"
#include "free_areas.h"

#define OK 0

int main(void)
{
    int exit_code = OK;
    arr_stack_t arr_stack = { .length = 0 };
    list_stack_t *list_stack = NULL;
    free_areas_t ptrs = { .len = 0 };

    while (true)
    {
        short int action;
        print_menu();
        exit_code = choose_action(&action);

        if (exit_code)
        {
            print_error_message(exit_code);
            continue;
        }

        exit_code = do_action(action, &arr_stack, &list_stack, &ptrs);

        if (exit_code)
        {
            print_error_message(exit_code);
            continue;
        }
    }

    return OK;
}