#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#include "read.h"

#define ERROR_COMPILING_REG     { printf("ERROR_COMPILING_REG\n");      return 1; }
#define ERROR_READ_NUMBER       { printf("ERROR_READ_NUMBER\n");        return 2; }
#define ERROR_TOO_LONG          { printf("ERROR_TOO_LONG");             return 3; }
#define ERROR_FORMAT_NUMBER     { printf("ERROR_FORMAT_NUMBER\n");      return 4; }

int read_number(char *number, char *regular_expression, int len)
{
    regex_t regex;
    int code_return;
    
    code_return = regcomp(&regex, regular_expression, REG_EXTENDED); 

    if (code_return)
        ERROR_COMPILING_REG;

    if (fgets(number, len, stdin) == NULL)
        ERROR_READ_NUMBER;

    if ((number[strlen(number) - 1]) != '\n')
        ERROR_TOO_LONG;

    number[strlen(number) - 1] = '\0';
    
    code_return = regexec(&regex, number, 0, NULL, 0);

    if (code_return)
        ERROR_FORMAT_NUMBER;
        
    return EXIT_SUCCESS;
}
