#ifndef STRUCTS_H
#define STRUCTS_H

#define SIZE_MANTISS    30
#define SIZE_INT        30
#define SIZE_RESULT     60

typedef struct material_t
{
    int mantissa_sign;
    int mantiss[SIZE_MANTISS];
    int exp_sign;
    int exp;
    int start;
} material_t;
 
typedef struct res_t
{
    int mantissa_sign;
    int mantiss[SIZE_RESULT];
    int exp_sign;
    int exp;
    int start;
} res_t;
 
typedef struct whole_t
{
    int sign;
    int digits[SIZE_INT];
    int start;
} whole_t;

#endif
