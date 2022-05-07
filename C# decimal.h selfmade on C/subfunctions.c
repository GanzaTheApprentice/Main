#include "s21_decimal.h"

int float_to_int(float src) {
  char buffer[33], buffer_2[33];
  int res = 0, lenght = 0;
  snprintf(buffer, sizeof(buffer), "%.6e", src);
  for (int i = 0; i < 33; i++) {
    if (buffer[i] == 'e' || buffer[i] == 'E') {
      buffer[i] = '\0';
      break;
    }
  }
  int j = 0;
  lenght = strlen(buffer);
  for (int i = 0; i < lenght; i++) {
    if (buffer[i] != '.') {
      buffer_2[j] = buffer[i];
      j++;
    }
  }
  lenght = strlen(buffer_2);
  for (int i = 0; i < lenght; i++) {
    res += (buffer_2[i] + '0' - 96);
    if (i < lenght - 1) res *= 10;
  }
  return res;
}

int check_exp(float src) {
  char buffer[33];
  int res = 0;
  snprintf(buffer, sizeof(buffer), "%e", src);
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == '+' || buffer[i] == '-') {
      i++;
      for (int j = i; buffer[j] != '\0'; j++) {
        res += buffer[j] + '0' - 96;
        if (buffer[j + 1] != '\0') res *= 10;
      }
      break;
    }
  }
  return res;
}

int check_neg_exp(float src) {
  char buffer[33];
  int flag = 0;
  snprintf(buffer, sizeof(buffer), "%e", src);
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == '-') {
      flag = 1;
    }
  }
  return flag;
}

void dec_reduction(super_decimal *src, int *scale) {
  super_decimal one_plus, mod, divider = from_one_divider(*src);
  init_sup_dec(&mod);
  init_sup_dec(&one_plus);
  one_plus.bits[0] = 10;
  unsigned int digit, score = 30;
  digit = divider.bits[6] - score;
  *scale = *scale - digit;
  unsigned int flag = 0;
  while ((check_overflow(*src) && *scale > 0) || flag) {
    if (flag) {
      flag = 0;
      *scale -= 1;
      score--;
    }
    mod = *src;
    digit = score;
    for (unsigned int i = 0; i < score; i++) {
      while (!is_greater_or_equal(mod, divider)) {
        mod = sub_dec(mod, divider);
      }
      shift_mul_ten(&mod);
    }
    unsigned int divider_digit = divider.bits[6] - digit;
    mod = div_dec(mod, divider);
    if (mod.bits[6] > 999) {
      *scale = -1;
      break;
    }
    divider = from_one_divider(mod);
    while (divider.bits[6] != divider_digit) {
      shift_mul_ten(&mod);
      divider.bits[6]++;
    }
    if (mod.bits[0] >= 5 && mod.bits[0] < 10) *src = add_dec(*src, one_plus);
    *src = sub_dec(*src, mod);
    divider = from_one_divider(*src);
    *src = div_dec(*src, divider);
    divider = from_one_divider(*src);
    while (divider.bits[6] < digit) {
      shift_mul_ten(src);
      divider.bits[6]++;
    }
    if (check_overflow(*src) && *scale > 0) {
      score--;
      *scale -= 1;
    }
    if (!check_overflow(*src) && *scale > 28) {
      flag = 1;
    }
  }
}

void scale_correcting(super_decimal *src, int *scale) {
  super_decimal buf, divider = from_one_divider(*src);
  unsigned int digit = divider.bits[6];
  init_sup_dec(&buf);
  buf = *src;
  buf = div_dec(buf, divider);

  if (which_bits(&buf, src) != -1) {
    while (*scale) {
      divider = from_one_divider(*src);
      *src = div_dec(*src, divider);
      divider = from_one_divider(*src);
      digit--;

      if (divider.bits[6] == digit) {
        *scale -= 1;
        break;
      }
      while (divider.bits[6] < digit) {
        shift_mul_ten(src);
        divider.bits[6]++;
      }
      *scale -= 1;
    }
  }
}

void convert_decs(s21_decimal *x, s21_decimal *y, super_decimal *one,
                  super_decimal *two) {
  init_sup_dec(one);
  init_sup_dec(two);
  dec_to_superdec(x, one);
  dec_to_superdec(y, two);
}

