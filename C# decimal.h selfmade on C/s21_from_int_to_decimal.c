#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  if (dst != NULL) {
    int sign = 0;
    super_decimal buf;
    init_dec(dst);
    init_sup_dec(&buf);
    dec_to_superdec(dst, &buf);

    if (src < 0) {
      sign = 1;
      src *= -1;
    }
    for (int i = 0; i < 96; i++) {
      if (src % 2 != 0) {
        set_bit(&buf, i);
        src -= 1;
        src /= 2;
      } else {
        zero_bit(&buf, i);
        src /= 2;
      }
    }

    superdec_to_dec(&buf, dst);
    if (sign) set_sign(dst, 1);
  } else {
    flag = 1;
  }
  return flag;
}

