#include "s21_decimal.h"

s21_decimal s21_truncate(s21_decimal src) {
  if (src.value_type == 0) {
    int sign = get_sign(src);
    if (empty_s21_dec(src)) {
      super_decimal res;
      init_sup_dec(&res);
      dec_to_superdec(&src, &res);
      int scale = get_scale(res);

      scale_correcting(&res, &scale);
      if (scale) truncate(&res, scale);
      res.bits[6] = 0;

      superdec_to_dec(&res, &src);
    } else {
      init_dec(&src);
    }
    set_sign(&src, sign);
  } else {
    init_dec_no_type(&src);
  }
  return src;
}
