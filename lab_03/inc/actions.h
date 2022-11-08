#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "structs.h"

uint64_t tick_count(void);
void multiplicate_matrix(str_matrix_t str, matrix_full_t mtr, str_matrix_t *res, clock_t *res_time);
void multiplicate_sparse(sparse_matrix_t str, sparse_matrix_t mtr, sparse_matrix_t *res_sparse, clock_t *res_time);

#endif
