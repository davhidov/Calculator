#ifndef S21_DEPOSIT_CALC_H_
#define S21_DEPOSIT_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct unit {
  struct tm date;
  double amount;
  int freq;
} unit;

typedef struct bank_info {
  struct tm date;
  double dep;
  double dif;
  double per_ad;
  double taxes;
} bnk;

typedef struct result {
  time_t date;
  double gained;
  double taxes;
  double deposit;
} resInfo;

resInfo res(unit*, unit*, int, int, time_t, time_t, double, double, int, double,
            int);

#endif  // S21_DEPOSIT_CALC_H_