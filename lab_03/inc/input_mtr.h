#ifndef INPUT_MTR_H
#define INPUT_MTR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structs.h"

#define MAX_STR 5000
#define MAX_COL 5000

#define ERROR_KEY 1
#define ERROR_READ 2
#define ERROR_PARAM 3
#define ERROR_MEMORY 4
#define ERROR_ELEMENT 5

#define EPSI 1e-6

int read_param(matrix_full_t *mtr);
int input_non_zero(matrix_full_t *mtr);
int read_matrix(matrix_full_t *mtr);
int **allocate_matrix(int n, int m);
void print_matrix(matrix_full_t mtr);
void create_arrays(matrix_full_t mtr, sparse_matrix_t *mtr_spr);
int create_sparse_matrix_t(matrix_full_t mtr, sparse_matrix_t *mtr_spr);
int create_rand_matrix(matrix_full_t *mtr_rand);
void free_matrix(int **MTR);


#endif