void dec_to_superdec(s21_decimal *one, super_decimal *two) {
  two->bits[0] = one->bits[0];
  two->bits[1] = one->bits[1];
  two->bits[2] = one->bits[2];
  two->bits[6] = one->bits[3];
  two->value_type = one->value_type;
}

void superdec_to_dec(super_decimal *one, s21_decimal *two) {
  two->bits[0] = one->bits[0];
  two->bits[1] = one->bits[1];
  two->bits[2] = one->bits[2];
  two->bits[3] = one->bits[6];
  two->value_type = one->value_type;
}

void shift_mul_ten(super_decimal *src) {
  super_decimal one = *src, two = *src;
  for (int i = 0; i < 3; i++) {
    great_shift(&one);
  }
  great_shift(&two);
  *src = add_dec(one, two);
}

long long my_pow(int x, int y) {
  long long z = 1;
  while (y) {
    z = z * x;
    y--;
  }
  return z;
}

super_decimal mod_dec(super_decimal one, super_decimal two) {
  two = div_balancer(one, two);
  unsigned int digit = two.bits[6];
  if (digit) {
    for (unsigned int i = 0; i != digit + 1; i++) {
      while (!is_greater_or_equal(one, two)) {
        one = sub_dec(one, two);
      }
      if (i != digit) shift_mul_ten(&one);
    }
  } else {
    while (!is_greater_or_equal(one, two)) {
      one = sub_dec(one, two);
    }
  }
  super_decimal divider = from_one_divider(one);
  if (divider.bits[6]) {
    unsigned int digit_2 = divider.bits[6] - digit;
    if (digit) {
      two = from_one_divider(one);
      one = div_dec(one, two);
    }
    divider = from_one_divider(one);
    digit = divider.bits[6];
    while (digit != digit_2) {
      shift_mul_ten(&one);
      digit++;
    }
  }
  return one;
}

void truncate(super_decimal *src, int scale) {
  super_decimal buf, divider = from_one_divider(*src);
  init_sup_dec(&buf);
  buf = *src;
  scale = divider.bits[6] - scale;
  unsigned int digit = scale;

  while (scale > 0) {
    while (!is_greater_or_equal(buf, divider)) {
      buf = sub_dec(buf, divider);
    }
    if (empty_dec(buf)) {
      while (!is_less(buf, divider) && scale > 0) {
        shift_mul_ten(&buf);
        scale--;
      }
    }
  }

  buf = div_dec(buf, divider);
  *src = sub_dec(*src, buf);
  divider = from_one_divider(*src);
  *src = div_dec(*src, divider);
  divider = from_one_divider(*src);
  while (divider.bits[6] < digit) {
    shift_mul_ten(src);
    divider.bits[6]++;
  }
}

void scale_round(super_decimal *src) {
  super_decimal one_plus, buf, divider = from_one_divider(*src);
  init_sup_dec(&buf);
  init_sup_dec(&one_plus);
  one_plus.bits[0] = 10;
  buf = *src;
  unsigned int score = divider.bits[6] - 1;
  for (unsigned int i = 0; i < score; i++) {
    while (!is_greater_or_equal(buf, divider)) {
      buf = sub_dec(buf, divider);
    }
    shift_mul_ten(&buf);
  }
  buf = div_dec(buf, divider);
  if (buf.bits[0] >= 5) *src = add_dec(*src, one_plus);
  *src = sub_dec(*src, buf);
  *src = div_dec(*src, divider);
  divider = from_one_divider(*src);
  while (divider.bits[6] != score) {
    shift_mul_ten(src);
    divider.bits[6]++;
  }
}

super_decimal div_balancer(super_decimal one, super_decimal two) {
  super_decimal buf = two;
  int score = 0;

  while (!is_greater(one, buf)) {
    shift_mul_ten(&buf);
    score++;
  }
  if (score) score--;
  for (int i = 0; i < score; i++) {
    shift_mul_ten(&two);
  }

  two.bits[6] = score;
  return two;
}

