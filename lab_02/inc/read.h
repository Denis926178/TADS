#ifndef READ_H
#define READ_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

#include "defines.h"
#include "struct.h"

int read_one_record(describtion_t *array, FILE *f_in, int flag);
int select_mode(int *mode);
int valid_date(char *date);

#endif
