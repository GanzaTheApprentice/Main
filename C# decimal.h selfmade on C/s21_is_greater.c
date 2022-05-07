#include "s21_decimal.h"

int s21_is_greater(s21_decimal x, s21_decimal y) {
  int flag = 1;
  if (type_for_great(x, y) < 0) {
    super_decimal one, two;
    convert_decs(&x, &y, &one, &two);
    int scl_1 = get_scale(one), scl_2 = get_scale(two);
    scale_correcting(&one, &scl_1);
    scale_correcting(&two, &scl_2);
    int scale = (scl_1 > scl_2) ? (scl_1 - scl_2) : (scl_2 - scl_1);
    int sign_one = get_sign(x), sign_two = get_sign(y);
    super_decimal scale_dec;
    init_sup_dec(&scale_dec);
    scale_dec = set_scale_to_dec(scale_dec, scale);
    if (scl_1 > scl_2) {
      two = mul_dec(two, scale_dec);
    } else {
      one = mul_dec(one, scale_dec);
    }

    scale = is_less(one, two);
    if (which_bits(&one, &two) < 0 && empty_dec(one) && empty_dec(two)) {
      if (!sign_one && sign_two) {
        flag = 0;
      }
    } else {
      if (!sign_one && sign_two && empty_dec(one) && empty_dec(two)) {
        flag = 0;
      } else if (sign_one && sign_two && !scale) {
        flag = 0;
      } else if (!sign_one && !sign_two && scale) {
        flag = 0;
      }
    }
  } else {
      flag = type_for_great(x, y);
  }
  return flag;
}
