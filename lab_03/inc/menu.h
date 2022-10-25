#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "structs.h"
#include "input_mtr.h"
#include "input_str.h"
#include "actions.h"

#define ERROR_MULTI 6

void print_rules(void);
void print_menu(void);
int do_actions(int key, matrix_full_t *mtr, sparse_matrix_t *mtr_spr, 
str_matrix_t *str, sparse_matrix_t *str_spr,
str_matrix_t *res, sparse_matrix_t *res_spr, int *flag_matrix, int *flag_str, 
int *flag_mult, int *flag_mult_spr, clock_t *res_time, clock_t *res_time_spr, int flag_compare);
#endif