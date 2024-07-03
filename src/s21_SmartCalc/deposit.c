#include "deposit.h"

resInfo res(unit *addRef, unit *addWith, int reffCount, int withCount,
            time_t startData, time_t endData, double rate, double money,
            int cap, double tax, int frequncy) {
  bnk rez;
  time_t buff = 0;
  int timeDiff = 0;
  rate = rate / 100;
  tax = tax / 100;
  double diff = 0, dailyRate = 0;
  const int daysec = 60 * 60 * 24;
  struct tm *cur = localtime(&startData), *tem = localtime(&startData);
  struct tm DataPayment = *cur;
  rez.date = *tem, rez.dep = money, rez.dif = money, rez.per_ad = 0;
  char s[20] = {0}, s1[20] = {0};
  resInfo output;
  output.gained = 0, output.deposit = 0, output.taxes = 0;
  switch (frequncy) {
    case 1:
      DataPayment.tm_mon += 1;
      break;
    case 3:
      DataPayment.tm_mon += 3;
      break;
    case 6:
      DataPayment.tm_mon += 6;
      break;
    case 12:
      DataPayment.tm_year += 1;
      break;
    case 100:
      DataPayment.tm_mday++;
      break;
  }
  while (mktime(cur) < endData) {
    for (int i = 0; i < reffCount; i++) {
      if (mktime(&addRef[i].date) == mktime(cur))
        diff += addRef[i].amount, addRef[i].date.tm_mon += addRef[i].freq;
    }
    for (int i = 0; i < withCount; i++) {
      if (mktime(&addWith[i].date) == mktime(cur))
        diff += addWith[i].amount, addWith[i].date.tm_mon += addWith[i].freq;
    }
    if (rez.dep + diff < 0) diff = 0;
    if (cur->tm_year % 4 == 0 && cur->tm_year % 1000 != 0)
      dailyRate = rate / 366;
    else
      dailyRate = rate / 365;
    if (!reffCount && !withCount && frequncy != 100) {
      switch (frequncy) {
        case 1:
          cur->tm_mon += 1;
          break;
        case 3:
          cur->tm_mon += 3;
          break;
        case 6:
          cur->tm_mon += 6;
          break;
        case 12:
          cur->tm_year += 1;
          break;
      }
    } else
      cur->tm_mday++;
    buff = mktime(cur);
    cur = localtime(&buff);
    if (mktime(cur) == mktime(&DataPayment)) {
      timeDiff = (buff - mktime(&rez.date)) / daysec;
      rez.date = DataPayment;
      if (cap)
        rez.per_ad = rez.dep * (double)timeDiff * dailyRate,
        rez.dif = rez.per_ad + diff, rez.dep = rez.dep + rez.dif;
      else
        rez.per_ad = rez.dep * (double)timeDiff * dailyRate, rez.dif = diff,
        rez.dep = rez.dep + rez.dif;
      output.gained += rez.per_ad;
      switch (frequncy) {
        case 1:
          DataPayment.tm_mon += 1;
          break;
        case 3:
          DataPayment.tm_mon += 3;
          break;
        case 6:
          DataPayment.tm_mon += 6;
          break;
        case 12:
          DataPayment.tm_year += 1;
          break;
        case 100:
          DataPayment.tm_mday++;
          break;
      }
      diff = 0;
      strftime(s, 20, "%d.%m.%Y", cur);
      strftime(s1, 20, "%d.%m.%Y", cur);
    }
  }
  output.taxes = output.gained * tax;
  output.date = mktime(&rez.date), output.deposit = rez.dep;
  if (!output.taxes) output.taxes = output.gained * tax;
  return output;
}
