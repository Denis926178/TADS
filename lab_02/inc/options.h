#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdlib.h>

#include "defines.h"
#include "struct.h"
#include "read.h"

int make_table(describtion_t *array, int *counter);
int add_record(describtion_t *array, int *counter);
int delete_record(describtion_t *array, int *counter);
int compare_year(char *date, int input_year);

#endif
