#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"
#include "parser.h"

void isminus(char **temp_symbol, int *field)
{
    if (**temp_symbol == '-')
        *field = -1;
    else if (**temp_symbol != '+')
        (*temp_symbol)--;

    (*temp_symbol)++;
}

void parser_to_structure(char *material_number_s, char *integet_number_s, material_t *material_number, whole_t *integet_number)
{
    char *temp_symbol = material_number_s;
    int i = 0;
    int exp_diff = 0;
    isminus(&temp_symbol, &material_number->sing_mantissa);

    while (strchr("e.E\0", *temp_symbol) == NULL)
        material_number->mantiss[SIZE_MANTISS - 1 - i++] = *(temp_symbol++) - '0';
 
    switch (*temp_symbol)
    {
        case 'e':
        case 'E':
            temp_symbol++;
            isminus(&temp_symbol, &material_number->exp_sign);
            int pw = strlen(temp_symbol);

            while (*temp_symbol != '\0')
                material_number->exp += (*(temp_symbol++) - '0') * (int)pow(10, pw-- - 1);

            material_number->exp = material_number->exp_sign * material_number->exp + exp_diff;

        case '.':
            temp_symbol++;
 
            while (strchr("eE\0", *temp_symbol) == NULL)
            {
                 material_number->mantiss[SIZE_MANTISS - 1 - i++] = *(temp_symbol++) - '0';
                 exp_diff--;
            }
    }
 
    material_number->start = SIZE_MANTISS - i;   
    temp_symbol = integet_number_s;
    isminus(&temp_symbol, &integet_number->sign);
    i = 0;

    while (*temp_symbol != '\0')
        integet_number->digits[SIZE_INT - 1 - i++] = *(temp_symbol++) - '0';

    integet_number->start = SIZE_INT - i;
    
}
