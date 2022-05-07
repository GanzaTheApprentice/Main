#include "s21_decimal.h"

s21_decimal s21_floor(s21_decimal src) {
  if (src.value_type == 0) {
    int flag = 0;
    if (empty_s21_dec(src)) {
      flag = 1;
    }
    int sign = get_sign(src), scale = get_s21_scale(src);
    src = s21_truncate(src);
    super_decimal one_plus, buf;
    init_sup_dec(&buf);
    init_sup_dec(&one_plus);
    dec_to_superdec(&src, &buf);
    one_plus.bits[0] = 1;

    if (flag) {
      if (sign && scale) {
        buf = add_dec(buf, one_plus);
      }
    } else {
      init_sup_dec(&buf);
    }

    superdec_to_dec(&buf, &src);
    set_sign(&src, sign);
  } else {
    init_dec_no_type(&src);
  }
    return src;
  }