super_decimal div_dec(super_decimal one, super_decimal two) {
  super_decimal res, one_plus;
  init_sup_dec(&one_plus);
  init_sup_dec(&res);
  one_plus.bits[L] = 1;
  int score = 0;

  while (empty_dec(one) && score < 1000) {
    while (!is_less(one, two)) {
      shift_mul_ten(&one);
      shift_mul_ten(&res);
      score++;
    }
    one = sub_dec(one, two);
    res = add_dec(res, one_plus);
  }
  res.bits[6] = score;
  return res;
}

void scale_for_div(super_decimal *one, super_decimal *two) {
  int scl_1 = get_scale(*one), scl_2 = get_scale(*two);
  int scale = (scl_1 > scl_2) ? (scl_1 - scl_2) : (scl_2 - scl_1);
  super_decimal scale_dec;
  init_sup_dec(&scale_dec);
  scale_dec = set_scale_to_dec(scale_dec, scale);

  if (scl_1 > scl_2) {
    *two = mul_dec(*two, scale_dec);
  } else {
    *one = mul_dec(*one, scale_dec);
  }
}

int empty_dec(super_decimal src) {
  int flag = 0;
  if (src.bits[5]) flag = 1;
  if (src.bits[4]) flag = 1;
  if (src.bits[3]) flag = 1;
  if (src.bits[2]) flag = 1;
  if (src.bits[1]) flag = 1;
  if (src.bits[0]) flag = 1;
  return flag;
}

int empty_s21_dec(s21_decimal src) {
  int flag = 0;
  if (src.bits[2]) flag = 1;
  if (src.bits[1]) flag = 1;
  if (src.bits[0]) flag = 1;
  return flag;
}

int check_overflow(super_decimal src) {
  int flag = 0;
  if (src.bits[5]) flag = 1;
  if (src.bits[4]) flag = 1;
  if (src.bits[3]) flag = 1;
  return flag;
}

void great_shift(super_decimal *src) {
  int bts0 = 0, bts1 = 0, bts2 = 0, bts3 = 0, bts4 = 0;
  if (get_bit(*src, 31)) bts0 = 1;
  if (get_bit(*src, 63)) bts1 = 1;
  if (get_bit(*src, 95)) bts2 = 1;
  if (get_bit(*src, 127)) bts3 = 1;
  if (get_bit(*src, 159)) bts4 = 1;

  shift_one_bit(src);

  if (bts0) set_bit(src, 32);
  if (bts1) set_bit(src, 64);
  if (bts2) set_bit(src, 96);
  if (bts3) set_bit(src, 128);
  if (bts4) set_bit(src, 160);
}

int which_bits(super_decimal *one, super_decimal *two) {
  int flag = -1;
  if (one->bits[5] != two->bits[5]) {
    flag = 5;
  } else if (one->bits[4] != two->bits[4]) {
    flag = 4;
  } else if (one->bits[3] != two->bits[3]) {
    flag = 3;
  } else if (one->bits[2] != two->bits[2]) {
    flag = 2;
  } else if (one->bits[1] != two->bits[1]) {
    flag = 1;
  } else if (one->bits[0] != two->bits[0]) {
    flag = 0;
  } else {
    flag = -1;
  }
  return flag;
}

int is_greater(super_decimal one, super_decimal two) {
  int flag = 1, num_bits;

  num_bits = which_bits(&one, &two);

  if (num_bits >= 0) {
    if (one.bits[num_bits] > two.bits[num_bits]) {
      flag = 0;
    }
  }
  return flag;
}

int is_greater_or_equal(super_decimal one, super_decimal two) {
  int flag = 0, num_bits;

  num_bits = which_bits(&one, &two);

  if (num_bits >= 0) {
    if (one.bits[num_bits] > two.bits[num_bits]) {
      flag = 0;
    } else {
      flag = 1;
    }
  }
  return flag;
}

int is_less(super_decimal one, super_decimal two) {
  int flag = 1;
  int num_bits;

  num_bits = which_bits(&one, &two);

  if (num_bits >= 0) {
    if (one.bits[num_bits] < two.bits[num_bits]) {
      flag = 0;
    }
  }
  return flag;
}

super_decimal set_scale_to_dec(super_decimal src, int scale) {
  init_sup_dec(&src);
  src.bits[L] = 1;
  while (scale) {
    shift_mul_ten(&src);
    scale--;
  }
  return src;
}

