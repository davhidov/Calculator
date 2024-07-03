#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ctype.h"
#include "polish_to_rez.h"

typedef struct Graf {
  double *y;
  double *x;
  int num_of_point;
  double rez;
  double start, end;
} Graf;

int test_str(char *equation);

char *input(char *str);
void check_mod(char *str, int k);
void check_sin(char *str, int k);
void check_asin(char *str, int k);
void check_cos(char *str, int k);
void check_acos(char *str, int k);
void check_tg(char *str, int k);
void check_atg(char *str, int k);
void check_ctg(char *str, int k);
void check_ln(char *str, int k);
void check_log(char *str, int k);
void check_sqrt(char *str, int k);
char *squeeze(char *str, char c);
int draw(char *equation, Graf *, int, double, int);
char *addBracets(char *s);
#endif  // SRC_INPUT_H_
