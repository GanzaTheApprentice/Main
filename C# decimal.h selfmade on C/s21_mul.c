#include "s21_decimal.h"

s21_decimal s21_mul(s21_decimal x, s21_decimal y) {
  if (!type_for_mul(x, y)) {
    int sign_1 = get_sign(x), sign_2 = get_sign(y);
    super_decimal one, two, res, sub;
    convert_decs(&x, &y, &one, &two);
    int scl_1 = get_scale(one), scl_2 = get_scale(two);
    scale_correcting(&one, &scl_1);
    scale_correcting(&two, &scl_2);
    int scale = scl_1 + scl_2;
    init_sup_dec(&res);
    init_sup_dec(&sub);
    if (empty_dec(one) && empty_dec(two)) {
      for (int i = 0; i < 96; i++) {
        int score = i;
        for (int j = 0; j < 96; j++) {
          if (get_bit(one, j) && get_bit(two, i)) {
            set_bit(&sub, j);
          } else {
            zero_bit(&sub, j);
          }
        }
        if (i > 0) {
          while (score) {
            great_shift(&sub);
            score--;
          }
        }
        res = add_dec(res, sub);
        init_sup_dec(&sub);
      }
    } else {
      convert_decs(&x, &y, &one, &two);
      if (!empty_dec(one)) {
        scale = get_scale(one);
      } else if (!empty_dec(two)) {
        scale = get_scale(two);
      }
      init_sup_dec(&res);
    }
    if (check_overflow(res) && scale) {
      dec_reduction(&res, &scale);
    }
    while (scale > 28) {
      if (!check_overflow(res) && empty_dec(res)) {
        scale_round(&res);
        scale--;
      } else {
        scale--;
      }
    }

    if (scale <= 0 && check_overflow(res) && sign_1 && !sign_2) {
      init_dec(&x);
      x.value_type = 2;
    } else if (scale <= 0 && check_overflow(res) && !sign_1 && sign_2) {
      init_dec(&x);
      x.value_type = 2;
    } else if (scale <= 0 && check_overflow(res)) {
      init_dec(&x);
      x.value_type = 1;
    } else {
      res.bits[6] = scale;
      superdec_to_dec(&res, &x);
      set_scale(&x, x.bits[S]);

      if (sign_1 && !sign_2)
        set_sign(&x, 1);
      else if (!sign_1 && sign_2)
        set_sign(&x, 1);
    }
  } else {
    x.value_type = type_for_mul(x, y);
    init_dec_no_type(&x);
  }
  return x;
}
