#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;
  if (dst == NULL) {
    flag = 1;
  } else {
    init_dec(dst);
    if (isinf(src) || isnan(src) || src > MAX_DEC || src < -MAX_DEC) {
      flag = 1;
      if (src == INFINITY || src > MAX_DEC) {
        dst->value_type = 1;
      } else if (src == -INFINITY || src < -MAX_DEC) {
        dst->value_type = 2;
      } else if (isnan(src)) {
        dst->value_type = 3;
      }
    } else {
      if (src == (int)src && (int)src < 1000000) {
        s21_from_int_to_decimal((int)src, dst);
      } else {
        int res, total, sign = 0, scale = 0;
        if (src < 0) {
          sign = 1;
          src *= -1;
        }
        res = float_to_int(src);

        if (src < 1000000) {
          total = (int)src;
          int tmp = res;
          while (tmp > total) {
            tmp /= 10;
            scale++;
          }
        }

        super_decimal buf;
        init_dec(dst);
        init_sup_dec(&buf);
        dec_to_superdec(dst, &buf);

        for (int i = 0; i < 96; i++) {
          if (res % 2 != 0) {
            set_bit(&buf, i);
            res -= 1;
            res /= 2;
          } else {
            zero_bit(&buf, i);
            res /= 2;
          }
        }

        total = check_exp(src);
        if (check_neg_exp(src) && total > 1) {
          scale += total - 1;
          while (scale > 28 && empty_dec(buf)) {
            scale_round(&buf);
            scale--;
          }
          if (!empty_dec(buf)) {
            scale = 0;
          }
        } else {
          while (total > 6) {
            shift_mul_ten(&buf);
            total--;
          }
        }

        superdec_to_dec(&buf, dst);
        if (scale < 29) {
          set_scale(dst, scale);
          if (sign) set_sign(dst, 1);
        }
      }
    }
  }
    return flag;
}
