#include "s21_decimal.h"

s21_decimal s21_negate(s21_decimal src) {
  if (!src.value_type) {
    swap_bit(&src, 127);
  } else {
    init_dec_no_type(&src);
  }
  return src;
}
