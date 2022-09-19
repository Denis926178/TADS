#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "parser.h"

#define REAL_START              material_number.start
#define INTEGER_START           integet_number.start
#define RES_START               REAL_START + INTEGER_START

#define COUNT_CURRENT_DIGIT { int temp = result_number->mantiss[i + j] + material_number.mantiss[i] * (j < SIZE_INT ? integet_number.digits[j] : 0) + rest;\
        result_number->mantiss[i + j] = temp % 10;\
        rest = temp / 10; }

void shift_mantiss_null(int *result_mantiss, int *result_exp,  int *material_mantiss, int *material_exp)
{
    for (int j = SIZE_RESULT - 1; j > 0; j--)
        *(result_mantiss + j + 1) = *(result_mantiss + j);
    (*result_exp)++;
    (*material_exp)--;
}

void shift_mantiss_to_round(int *result_mantiss, int *result_exp)
{
    for (int j = SIZE_MANTISS + 1; j < SIZE_RESULT; j++)
        *(result_mantiss + j - 1) = *(result_mantiss + j);
 
    *(result_mantiss + SIZE_RESULT - 1) = 1;
    *(result_exp)++;
}

void round_mantiss(int *result_number_mantiss, int *result_number_exp, int *i)
{
    *(result_number_mantiss + (*i)++) = 0;
 
    if (*i == SIZE_RESULT) 
        shift_mantiss_to_round(result_number_mantiss, result_number_exp);
 
    *(result_number_mantiss + (*i)++);
}

void multiply(material_t material_number, whole_t integet_number, res_t *result_number)
{
    result_number->sing_mantissa = material_number.sing_mantissa * integet_number.sign;
    result_number->exp_sign = material_number.exp_sign * integet_number.sign;
    result_number->exp = material_number.exp;

    for (int i = REAL_START; i < SIZE_MANTISS; i++)
        for (int j = INTEGER_START, rest = 0; j < SIZE_INT || rest; j++)
            COUNT_CURRENT_DIGIT;

    int i = SIZE_RESULT - 1;
    result_number->start = RES_START + 1;

    if (result_number->mantiss[SIZE_RESULT - 1] == 0)
        shift_mantiss_null(result_number->mantiss, &result_number->start, material_number.mantiss, &material_number.exp);

    result_number->start--;
    int flag = 0;

    if (result_number->mantiss[SIZE_MANTISS - 1] >= 5)
    {
        result_number->mantiss[SIZE_MANTISS]++; 
        result_number->start = 30;
    }
 
    i = SIZE_MANTISS;

    while (result_number->mantiss[i] == 10 && i < SIZE_RESULT)
        round_mantiss(result_number->mantiss, &result_number->exp, &i);
 
    i = result_number->start;
    
    while (i < SIZE_RESULT && result_number->mantiss[i++] == 0)
    {
        result_number->exp++;
        result_number->start++;
    }

    result_number->exp += SIZE_RESULT - result_number->start;
}
