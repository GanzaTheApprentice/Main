#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nums {
  double data;
  struct Nums *next;
} Nums;

typedef struct Syms {
  char data;
  struct Syms *next;
} Syms;

void nPush(Nums **list, double x);
void sPush(Syms **list, char x);
double nPop(Nums **list);
char sPop(Syms **list);
bool isRB(char x);
bool isLB(char x);
bool isSym(char x);
bool isNum(char x);
double toDoubleX(char *ins, int sign);
double toDouble(char *ins, int *i, int sign);
char toFunc(char *ins, int *i, int sign);
int isFunc(char x);
int isOper(char x);
void counts(Nums **nlist, Syms **slist);
int tier(char x);
int getSign(char *ins, int *i);
int errors(char *ins, char *x);
char *calc(char *ins, char *x);

#endif  // SRC_SMARTCALC_H_
