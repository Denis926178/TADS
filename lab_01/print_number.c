#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "parser.h"
#include "print_number.h"

void print_number(result_t result_number)
{
    printf("------------------------------------\n");
    printf("Result: ");
    
    if (result_number.mantissa_sign < 0)
        printf("-");

    printf("0.");

    for (int i = SIZE_RESULT - 1; i >= result_number.start; i--)
        printf("%d", result_number.mantiss[i]);

    printf("E%d\n", result_number.exp);
    
    printf("------------------------------------\n");
}
