#include "input.h"
// flag - 0 -> one - 1 -> graf ->
// test - 0 ->true - 1 ->false
int draw(char *equation, Graf *graf, int flag, double xx, int test) {
  int len_c = strlen(equation);
  equation = PreobToUnarMinus(equation, len_c, test);
  equation = input(equation);
  int er = test_str(equation);
  if (er == 1) {
    printf("Incorrect input. Try again.");
    printf("\n%s\n", equation);
    free(equation);
    return 1;
  }
  equation = addBracets(equation);
  printf("after - %s\n", equation);
  len_c = strlen(equation);
  struct stack *stk;
  stk = (struct stack *)malloc(sizeof(struct stack));
  init(stk);
  char *polish = (char *)calloc(len_c * 2, sizeof(char));
  ToPolish(equation, polish, stk, len_c);
  free(stk);
  free(equation);
  struct stack_double *stk_d;
  stk_d = (struct stack_double *)malloc(sizeof(struct stack_double));
  init_double(stk_d);
  int len = strlen(polish);
  printf("polish - %s\n", polish);

  if (flag == 1) {
    double x_start = graf->start, x_end = graf->end;
    graf->y = (double *)calloc(graf->num_of_point + 1, sizeof(double));
    graf->x = (double *)calloc(graf->num_of_point + 1, sizeof(double));
    int j = 0;
    double step = (x_end - x_start) / graf->num_of_point;
    printf("%f %f %f\n", x_start, x_end, step);
    for (double i = x_start; i <= x_end || j <= graf->num_of_point;
         i += step, j++) {
      graf->y[j] = ToRezalt(stk_d, polish, &len, &i);
      graf->x[j] = i;
    }
  } else {
    double yy = ToRezalt(stk_d, polish, &len, &xx);
    graf->rez = yy;
    printf("rez - %f\n", yy);
  }
  free(stk_d);
  free(polish);
  return 0;
}

char *input(char *str) {
  int k = strlen(str);
  check_mod(str, k);        // m
  check_acos(str, k);       // r
  check_asin(str, k);       // u
  check_atg(str, k);        // a
  check_sin(str, k);        // s
  check_cos(str, k);        // c
  check_ctg(str, k);        // g
  check_tg(str, k);         // t
  check_ln(str, k);         // l
  check_log(str, k);        // o
  check_sqrt(str, k);       // q
  str = squeeze(str, ' ');  // scgtloruaqmx
  return str;
}

char *squeeze(char *s, char c) {
  int len = 0, skip = 0;
  for (size_t i = 0; i < strlen(s); i++)
    if (s[i] == c) len++;
  char *rez = (char *)calloc(strlen(s) - len + 1, sizeof(char));
  for (size_t i = 0; i < strlen(s); i++) {
    if (s[i] == c)
      skip++;
    else
      rez[i - skip] = s[i];
  }
  rez[strlen(s) - len] = '\0';
  free(s);
  return rez;
}

void check_mod(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'm') {
      if ((str[i + 1] == 'o') && (str[i + 2] == 'd')) {
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    }
  }
}

void check_atg(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'a') {
      if ((str[i + 1] == 't') && (str[i + 2] == 'a') && (str[i + 3] == 'n')) {
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      }
    }
  }
}

void check_asin(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'a') {
      if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n') {
        str[i] = 'u';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      }
    }
  }
}

void check_acos(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'a') {
      if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's') {
        str[i] = 'r';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      }
    }
  }
}

void check_log(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'l') {
      if ((str[i + 1] == 'o') && (str[i + 2] == 'g')) {
        str[i] = 'o';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    }
  }
}

void check_sin(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 's') {
      if ((str[i + 1] == 'i') && (str[i + 2] == 'n')) {
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    }
  }
}

void check_cos(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'c') {
      if ((str[i + 1] == 'o') && (str[i + 2] == 's')) {
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    }
  }
}

void check_tg(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 't') {
      if ((str[i + 1] == 'a') && (str[i + 2] == 'n')) {
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    }
  }
}

void check_ctg(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'c') {
      if ((str[i + 1] == 't') && (str[i + 2] == 'g')) {
        str[i] = 'g';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
      }
    }
  }
}
void check_ln(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 'l') {
      if (str[i + 1] == 'n') {
        str[i + 1] = ' ';
      }
    }
  }
}
void check_sqrt(char *str, int k) {
  for (int i = 0; i < k; i++) {
    if (str[i] == 's') {
      if ((str[i + 1] == 'q') && (str[i + 2] == 'r') && (str[i + 3] == 't')) {
        str[i] = 'q';
        str[i + 1] = ' ';
        str[i + 2] = ' ';
        str[i + 3] = ' ';
      }
    }
  }
}
