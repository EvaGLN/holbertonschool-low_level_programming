#ifndef CALC_H
#define CALC_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);

int op_add(int a, int b);

int op_sub(int a, int b);

int op_mul(int a, int b);

int op_div(int a, int b);

int op_mod(int a, int b);

int (*get_op_func(char *s))(int, int);

#endif
