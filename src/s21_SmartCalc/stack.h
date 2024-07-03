#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 257
struct stack {
  char elem[NMAX];
  int top;
};

struct stack_double {
  double elem[NMAX];
  int top;
};

void init(struct stack *stk);
void push(struct stack *stk, char f);
char pop(struct stack *stk);

void init_double(struct stack_double *stk);
void push_double(struct stack_double *stk, double f);
double pop_double(struct stack_double *stk);

#endif  // SRC_STACK_H_