void shift_one_bit(super_decimal *src) {
  src->bits[5] <<= 1;
  src->bits[4] <<= 1;
  src->bits[3] <<= 1;
  src->bits[2] <<= 1;
  src->bits[1] <<= 1;
  src->bits[0] <<= 1;
}

void init_dec(s21_decimal *src) {
  src->bits[L] = 0;
  src->bits[M] = 0;
  src->bits[H] = 0;
  src->bits[S] = 0;
  src->value_type = s21_NORMAL_VALUE;
}

void init_dec_no_type(s21_decimal *src) {
  src->bits[L] = 0;
  src->bits[M] = 0;
  src->bits[H] = 0;
  src->bits[S] = 0;
}

void init_sup_dec(super_decimal *src) {
  src->bits[0] = 0;
  src->bits[1] = 0;
  src->bits[2] = 0;
  src->bits[3] = 0;
  src->bits[4] = 0;
  src->bits[5] = 0;
  src->bits[6] = 0;
  src->value_type = s21_NORMAL_VALUE;
}

super_decimal from_one_divider(super_decimal src) {
  super_decimal divider;
  init_sup_dec(&divider);
  divider.bits[L] = 1;
  int score = 0, save_score = 0;

  while (!is_greater_or_equal(src, divider)) {
    shift_mul_ten(&divider);
    score++;
  }
  save_score = score;
  if (divider.bits[L] != 1) {
    init_sup_dec(&divider);
    divider.bits[L] = 1;
    score--;
    for (int i = 0; i != score; i++) {
      shift_mul_ten(&divider);
    }
  }
  divider.bits[6] = save_score;
  return divider;
}

