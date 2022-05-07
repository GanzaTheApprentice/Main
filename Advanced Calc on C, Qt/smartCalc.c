#include "smartCalc.h"

int errors(char *ins, char *x) {
  int flag = 0, fun = 0, lB = 0, oper = 0, num = 0, rB = 0;

  if (x[0] != '\0') {
    for (int i = 0; x[i] != '\0' && !flag; i++) {
      if (!i && (x[i] == '-' || x[i] == '+')) {
      } else if (x[i] == '.' && !fun) {
        fun = 1;
      } else if (isNum(x[i])) {
      } else {
        flag = 1;
      }
    }
    fun = 0;
  }

  for (int i = 0; ins[i] != '\0' && !flag; i++) {
    if (ins[i] == '(') {
      lB++;
    } else if (ins[i] == ')' && lB <= 0) {
      flag = 1;
    } else if (ins[i] == ')' && lB > 0) {
      lB--;
    }
  }

  if (lB) {
    flag = 1;
  }

  for (int i = 0; ins[i] != '\0' && !flag; i++) {
    int sign;
    sign = getSign(ins, &i);
    if (ins[i] == 'x' && !num) {
      num = 1;
      oper = 0;
    } else if (isSym(ins[i]) || isRB(ins[i])) {
      char s = toFunc(ins, &i, sign);
      if (isFunc(s) && !num && !oper && !lB && !rB) {
        fun = 1;
      } else if (isFunc(s) && !fun && !num && !rB) {
        fun = 1;
      } else if (isOper(s) && !oper && num && ins[i + 1] != '\0') {
        oper = 1;
        rB = 0;
        num = 0;
      } else if ((isLB(s) && oper) || (isLB(s) && fun)) {
        lB = 1;
        rB = 0;
        fun = 0;
      } else if (isLB(s) && !num && !oper && !rB) {
        lB = 1;
      } else if (isRB(s) && num) {
        rB = 1;
        lB = 0;
      } else {
        flag = 1;
      }
    } else if (isNum(ins[i])) {
      if (toDouble(ins, &i, sign) != NAN && !num) {
        num = 1;
        oper = 0;
      } else {
        flag = 1;
      }
    } else if (ins[i] == ' ') {
    } else {
      flag = 1;
    }
  }

  return flag;
}

char *calc(char *ins, char *x) {
  static char res[333];
  if (!errors(ins, x)) {
    Nums *listNums = NULL;
    Syms *listSyms = NULL;

    for (int i = 0; ins[i] != '\0'; i++) {
      int sign = getSign(ins, &i);
      if (isNum(ins[i])) {
        nPush(&listNums, toDouble(ins, &i, sign));
      } else if (ins[i] == 'x') {
        nPush(&listNums, toDoubleX(x, sign));
      } else if (isSym(ins[i]) && listSyms == NULL) {
        sPush(&listSyms, toFunc(ins, &i, sign));
      } else if (ins[i] == '^' || ins[i] == '(') {
        sPush(&listSyms, toFunc(ins, &i, sign));
      } else if (isSym(ins[i]) && tier(ins[i]) > tier(listSyms->data)) {
        sPush(&listSyms, toFunc(ins, &i, sign));
      } else if (isSym(ins[i]) && tier(ins[i]) <= tier(listSyms->data)) {
        while (listSyms != NULL && tier(ins[i]) <= tier(listSyms->data)) {
          counts(&listNums, &listSyms);
        }
        sPush(&listSyms, toFunc(ins, &i, sign));
      } else if (isRB(ins[i])) {
        if (listSyms->data == '(') {
          sPop(&listSyms);
          if (listSyms != NULL && isFunc(listSyms->data)) {
            counts(&listNums, &listSyms);
          }
        } else {
          while (listSyms->data != '(') {
            counts(&listNums, &listSyms);
          }
          sPop(&listSyms);
        }
      }
    }
    while (listSyms != NULL) {
      counts(&listNums, &listSyms);
    }
    snprintf(res, sizeof(res), "%.8lf", nPop(&listNums));
  } else {
    const char err[] = {"incorrect input"};
    for (int i = 0; i < 15; i++) {
      res[i] = err[i];
    }
    res[15] = '\0';
  }
  return res;
}

int isFunc(char x) {
  int flag = 0;
  const char ins[] = {"cstalqwerydfghzxvbn"};
  for (int i = 0; ins[i] != '\0'; i++) {
    if (x == ins[i]) flag = 1;
  }
  return flag;
}

int isOper(char x) {
  int flag = 0;
  const char ins[] = {"+-*/%^"};
  for (int i = 0; ins[i] != '\0'; i++) {
    if (x == ins[i]) flag = 1;
  }
  return flag;
}

