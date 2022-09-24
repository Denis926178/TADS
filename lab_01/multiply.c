#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "parser.h"

#define ERROR_RESULT_EXP        { printf("Невозможно перемножить два числа\n"); return 5; }
#define LEN_NUMBER              30

#define COUNT_CURRENT_DIGIT { int temp = result_number->mantiss[i + j] + material_number.mantiss[i] * (j < SIZE_INT ? integer_number.digits[j] : 0) + rest;\
        result_number->mantiss[i + j] = temp % 10;\
        rest = temp / 10; }

int check_null(int *digits)
{
    for (int i = 0; i < LEN_NUMBER; i++)
        if (*(digits + i) != 0)
            return EXIT_SUCCESS;
    
    return EXIT_FAILURE;
}

void shift_mantiss_null_before_act(int flag, int *digits, int i, int *result_number)
{
    while (!flag && *(digits + i) == 0)
    {
        for (int j = SIZE_INT - 1; j > 0; j--)
            *(digits + j + 1) = *(digits + j);
        (*result_number)--;
    }
}

void shift_mantiss_null_after_act(int *result_mantiss, int *result_exp, int *material_exp)
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
    (*result_exp)++;
}

void round_mantiss(int *result_number_mantiss, int *result_number_exp, int *i)
{
    *(result_number_mantiss + (*i)) = 0;
    (*i)++;
    if (*i == SIZE_RESULT - 1)
        (*result_number_exp)++;
        //shift_mantiss_to_round(result_number_mantiss, result_number_exp);
 
    *(result_number_mantiss + *i) += 1;
}

int multiply(material_t material_number, whole_t integer_number, res_t *result_number)
{
    int real_start = material_number.start;
    int integer_start = integer_number.start;
    int res_start = real_start + integer_start;

    result_number->mantissa_sign = material_number.mantissa_sign * integer_number.sign;
    result_number->exp_sign = material_number.exp_sign;
    result_number->exp = material_number.exp;

    int flag = check_null(integer_number.digits);     
    int i = SIZE_INT - 1;
    shift_mantiss_null_before_act(flag, integer_number.digits, i, &result_number->exp); 
    flag = check_null(material_number.mantiss);
    shift_mantiss_null_before_act(flag, material_number.mantiss, i, &result_number->exp);

    for (int i = real_start; i < SIZE_MANTISS; i++)
        for (int j = integer_start, rest = 0; j < SIZE_INT || rest; j++)
            COUNT_CURRENT_DIGIT;

    i = SIZE_RESULT - 1;
    result_number->start = res_start + 1;

    if (result_number->mantiss[SIZE_RESULT - 1] == 0)
        shift_mantiss_null_after_act(result_number->mantiss, &result_number->start, &material_number.exp);

    result_number->start--;
    
    if (result_number->mantiss[SIZE_MANTISS - 1] >= 5)
    {
        result_number->mantiss[SIZE_MANTISS - 1] = 0;
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

    for (int i = 0; i < SIZE_MANTISS; i++)
        if (result_number->mantiss[i] > 0)
            result_number->start = 30;

    if (result_number->exp > 99999)
        ERROR_RESULT_EXP;

    return EXIT_SUCCESS;
}
