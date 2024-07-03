#include "credit.h"

CreditInfo resultDif(int duration, double rate, double money) {
  rate = rate / 100 / 12;
  CreditInfo res;
  double startMoney = money, buff = 0, min = money, max = 0, debt = 0;
  for (int i = 0; i < duration; i++) {
    buff = money * rate + startMoney / duration;
    money = money - startMoney / duration;
    if (buff > max) max = buff;
    if (buff < min) min = buff;
    debt += buff;
  }
  res.monthlyPayment[0] = min;
  res.monthlyPayment[1] = max;
  res.overpayment = debt - startMoney;
  res.totalDebt = debt;
  return res;
}
CreditInfo resultAn(int duration, double rate, double money) {
  rate = rate / 100 / 12;
  CreditInfo res;
  double monthly_payment = money * (rate * pow(1 + rate, duration)) /
                           (pow(1 + rate, duration) - 1),
         debt = monthly_payment * duration;

  res.monthlyPayment[0] = monthly_payment;
  res.monthlyPayment[1] = 0;
  res.overpayment = debt - money;
  res.totalDebt = debt;
  return res;
}
