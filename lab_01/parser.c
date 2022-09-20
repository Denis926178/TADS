#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"
#include "parser.h"

#define ERROR_TOO_LARGE_EXP     6

void isminus(char **temp_symbol, int *field)
{
    if (**temp_symbol == '-')
        *field = -1;
    else if (**temp_symbol != '+')
        (*temp_symbol)--;

    (*temp_symbol)++;
}

int parser_to_structure(char *material_number_s, char *integer_number_s, material_t *material_number, whole_t *integer_number)
{
    char *temp_symbol = material_number_s;
    int i = 0;
    int exp_diff = 0;
    isminus(&temp_symbol, &material_number->mantissa_sign);

    while (strchr("e.E\0", *temp_symbol) == NULL)
        material_number->mantiss[SIZE_MANTISS - 1 - i++] = *(temp_symbol++) - '0';
 
    switch (*temp_symbol)
    {
        case '.':
            temp_symbol++;
 
            while (strchr("eE\0", *temp_symbol) == NULL)
            {
                 material_number->mantiss[SIZE_MANTISS - 1 - i++] = *(temp_symbol++) - '0';
                 exp_diff--;
            }
            if ((*temp_symbol != 'e') && (*temp_symbol != 'E'))
                break;

        case 'e':
        case 'E':
            temp_symbol++;
            isminus(&temp_symbol, &material_number->exp_sign);
            int pw = strlen(temp_symbol);

            while (*temp_symbol != '\0')
                material_number->exp += (*(temp_symbol++) - '0') * (int)pow(10, pw-- - 1);

            break;
    }

    material_number->exp = material_number->exp_sign * material_number->exp + exp_diff;

    if (material_number->exp > 99999 || material_number->exp < -99999)
    {
        printf("Слишком большой размер у экпоненты\n");
        return ERROR_TOO_LARGE_EXP;
    }

    material_number->start = SIZE_MANTISS - i;   
    temp_symbol = integer_number_s;
    isminus(&temp_symbol, &integer_number->sign);
    i = 0;
 
    while (*temp_symbol != '\0')
        integer_number->digits[SIZE_INT - 1 - i++] = *(temp_symbol++) - '0';

    integer_number->start = SIZE_INT - i;

    return EXIT_SUCCESS;   
}
