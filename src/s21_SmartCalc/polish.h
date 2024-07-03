#ifndef SRC_POLISH_H_
#define SRC_POLISH_H_
#include "stack.h"

int push_simbol(struct stack* stk, char elem, char* str, int i);
char* PreobToUnarMinus(char* equation, int len, int);
void ToPolish(char* equation, char* polish, struct stack* stk, int len);
void MinusPlus(struct stack* stk, char* equation, char* polish, int* j);
void UmnDel(struct stack* stk, char* equation, char* polish, int* j);
void UnarMinus(struct stack* stk, char* equation, char* polish, int* j);
void Funks(struct stack* stk, char* equation, char* polish, int* j);
void Stepen(struct stack* stk, char* equation, char* polish, int* j);

#endif  // SRC_POLISH_H_
