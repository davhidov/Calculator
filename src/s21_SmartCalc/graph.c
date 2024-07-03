
#include "input.h"

char* addBracets(char* str) {
  int len = strlen(str);
  char* s = (char*)calloc(len + 4, sizeof(char));
  s[0] = '(';
  int skip = 1;
  for (int i = 0; i <= len; i++) {
    if (str[i] == '\n') {
      skip++;
      continue;
    }
    s[i + skip] = str[i];
  }
  free(str);
  len = strlen(s);
  s[len + 0] = ')';
  s[len + 1] = '\n';
  s[len + 2] = '\0';
  return s;
}

int test_str(char* expression) {
  int er = 0;
  const int MAX_LENGTH = 255;
  const char valid_operators[] = "+^-*/~sctgqloruam\%()x";
  int len = strlen(expression);
  if (len > MAX_LENGTH) printf("here 1\n"), er = 1;
  struct stack brackets_stack;
  init(&brackets_stack);

  if (strchr("+^-*/m%).", expression[0]) != NULL)
    printf("here 2 - %c\n", expression[0]), er = 1;
  if (strchr("+^-*/m%", expression[len - 1]) != NULL)
    printf("here 4\n"), er = 1;
  if (expression[len - 1] == '(') printf("here 5\n"), er = 1;

  for (int i = 0; i < len - 1; i++) {
    if (strchr("+-*/%^~.m", expression[i]) != NULL &&
        strchr(").+m-*/%^~", expression[i + 1]) != NULL)
      printf("here 6\n"), er = 1;
    if (expression[i] == '(' && strchr("+-*/%^m.)", expression[i + 1]) != NULL)
      printf("here 7\n"), er = 1;
    if (strchr("0123456789.sctgqloruax)", expression[i]) != NULL &&
        strchr("sctgqlorua", expression[i + 1]) != NULL)
      printf("here 8\n"), er = 1;
    if (strchr("0123456789.)", expression[i]) != NULL &&
        strchr("(sctgqlorua", expression[i + 1]) != NULL)
      printf("here 8\n"), er = 1;
    if (strchr("sctgqlorua", expression[i]) != NULL && expression[i + 1] != '(')
      printf("here 6\n"), er = 1;
    if (expression[i] == 'x' &&
        (expression[i + 1] == '.' || expression[i + 1] == '('))
      printf("here x\n"), er = 1;
  }
  for (int i = 0; i < len; i++) {
    if (expression[i] == ')' &&
        (strchr("(0123456789.sctgqlorua", expression[i + 1]) != NULL &&
         expression[i + 1] != '\0'))
      printf("here 9.1 simbol - %c\n", expression[i + 1]), er = 1;
    if (expression[i] == '(') push(&brackets_stack, '(');
    if (expression[i] == ')') {
      if (brackets_stack.top == 0 ||
          brackets_stack.elem[brackets_stack.top - 1] != '(')
        printf("here 9\n"), er = 1;
      else
        pop(&brackets_stack);
    }
  }
  if (brackets_stack.top != 0) printf("here 10\n"), er = 1;
  for (int i = 0; i < len; i++) {
    if (strchr(valid_operators, expression[i]) == NULL &&
        !isdigit(expression[i]) && expression[i] != '.' &&
        expression[i] != '\n') {
      printf("here 11\n"), er = 1;
    }
  }

  return er;
}