super_decimal mul_dec(super_decimal one, super_decimal two) {
  super_decimal res, sub;
  init_sup_dec(&res);
  init_sup_dec(&sub);

  for (int i = 0; i < 192; i++) {
    int score = i;
    for (int j = 0; j < 192; j++) {
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
  return res;
}

super_decimal add_dec(super_decimal one, super_decimal two) {
  int v_ume = 0;
  super_decimal res;
  init_sup_dec(&res);

  for (int i = 0; i < 192; i++) {
    if (get_bit(one, i) && get_bit(two, i)) {
      if (v_ume == 0) {
        zero_bit(&res, i);
      } else {
        set_bit(&res, i);
      }
      v_ume = 1;
    } else if (get_bit(one, i) || get_bit(two, i)) {
      if (v_ume == 1) {
        zero_bit(&res, i);
      } else {
        set_bit(&res, i);
      }
    } else {
      if (v_ume == 1) {
        set_bit(&res, i);
        v_ume = 0;
      } else {
        zero_bit(&res, i);
      }
    }
  }
  return res;
}

void scale_for_sub(super_decimal *one, super_decimal *two, super_decimal *res) {
  int scl_1 = get_scale(*one), scl_2 = get_scale(*two);
  int scale = (scl_1 > scl_2) ? (scl_1 - scl_2) : (scl_2 - scl_1);
  super_decimal scale_dec;
  init_sup_dec(&scale_dec);
  scale_dec = set_scale_to_dec(scale_dec, scale);

  if (scl_1 > scl_2) {
    *two = mul_dec(*two, scale_dec);
    res->bits[6] = scl_1;
  } else {
    *one = mul_dec(*one, scale_dec);
    res->bits[6] = scl_2;
  }
}

super_decimal sub_dec(super_decimal one, super_decimal two) {
  super_decimal res;
  init_sup_dec(&res);
  int v_ume = 0;
  for (int i = 0; i < 192; i++) {
    if (get_bit(one, i) && get_bit(two, i)) {
      if (v_ume == 1) zero_bit(&one, i);
    } else if (get_bit(one, i) && !get_bit(two, i)) {
      if (v_ume == 1) {
        zero_bit(&one, i);
        v_ume = 0;
      }
    } else if (!get_bit(one, i) && get_bit(two, i)) {
      if (v_ume == 1) set_bit(&one, i);
      v_ume = 1;
    } else if (!get_bit(one, i) && !get_bit(two, i)) {
      if (v_ume == 1) set_bit(&one, i);
    }
  }
  for (int i = 0; i < 192; i++) {
    if (get_bit(one, i) && get_bit(two, i)) {
      zero_bit(&res, i);
    } else if (get_bit(one, i) && !get_bit(two, i)) {
      set_bit(&res, i);
    } else if (!get_bit(one, i) && get_bit(two, i)) {
      set_bit(&res, i);
    } else if (!get_bit(one, i) && !get_bit(two, i)) {
      zero_bit(&res, i);
    }
  }
  return res;
}

void scale_for_add(super_decimal *one, super_decimal *two, super_decimal *res) {
  int scl_1 = get_scale(*one), scl_2 = get_scale(*two);
  int scale = (scl_1 > scl_2) ? (scl_1 - scl_2) : (scl_2 - scl_1);
  super_decimal scale_dec;
  init_sup_dec(&scale_dec);
  scale_dec = set_scale_to_dec(scale_dec, scale);
  if (scl_1 > scl_2) {
    *two = mul_dec(*two, scale_dec);
    res->bits[6] = scl_1;
  } else {
    *one = mul_dec(*one, scale_dec);
    res->bits[6] = scl_2;
  }
}

int get_sign(s21_decimal src) {
  super_decimal x;
  init_sup_dec(&x);
  dec_to_superdec(&src, &x);
  return get_bit(x, 223);
}

void set_sign(s21_decimal *src, int sign) {
  super_decimal x;
  init_sup_dec(&x);
  dec_to_superdec(src, &x);

  if (sign == 0) {
    zero_bit(&x, 223);
  } else {
    set_bit(&x, 223);
  }

  superdec_to_dec(&x, src);
}

int get_scale(super_decimal src) { return ((src.bits[6] & SCALE_MASK) >> 16); }
int get_s21_scale(s21_decimal src) {
  return ((src.bits[3] & SCALE_MASK) >> 16);
}
void set_scale(s21_decimal *src, int scale) { src->bits[S] = scale << 16; }

int get_bit(super_decimal src, const int n) {
  return (src.bits[n / 32] & (1 << (n % 32))) != 0;
}

void zero_bit(super_decimal *src, const int n) {
  src->bits[n / 32] &= ~(1 << (n % 32));
}

void swap_bit(s21_decimal *src, const int n) {
  src->bits[n / 32] ^= (1 << (n % 32));
}

void set_bit(super_decimal *src, const int n) {
  src->bits[n / 32] |= (1 << (n % 32));
}

int type_for_add(s21_decimal one, s21_decimal two) {
  int res = 0;
  if (!one.value_type && !two.value_type) {
    res = 0;
  } else if ((!one.value_type && two.value_type == 1) ||
             (one.value_type == 1 && !two.value_type) ||
             (one.value_type == 1 && two.value_type == 1)) {
    res = 1;
  } else if ((!one.value_type && two.value_type == 2) ||
             (one.value_type == 2 && !two.value_type) ||
             (one.value_type == 2 && two.value_type == 2)) {
    res = 2;
  } else if ((!one.value_type && two.value_type == 3) ||
             (one.value_type == 3 && !two.value_type) ||
             (one.value_type == 3 && two.value_type == 3) ||
             (one.value_type == 1 && two.value_type == 2) ||
             (one.value_type == 2 && two.value_type == 1)) {
    res = 3;
  }
  return res;
}

int type_for_sub(s21_decimal one, s21_decimal two) {
  int res;
  if (!one.value_type && !two.value_type) {
    res = 0;
  } else if ((!one.value_type && two.value_type == 2) ||
             (one.value_type == 1 && !two.value_type) ||
             (one.value_type == 1 && two.value_type == 2)) {
    res = 1;
  } else if ((!one.value_type && two.value_type == 1) ||
             (one.value_type == 2 && !two.value_type)) {
    res = 2;
  } else {
    res = 3;
  }
  return res;
}

int type_for_less(s21_decimal one, s21_decimal two) {
  int res = 0;
  if (!one.value_type && !two.value_type) {
    res = -1;
  } else if ((!one.value_type && two.value_type == 1) ||
             (one.value_type == 2 && !two.value_type) ||
             (one.value_type == 2 && two.value_type == 1)) {
    res = 0;
  } else if ((!one.value_type && two.value_type == 2) ||
             (one.value_type == 1 && !two.value_type) ||
             (one.value_type == 1 && two.value_type == 2) ||
             (one.value_type == 3 && two.value_type == 3) ||
             (one.value_type == 1 && two.value_type == 3) ||
             (one.value_type == 1 && two.value_type == 1) ||
             (one.value_type == 2 && two.value_type == 2) ||
             (one.value_type == 3 && two.value_type == 2)) {
    res = 1;
  }
  return res;
}

int type_for_great(s21_decimal one, s21_decimal two) {
  int res = 1;
  if (!one.value_type && !two.value_type) {
    res = -1;
  } else if ((!one.value_type && two.value_type == 2) ||
             (one.value_type == 1 && !two.value_type) ||
             (one.value_type == 1 && two.value_type == 2)) {
    res = 0;
  }
  return res;
}

int type_for_eq(s21_decimal one, s21_decimal two) {
  int res;
  if (!one.value_type && !two.value_type) {
    res = 0;
  } else if ((one.value_type == 1 && two.value_type == 1) ||
             (one.value_type == 2 && two.value_type == 2)) {
    res = 0;
  } else {
    res = 1;
  }
  return res;
}

int type_for_div(s21_decimal one, s21_decimal two, int sign_1, int sign_2) {
  int res = 0;
  if (!one.value_type && !empty_s21_dec(one) && !two.value_type &&
      empty_s21_dec(two)) {
    res = 6;
  } else if (!one.value_type && !two.value_type && empty_s21_dec(two)) {
    res = 0;
  } else if (!one.value_type && !two.value_type) {
    if (sign_2)
      res = 2;
    else
      res = 1;
  } else if (one.value_type == 1 && !two.value_type) {
    if (sign_2)
      res = 2;
    else
      res = 1;
  } else if (one.value_type == 2 && !two.value_type) {
    if (sign_2)
      res = 1;
    else
      res = 2;
  } else if (!one.value_type && two.value_type == 1) {
    if (!sign_1)
      res = 4;
    else
      res = 5;
  } else if (!one.value_type && two.value_type == 2) {
    if (!sign_1)
      res = 5;
    else
      res = 4;
  } else {
    res = 3;
  }
  return res;
}

int type_for_mul(s21_decimal one, s21_decimal two) {
  int res = 0;
  if (!one.value_type && !two.value_type) {
    res = 0;
  } else if ((!one.value_type && two.value_type == 1) ||
             (one.value_type == 1 && !two.value_type)) {
    res = 1;
  } else if ((!one.value_type && two.value_type == 2) ||
             (one.value_type == 2 && !two.value_type)) {
    res = 2;
  } else if ((one.value_type == 1 && two.value_type == 1) ||
             (one.value_type == 2 && two.value_type == 2)) {
    res = 1;
  } else if ((one.value_type == 3 && !two.value_type) ||
             (one.value_type == 2 && two.value_type == 1) ||
             (one.value_type == 1 && two.value_type == 2) ||
             (!one.value_type && two.value_type == 3)) {
    res = 3;
  }
  return res;
}

int type_for_mod(s21_decimal one, s21_decimal two) {
  int res;
  if (!one.value_type && !two.value_type && empty_s21_dec(two)) {
    res = 0;
  } else if (!one.value_type && !its_one(one) &&
             (two.value_type == 1 || two.value_type == 2)) {
    res = 4;
  } else if (!one.value_type && (two.value_type == 1 || two.value_type == 2)) {
    res = 2;
  } else {
    res = 3;
  }
  return res;
}

int type_for_not_eq(s21_decimal one, s21_decimal two) {
  int res;
  if (!one.value_type && !two.value_type) {
    res = 2;
  } else if ((one.value_type == 1 && two.value_type == 1) ||
             (one.value_type == 2 && two.value_type == 2)) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int its_one(s21_decimal src) {
  int flag = 0;
  if (src.bits[2]) flag = 1;
  if (src.bits[1]) flag = 1;
  if (src.bits[0] != 1) flag = 1;
  return flag;
}
