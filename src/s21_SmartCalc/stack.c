#include "stack.h"

void init(struct stack *stk) { stk->top = 0; }

void init_double(struct stack_double *stk) { stk->top = 0; }

void push(struct stack *stk, char f) {
  if (stk->top < NMAX) {
    stk->elem[stk->top] = f;
    stk->top++;
  } else {
    printf("Stack is full. Count of elements: %c !\n", stk->top);
  }
}

char pop(struct stack *stk) {
  if ((stk->top) > 0) {
    stk->top--;
    return stk->elem[stk->top];
  } else {
    printf("Stack is empty!\n");
    return '|';
  }
}

void push_double(struct stack_double *stk, double f) {
  if (stk->top < NMAX) {
    stk->elem[stk->top] = f;
    stk->top++;
  } else {
    printf("Stack is full. Count of elements: %d !\n", stk->top);
  }
}

double pop_double(struct stack_double *stk) {
  if ((stk->top) > 0) {
    stk->top--;
    return stk->elem[stk->top];
  } else {
    printf("Stack is empty!\n");
    return '|';
  }
}
