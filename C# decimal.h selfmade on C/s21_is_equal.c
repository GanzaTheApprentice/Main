#include "s21_decimal.h"

int s21_is_equal(s21_decimal x, s21_decimal y) {
  int flag = 0;
  if (!type_for_eq(x, y)) {
    int sign_1 = get_sign(x), sign_2 = get_sign(y);
    super_decimal one, two;
    init_sup_dec(&one);
    init_sup_dec(&two);
    convert_decs(&x, &y, &one, &two);
    int scl_1 = get_scale(one), scl_2 = get_scale(two);
    scale_correcting(&one, &scl_1);
    scale_correcting(&two, &scl_2);
    if (which_bits(&one, &two) != -1) {
      flag = 1;
    } else if (sign_1 != sign_2 && empty_dec(one) && empty_dec(two)) {
      flag = 1;
    } else if (scl_1 != scl_2 && empty_dec(one) && empty_dec(two)) {
      flag = 1;
    }

  } else {
    flag = type_for_eq(x, y);
  }
  return flag;
}
