#ifndef STRUCTS_H
#define STRUCTS_H 

#include <stdlib.h>
#include <stdio.h>

typedef struct sparse_matrix_t
{
    int str;
    int col;
    int n_zero;
    
    int *A;
    int *IA;
    int *JA;
} sparse_matrix_t;

typedef struct matrix_full_t
{
    int **mtr;
    int n;
    int m;
    int n_zero;
} matrix_full_t;

typedef struct str_matrix_t
{
    int *mtr;
    int n;
    int n_zero;
} str_matrix_t;

int *allocate_arr(int n_zero);
int **allocate_matrix(int n, int m);
void free_matrix(int **mtr);
void free_arr(int *arr);
void print_matrix(matrix_full_t mtr);
void print_arr(int *arr, int n);
void print_str(str_matrix_t str_mtr);


#endif
