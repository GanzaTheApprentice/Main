#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dec) {
  int flag = 0;
  if (dec == NULL) {
    flag = 1;
  } else {
    if (src.value_type == 1) {
      *dec = INFINITY;
      flag = 1;
    } else if (src.value_type == 2) {
      *dec = -INFINITY;
      flag = 1;
    } else if (src.value_type == 3) {
      *dec = NAN;
      flag = 1;
    } else {
      double res = 0;
      int sign = get_sign(src);
      super_decimal buf;
      init_sup_dec(&buf);
      dec_to_superdec(&src, &buf);

      for (int i = 0; i < 192; i++) {
        res += pow(2, i) * get_bit(buf, i);
      }

      res /= pow(10, get_scale(buf));

      if (sign) {
        res *= -1;
      }
      *dec = res;
    }
  }
  return flag;
}
