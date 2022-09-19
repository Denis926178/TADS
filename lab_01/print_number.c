#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "parser.h"
#include "print_number.h"

void print_number(res_t result_number)
{
    printf("0.");

    for (int i = SIZE_RESULT - 1; i >= result_number.start; i--)
        printf("%d", result_number.mantiss[i]);

    if (result_number.sing_mantissa < 0)
        printf("E-%d\n", result_number.exp);
    else
        printf("E%d\n", result_number.exp);
}
