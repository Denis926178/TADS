#ifndef INPUT_STR_H
#define INPUT_STR_H


#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR_PARAM 3
#define ERROR_MEMORY 4
#define ERROR_ELEMENT 5

int read_param_str(str_matrix_t *str_mtr);
int read_element_str(str_matrix_t *str_mtr);
int create_sparse_string(str_matrix_t str, sparse_matrix_t *str_spr);
int create_rand_str(str_matrix_t *str_mtr);
void print_str(str_matrix_t str_mtr);

#endif