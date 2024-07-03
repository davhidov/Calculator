#ifndef SRC_POLISH_TO_REZ_H_
#define SRC_POLISH_TO_REZ_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "polish.h"
#include "stack.h"

void plus(struct stack_double *stk, double *a, double *b);
void minus(struct stack_double *stk, double *a, double *b);
void umn(struct stack_double *stk, double *a, double *b);
void del(struct stack_double *stk, double *a, double *b);
void mod(struct stack_double *stk, double *a, double *b);
void pow_s(struct stack_double *stk, double *a, double *b);

void sin_s(struct stack_double *stk, double *a);
void asin_s(struct stack_double *stk, double *a);
void cos_s(struct stack_double *stk, double *a);
void acos_s(struct stack_double *stk, double *a);
void tan_s(struct stack_double *stk, double *a);
void atan_s(struct stack_double *stk, double *a);
void ctg_s(struct stack_double *stk, double *a);
void sqrt_s(struct stack_double *stk, double *a);
void ln_s(struct stack_double *stk, double *a);
void log_s(struct stack_double *stk, double *a);
void un_min(struct stack_double *stk, double *a);

void ToDouble(struct stack_double *stk, char polish, char *num, int *j);
double ToRezalt(struct stack_double *stk, char *polish, const int *len,
                double *x);

#endif  // SRC_POLISH_TO_REZ_H_