int getSign(char *ins, int *i) {
  int sign = 0;
  if (ins[*i] == '-' && isSym(ins[*i - 1])) {
    sign = 1;
    *i += 1;
  } else if (ins[*i] == '-' && !ins[*i - 1]) {
    sign = 1;
    *i += 1;
  }
  if (ins[*i] == '+' && isSym(ins[*i - 1])) {
    *i += 1;
  } else if (ins[*i] == '+' && !ins[*i - 1]) {
    *i += 1;
  }
  return sign;
}

int tier(char x) {
  int tier = 0;
  switch (x) {
    case '+':
    case '-':
      tier = 1;
      break;
    case '*':
    case '/':
    case '%':
      tier = 2;
      break;
    case '^':
    case 'c':
    case 's':
    case 't':
    case 'a':
    case 'l':
    case 'q':
    case 'w':
    case 'e':
    case 'r':
    case 'y':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'z':
    case 'x':
    case 'v':
    case 'b':
    case 'n':
      tier = 3;
      break;
  }
  return tier;
}

char toFunc(char *ins, int *i, int sign) {
  char tmp = '0';
  int j = *i;
  switch (ins[*i]) {
    case ')':
      tmp = ')';
      break;
    case '(':
      tmp = '(';
      break;
    case '+':
      tmp = '+';
      break;
    case '-':
      tmp = '-';
      break;
    case '*':
      tmp = '*';
      break;
    case '/':
      tmp = '/';
      break;
    case '%':
      tmp = '%';
      break;
    case '^':
      tmp = '^';
      break;
    case 'c':
      if (ins[j + 1] == 'o' && ins[j + 2] == 's') {
        if (sign) {
          tmp = 'r';  // -cos
          *i += 2;
        } else {
          tmp = 'q';  // cos
          *i += 2;
        }
      }
      break;
    case 's':
      if (ins[j + 1] == 'i' && ins[j + 2] == 'n') {
        if (sign) {
          tmp = 't';  // -sin
          *i += 2;
        } else {
          tmp = 'w';  // sin
          *i += 2;
        }
      }
      if (ins[j + 1] == 'q' && ins[j + 2] == 'r' && ins[j + 3] == 't') {
        if (sign) {
          tmp = 'v';  // -sqrt
          *i += 3;
        } else {
          tmp = 'z';  // sqrt
          *i += 3;
        }
      }
      break;
    case 't':
      if (ins[j + 1] == 'a' && ins[j + 2] == 'n') {
        if (sign) {
          tmp = 'y';  // -tan
          *i += 2;
        } else {
          tmp = 'e';  // tan
          *i += 2;
        }
      }
      break;
    case 'a':
      if (ins[j + 1] == 'c' && ins[j + 2] == 'o' && ins[j + 3] == 's') {
        if (sign) {
          tmp = 'f';  // -acos
          *i += 3;
        } else {
          tmp = 'a';  // acos
          *i += 3;
        }
      }
      if (ins[j + 1] == 's' && ins[j + 2] == 'i' && ins[j + 3] == 'n') {
        if (sign) {
          tmp = 'g';  // -asin
          *i += 3;
        } else {
          tmp = 's';  // asin
          *i += 3;
        }
      }
      if (ins[j + 1] == 't' && ins[j + 2] == 'a' && ins[j + 3] == 'n') {
        if (sign) {
          tmp = 'h';  // -atan
          *i += 3;
        } else {
          tmp = 'd';  // atan
          *i += 3;
        }
      }
      break;
    case 'l':
      if (ins[j + 1] == 'n') {
        if (sign) {
          tmp = 'b';  // -ln
          *i += 1;
        } else {
          tmp = 'x';  // ln
          *i += 1;
        }
      }
      if (ins[j + 1] == 'o' && ins[j + 2] == 'g') {
        if (sign) {
          tmp = 'n';  // -log
          *i += 2;
        } else {
          tmp = 'c';  // log
          *i += 2;
        }
      }
      break;
  }
  return tmp;
}

double toDoubleX(char *ins, int sign) {
  double tmp = 0, flag = 0;
  int signX = 0, i = 0;
  if (ins[i] == '-') {
    i++;
    signX++;
  }
  while (isNum(ins[i]) || ins[i] == '.') {
    if (ins[i] == '.') {
      i++;
      flag = 1;
    }
    if (flag) flag *= 10;
    tmp += (ins[i] + '0' - 96);
    i++;
    if (isNum(ins[i]) || ins[i] == '.') {
      tmp *= 10;
    }
  }
  if (flag) tmp /= flag;
  if ((sign && !signX) || (!sign && signX)) {
    tmp *= -1;
  }
  return tmp;
}

