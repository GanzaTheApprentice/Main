#include "s21_decimal.h"

s21_decimal s21_div(s21_decimal x, s21_decimal y) {
  int sign_1 = get_sign(x), sign_2 = get_sign(y);
  if (!type_for_div(x, y, sign_1, sign_2)) {
    super_decimal one, two, res, one_plus;
    convert_decs(&x, &y, &one, &two);
    init_sup_dec(&res);
    init_sup_dec(&one_plus);
    one_plus.bits[L] = 1;

    scale_for_div(&one, &two);
    two = div_balancer(one, two);

    int scale = 0;
    scale -= two.bits[6];

    while (empty_dec(one)) {
      while (!is_less(one, two)) {
        shift_mul_ten(&one);
        shift_mul_ten(&res);
        scale++;
      }
      while (!is_greater_or_equal(one, two)) {
        one = sub_dec(one, two);
        res = add_dec(res, one_plus);
      }
      if (scale > 28) {
        while (scale != 28 && !check_overflow(res) && empty_dec(one)) {
          scale_round(&res);
          scale--;
        }
        break;
      }
    }
    if (scale < 0) {
      scale *= -1;
      while (scale) {
        shift_mul_ten(&res);
        scale--;
      }
    }
    if (check_overflow(res) && scale) {
      dec_reduction(&res, &scale);
    }
    if (scale <= 0 && check_overflow(res) &&
        ((!sign_1 && !sign_2) || (sign_1 && sign_2))) {
      init_dec(&x);
      x.value_type = 1;
    } else if (scale <= 0 && check_overflow(res)) {
      init_dec(&x);
      x.value_type = 2;
    } else {
      scale_correcting(&res, &scale);
      superdec_to_dec(&res, &x);
      if (empty_s21_dec(x)) set_scale(&x, scale);

      if (sign_1 && !sign_2) {
        set_sign(&x, 1);
      } else if (!sign_1 && sign_2) {
        set_sign(&x, 1);
      }
    }
  } else if (type_for_div(x, y, sign_1, sign_2) == 6) {
    if (sign_1 && !sign_2) {
      set_sign(&x, 1);
    } else if (!sign_1 && sign_2) {
      set_sign(&x, 1);
    }
  } else if (type_for_div(x, y, sign_1, sign_2) == 4) {
    x.value_type = 0;
    init_dec_no_type(&x);
  } else if (type_for_div(x, y, sign_1, sign_2) == 5) {
    x.value_type = 0;
    init_dec_no_type(&x);
    set_sign(&x, 1);
  } else {
    x.value_type = type_for_div(x, y, sign_1, sign_2);
    init_dec_no_type(&x);
  }
  return x;
}
