#ifndef S21_CREDIT_CALC_H_
#define S21_CREDIT_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CreditInfo {
  double monthlyPayment[2];
  double overpayment;
  double totalDebt;
} CreditInfo;

CreditInfo resultDif(int, double, double);
CreditInfo resultAn(int, double, double);

#endif  // S21_CREDIT_CALC_H_
