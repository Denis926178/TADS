#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

#include "options.h"

void header_keys();
void footer_keys();
void print_record_key(keys_t key);
int print_keys(keys_t *array, int counter);
void print_result(int64_t start, int64_t end);
int print_table_in_keys(describtion_t *array, int counter);
void print_one_record(describtion_t array, int i);
int print_table(describtion_t *array, int counter);
void print_header();
void print_footer();
void print_options();
int print_in_keys(describtion_t *array, keys_t *keys, int counter);

#endif
