#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#define L 0
#define M 1
#define H 2
#define S 3
#define SCALE_MASK 0xFF0000
#define MAX_DEC 79228162514264337593543950335.0

typedef enum {
  s21_NORMAL_VALUE = 0,
  s21_INFINITY = 1,
  s21_NEGATIVE_INFINITY = 2,
  s21_NAN = 3
} value_type_t;

typedef struct {
  unsigned int bits[4];
  value_type_t value_type;
} s21_decimal;

typedef struct {
  unsigned int bits[7];
  value_type_t value_type;
} super_decimal;

int float_to_int(float src);
int check_exp(float src);
int check_neg_exp(float src);
void truncate(super_decimal *src, int scale);
void scale_round(super_decimal *src);
void dec_to_superdec(s21_decimal *one, super_decimal *two);
void superdec_to_dec(super_decimal *one, s21_decimal *two);
void convert_decs(s21_decimal *x, s21_decimal *y, super_decimal *one,
                  super_decimal *two);
super_decimal from_one_divider(super_decimal src);
super_decimal div_balancer(super_decimal one, super_decimal two);
void shift_mul_ten(super_decimal *src);
void scale_correcting(super_decimal *src, int *scale);
void dec_reduction(super_decimal *src, int *scale);
long long my_pow(int x, int y);
void init_dec(s21_decimal *src);
void init_sup_dec(super_decimal *src);
int which_bits(super_decimal *one, super_decimal *two);
void great_shift(super_decimal *src);
void shift_one_bit(super_decimal *src);
int get_bit(super_decimal src, const int n);
void set_bit(super_decimal *src, const int n);
void swap_bit(s21_decimal *src, const int n);
void zero_bit(super_decimal *src, const int n);
int get_scale(super_decimal src);
int get_s21_scale(s21_decimal src);
int get_sign(s21_decimal src);
void set_scale(s21_decimal *src, int scale);
void set_sign(s21_decimal *src, int sign);
super_decimal mul_dec(super_decimal one, super_decimal two);
super_decimal add_dec(super_decimal one, super_decimal two);
super_decimal sub_dec(super_decimal one, super_decimal two);
super_decimal div_dec(super_decimal one, super_decimal two);
super_decimal mod_dec(super_decimal one, super_decimal two);
super_decimal set_scale_to_dec(super_decimal src, int scale);
int is_less(super_decimal one, super_decimal two);
int is_greater(super_decimal one, super_decimal two);
int is_greater_or_equal(super_decimal one, super_decimal two);
int empty_dec(super_decimal src);
int empty_s21_dec(s21_decimal src);
void scale_for_add(super_decimal *one, super_decimal *two, super_decimal *res);
void scale_for_mul(super_decimal *one, super_decimal *two, super_decimal *res);
void scale_for_div(super_decimal *one, super_decimal *two);
void scale_for_sub(super_decimal *one, super_decimal *two, super_decimal *res);

s21_decimal s21_add(s21_decimal x, s21_decimal y);
s21_decimal s21_mul(s21_decimal x, s21_decimal y);
s21_decimal s21_sub(s21_decimal x, s21_decimal y);
s21_decimal s21_div(s21_decimal x, s21_decimal y);
int s21_is_equal(s21_decimal x, s21_decimal y);
int s21_is_not_equal(s21_decimal one, s21_decimal two);
int s21_is_greater(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y);
int s21_is_less(s21_decimal x, s21_decimal y);
int s21_is_less_or_equal(s21_decimal x, s21_decimal y);
s21_decimal s21_truncate(s21_decimal src);
s21_decimal s21_round(s21_decimal src);
s21_decimal s21_floor(s21_decimal src);
s21_decimal s21_mod(s21_decimal one, s21_decimal two);
s21_decimal s21_negate(s21_decimal src);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

void init_dec_no_type(s21_decimal *src);
int empty_dec_for_check(super_decimal src);
int check_overflow(super_decimal src);
int type_for_add(s21_decimal one, s21_decimal two);
int type_for_sub(s21_decimal one, s21_decimal two);
int type_for_less(s21_decimal one, s21_decimal two);
int type_for_great(s21_decimal one, s21_decimal two);
int type_for_eq(s21_decimal one, s21_decimal two);
int type_for_div(s21_decimal one, s21_decimal two, int sign_1, int sign_2);
int type_for_mul(s21_decimal one, s21_decimal two);
int type_for_mod(s21_decimal one, s21_decimal two);
int type_for_not_eq(s21_decimal one, s21_decimal two);
int its_one(s21_decimal src);
#endif  // SRC_S21_DECIMAL_H_
