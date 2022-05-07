#include "s21_decimal.h"

s21_decimal s21_mod(s21_decimal x, s21_decimal y) {
  if (!type_for_mod(x, y)) {
    int sign_1 = get_sign(x);
    super_decimal one, two, res;
    init_sup_dec(&res);

    convert_decs(&x, &y, &one, &two);
    int scale_1 = get_scale(one), scale_2 = get_scale(two);

    if (empty_dec(one)) {
      scale_for_div(&one, &two);
      if (!is_greater_or_equal(one, two)) {
        res = mod_dec(one, two);
      } else {
        scale_correcting(&one, &scale_2);
        res = one;
      }
      superdec_to_dec(&res, &x);
      if (scale_1 > scale_2) {
        set_scale(&x, scale_1);
      } else {
        set_scale(&x, scale_2);
      }
      if (sign_1) set_sign(&x, 1);
    }

  } else if (type_for_mod(x, y) == 4) {
    x.value_type = 0;
  } else if (type_for_mod(x, y) == 2) {
    x.value_type = 0;
    init_dec_no_type(&x);
  } else {
    x.value_type = type_for_mod(x, y);
    init_dec_no_type(&x);
  }
  return x;
}
