#include <stdio.h>

#include <stdlib.h>

struct _retire_info {

  int months;

  double contribution;

  double rate_of_return;

};

typedef struct _retire_info retire_info;

int calculator (int startAge, double initial, retire_info status) {

  int month = status.months;

  int currentAge = startAge;

  double balance = initial;

  for (int i = 1; i <= month; i++) {

    int years = currentAge / 12;

    int mon = currentAge % 12;

    double interest = balance * status.rate_of_return;

    balance = balance + interest + status.contribution;

    printf("Age %3d month %2d you have %.2f\n", years, mon, balance);

    currentAge++;

  }

  return balance;

}

void retirement (int startAge, double initial, retire_info working, retire_info retired) {

  printf("Age %3d month %2d you have %.2f\n", startAge / 12, startAge % 12, initial);

  double finalBalance = calculator(328, 21345, working);

  calculator(816, finalBalance, retired);

}

int main (void) {

  retire_info working;

  working.months = 489;

  working.contribution = 1000;

  working.rate_of_return = 0.045/12;

  retire_info retired;

  retired.months = 384;

  retired.contribution = (-4000);

  retired.rate_of_return = 0.01/(double)12;

  retirement (327, 21345, working, retired);

  return 0;

}
