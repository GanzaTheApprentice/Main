#include "s21_decimal.h"

s21_decimal s21_sub(s21_decimal x, s21_decimal y) {
  if (!type_for_sub(x, y)) {
    int flag = 0, scale, sign_1 = get_sign(x), sign_2 = get_sign(y);
    super_decimal one, two, res;
    convert_decs(&x, &y, &one, &two);
    init_sup_dec(&res);
    scale_for_sub(&one, &two, &res);
    scale = res.bits[6];

    if (!is_greater_or_equal(one, two)) {
      if (sign_1 && !sign_2) {
        res = add_dec(one, two);
        flag = 1;
      } else if (sign_1 && sign_2) {
        res = sub_dec(one, two);
        flag = 1;
      } else if (!sign_1 && sign_2) {
        res = add_dec(one, two);
      } else {
        res = sub_dec(one, two);
      }
    } else {
      if (sign_1 && !sign_2) {
        res = add_dec(one, two);
        flag = 1;
      } else if (!sign_1 && sign_2) {
        res = add_dec(one, two);
      } else if (sign_1 && sign_2) {
        res = sub_dec(two, one);
      } else {
        res = sub_dec(two, one);
        flag = 1;
      }
    }
    if (check_overflow(res) && scale) {
      dec_reduction(&res, &scale);
    }
    if (check_overflow(res) && scale <= 0) {
      x.value_type = flag ? 2 : 1;
      init_dec_no_type(&x);
    } else {
      convert_decs(&x, &y, &one, &two);
      if (!empty_dec(one) && get_scale(one)) {
        scale = get_scale(one);
      } else if (!empty_dec(two) && get_scale(two)) {
        scale = get_scale(two);
      }
      superdec_to_dec(&res, &x);
      set_scale(&x, scale);
      if (flag) set_sign(&x, 1);
    }
  } else {
    x.value_type = type_for_sub(x, y);
    init_dec_no_type(&x);
  }
  return x;
}
