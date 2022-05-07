#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  if (!src.value_type && dst != NULL) {
    int sign = get_sign(src);
    src = s21_truncate(src);
    *dst = 0;
    super_decimal buf;
    init_sup_dec(&buf);
    dec_to_superdec(&src, &buf);

    for (int i = 95; i >= 0; i--) {
      if (get_bit(buf, i)) {
        *dst += my_pow(2, i);
      }
    }
    if (sign) {
      *dst *= -1;
    }
  } else {
    flag = 1;
  }
  return flag;
}
