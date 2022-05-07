#include "s21_decimal.h"

s21_decimal s21_round(s21_decimal src) {
  if (src.value_type == 0) {
    int sign = get_sign(src), scale = get_s21_scale(src);
    if (empty_s21_dec(src)) {
      super_decimal one_plus, buf;
      init_sup_dec(&buf);
      init_sup_dec(&one_plus);
      dec_to_superdec(&src, &buf);
      one_plus.bits[0] = 1;

      scale_correcting(&buf, &scale);

      if (scale > 1) {
        scale--;
        truncate(&buf, scale);
        scale_round(&buf);
      } else if (scale == 1) {
        scale_round(&buf);
      }

      buf.bits[6] = 0;
      superdec_to_dec(&buf, &src);
      set_sign(&src, sign);

    } else {
      init_dec(&src);
      set_sign(&src, sign);
    }
  } else {
    init_dec_no_type(&src);
  }
  return src;
}
