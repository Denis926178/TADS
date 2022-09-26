#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "read.h"
#include "parser.h"
#include "multiply.h"
#include "print_number.h"

#define MAX_LEN_INT     33
#define MAX_LEN_DOUBLE  41

material_t material_number = {1, { 0 }, 1, 0, 0};
whole_t integer_number = {1, { 0 }, 0};
result_t result_number = {1, { 0 }, 1, 0, SIZE_MANTISS};

int main(void)
{
    char *float_regular = "^[+-]?([0-9]+([.][0-9]*)?([eE][+-]?[0-9]+)?|[.][0-9]+([eE][+-]?[0-9]+)?)$";
    char *int_regular = "^[+-]?[0-9]+$";

    char number_int[MAX_LEN_INT];
    char number_double[MAX_LEN_DOUBLE];
    int code_return;

    if ((code_return = read_number(number_int, int_regular, MAX_LEN_INT)))
        return code_return;

    if ((code_return = read_number(number_double, float_regular, MAX_LEN_DOUBLE)))
        return code_return;

    code_return = parser_to_structure(number_double, number_int, &material_number, &integer_number);
    
    if (code_return)
        return code_return;

    code_return = multiply(material_number, integer_number, &result_number);

    if (code_return)
        return code_return;

    print_number(result_number);

    return EXIT_SUCCESS;
}
