#ifndef STRUCT_H
#define STRUCT_H

#include "defines.h"

typedef struct keys_t
{
    int age;
    int index;
} keys_t;

typedef struct house_t
{
    char street[MAX_SIZE_STREET];
    int number_house;
    int number_flat;
} house_t;

typedef struct dorm_t
{
    int number_dorm;
    int number_room;
} dorm_t;

typedef union choose_type_t
{
    house_t house;
    dorm_t dorm;
} choose_type_t;

typedef struct describtion_t
{
    char type_house[MAX_SIZE_TYPE_HOUSE];
    char surname[MAX_SIZE_SURNAME];
    char name[MAX_SIZE_NAME];
    int group;
    char gender[MAX_SIZE_GENDER];
    int age;
    double arithmetic_mean;
    char entry_day[MAX_SIZE_ENTRY_DAY];
    choose_type_t home;
} describtion_t;

#endif