double toDouble(char *ins, int *i, int sign) {
  double tmp = 0;
  double flag = 0;
  int j = *i;
  while (isNum(ins[j]) || ins[j] == '.') {
    if (ins[j] == '.' && !flag) {
      *i += 1;
      j += 1;
      flag = 1;
    } else if (ins[j] == '.' && flag) {
      tmp = NAN;
      break;
    }
    if (flag) flag *= 10;
    tmp += (ins[j] + '0' - 96);
    j += 1;
    if (isNum(ins[j]) || ins[j] == '.') {
      tmp *= 10;
      *i += 1;
    }
  }
  if (flag) tmp /= flag;
  if (sign) tmp *= -1;
  return tmp;
}

void counts(Nums **nlist, Syms **slist) {
  double res = 0, one = 0, two = 0;
  char oper = sPop(slist);

  switch (oper) {
    case '+':
      two = nPop(nlist);
      one = nPop(nlist);
      res = one + two;
      break;
    case '-':
      two = nPop(nlist);
      one = nPop(nlist);
      res = one - two;
      break;
    case '*':
      two = nPop(nlist);
      one = nPop(nlist);
      res = one * two;
      break;
    case '/':
      two = nPop(nlist);
      one = nPop(nlist);
      res = one / two;
      break;
    case '%':
      two = nPop(nlist);
      one = nPop(nlist);
      res = fmod(one, two);
      break;
    case '^':
      two = nPop(nlist);
      one = nPop(nlist);
      res = pow(one, two);
      break;
    case 'q':  // cos
      one = nPop(nlist);
      res = cos(one);
      break;
    case 'r':  // -cos
      one = nPop(nlist);
      res = cos(one);
      res *= -1;
      break;
    case 'w':  // sin
      one = nPop(nlist);
      res = sin(one);
      break;
    case 't':  // -sin
      one = nPop(nlist);
      res = sin(one);
      res *= -1;
      break;
    case 'e':  // tan
      one = nPop(nlist);
      res = tan(one);
      break;
    case 'y':  // -tan
      one = nPop(nlist);
      res = tan(one);
      res *= -1;
      break;
    case 'a':  // acos
      one = nPop(nlist);
      res = acos(one);
      break;
    case 'f':  // -acos
      one = nPop(nlist);
      res = acos(one);
      res *= -1;
      break;
    case 's':  // asin
      one = nPop(nlist);
      res = asin(one);
      break;
    case 'g':  // -asin
      one = nPop(nlist);
      res = asin(one);
      res *= -1;
      break;
    case 'd':  // atan
      one = nPop(nlist);
      res = atan(one);
      break;
    case 'h':  // -atan
      one = nPop(nlist);
      res = atan(one);
      res *= -1;
      break;
    case 'z':  // sqrt
      one = nPop(nlist);
      res = sqrt(one);
      break;
    case 'v':  // -sqrt
      one = nPop(nlist);
      res = sqrt(one);
      res *= -1;
      break;
    case 'x':  // ln
      one = nPop(nlist);
      res = log(one);
      break;
    case 'b':  // -ln
      one = nPop(nlist);
      res = log(one);
      res *= -1;
      break;
    case 'c':  // log
      one = nPop(nlist);
      res = log10(one);
      break;
    case 'n':  // -log
      one = nPop(nlist);
      res = log10(one);
      res *= -1;
      break;
  }
  nPush(nlist, res);
}

bool isRB(char x) { return (x == ')'); }
bool isLB(char x) { return (x == '('); }
bool isSym(char x) {
  return (x == '(' || x == '+' || x == '-' || x == '*' || x == '/' ||
          x == '^' || x == '%' || x == 'c' || x == 's' || x == 't' ||
          x == 'a' || x == 'l');
}
bool isNum(char x) { return (x >= '0' && x <= '9'); }

void nPush(Nums **list, double x) {
  Nums *p = malloc(sizeof(Nums));
  p->data = x;
  p->next = *list;
  *list = p;
}

void sPush(Syms **list, char x) {
  Syms *p = malloc(sizeof(Syms));
  p->data = x;
  p->next = *list;
  *list = p;
}

double nPop(Nums **list) {
  Nums *p = *list;
  double data;
  data = p->data;
  *list = p->next;
  free(p);
  return data;
}

char sPop(Syms **list) {
  Syms *p = *list;
  char data;
  data = p->data;
  *list = p->next;
  free(p);
  return data;
}
