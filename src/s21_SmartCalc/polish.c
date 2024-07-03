#include "polish.h"

int push_simbol(struct stack* stk, char equation, char* polish, int j) {
  if (stk->top == 0) {
    push(stk, equation);
    return j;
  }
  MinusPlus(stk, &equation, polish, &j);
  UmnDel(stk, &equation, polish, &j);
  UnarMinus(stk, &equation, polish, &j);
  Funks(stk, &equation, polish, &j);
  Stepen(stk, &equation, polish, &j);
  if (equation == '\n') {
    while (stk->top != 0) {
      polish[j] = pop(stk);
      if (polish[j] == '|') break;
      j++;
    }
  }
  if (equation == '(') push(stk, equation);
  if (equation == ')') {
    while (stk->elem[stk->top - 1] != '(') {
      polish[j] = pop(stk);
      if (polish[j] == '|') break;
      j++;
    }
    pop(stk);
  }
  return j;
}

void ToPolish(char* equation, char* polish, struct stack* stk, int len) {
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (strchr("/^*-+()~lsctgqoruaxm\%", equation[i]) != NULL ||
        equation[i] == '\n') {
      if (equation[i] == 'x') {
        polish[j] = equation[i];
        j++;
        continue;
      }
      j = push_simbol(stk, equation[i], polish, j);
    } else {
      polish[j] = equation[i];
      j++;
      if (strchr("/^*-+()xm\%", equation[i + 1]) != NULL ||
          equation[i] == '\n') {
        polish[j] = '|';
        j++;
      }
    }
  }
  polish[j] = '\n';
}

char* PreobToUnarMinus(char* str, int len, int flag) {
  char* equation = (char*)calloc(strlen(str) + 1, sizeof(char));
  for (int i = 0; i < (int)strlen(str); i++) equation[i] = str[i];
  equation[strlen(str)] = '\0';
  if (flag) free(str);
  if (equation[0] == '-') equation[0] = '~';
  if (equation[0] == '+') equation[0] = ' ';
  for (int i = 1; i < len - 1; i++) {
    if (equation[i] == '(' && equation[i + 1] == '-') equation[i + 1] = '~';
    if (equation[i] == '(' && equation[i + 1] == '+') equation[i + 1] = ' ';
  }
  return equation;
}
void MinusPlus(struct stack* stk, char* equation, char* polish, int* j) {
  if (*equation == '-' || *equation == '+') {
    while (strchr("+^-*/~sctgqloruam\%", stk->elem[stk->top - 1]) != NULL) {
      polish[*j] = pop(stk);
      (*j)++;
    }
    push(stk, *equation);
  }
}
void UmnDel(struct stack* stk, char* equation, char* polish, int* j) {
  if (*equation == '*' || *equation == '/' || *equation == '\%' ||
      *equation == 'm') {
    while (strchr("^*/~sctgqloruam\%", stk->elem[stk->top - 1]) != NULL) {
      polish[*j] = pop(stk);
      (*j)++;
    }
    push(stk, *equation);
  }
}
void UnarMinus(struct stack* stk, char* equation, char* polish, int* j) {
  if (*equation == '~') {
    while (strchr("^~sctgqlorua", stk->elem[stk->top - 1]) != NULL) {
      polish[*j] = pop(stk);
      (*j)++;
    }
    push(stk, *equation);
  }
}
void Funks(struct stack* stk, char* equation, char* polish, int* j) {
  if (strchr("sctgqlorua", *equation) != NULL) {
    while (strchr("sctgqlorua", stk->elem[stk->top - 1]) != NULL) {
      polish[*j] = pop(stk);
      (*j)++;
    }
    push(stk, *equation);
  }
}
void Stepen(struct stack* stk, char* equation, char* polish, int* j) {
  if (*equation == '^') {
    while (strchr("^sctgqlorua", stk->elem[stk->top - 1]) != NULL) {
      polish[*j] = pop(stk);
      (*j)++;
    }
    push(stk, *equation);
  }
}
