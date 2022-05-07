#include <check.h>
#include <math.h>
#include <stdio.h>
#define DECIMAL_DEFAULT \
  { 0 }

#include "s21_decimal.h"

START_TEST(s21_add_test1) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000110;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test2) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test3) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000011110;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test4) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000101011;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test5) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test6) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000100;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test7) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000011111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001010000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000001001110110111;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000010000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test8) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000001;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
}
END_TEST

START_TEST(s21_add_test9) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10010010000001100111100010100101;
  original.bits[1] = 0b10001011011010100100100011011111;
  original.bits[2] = 0b00011100010100011001001100010001;
  original.bits[3] = 0b10000000000100010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
}
END_TEST

START_TEST(s21_add_test10) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11010010000011011110010110111111;
  original.bits[1] = 0b10100111010011100111001000100001;
  original.bits[2] = 0b00011100010100111001110111101101;
  original.bits[3] = 0b10000000000100010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test11) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = 1;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test12) {
  s21_decimal src1, src2, original;
  src1.value_type = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = 1;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_add_test13) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_add(src1, src2);
  original.value_type = 0;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 4294967295;
  original.bits[3] = 0;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test1) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test2) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test3) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test4) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test5) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000110010;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test6) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000011000000010110110011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000111010001110000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000010000110001000101100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 9999999999999999999;
}
END_TEST

START_TEST(s21_sub_test7) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10001001111001111111111111111110;
  original.bits[1] = 0b10001010110001110010001100000100;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = -54896651557845.352654545456455;
  // src2 = 21465;
}
END_TEST

START_TEST(s21_sub_test8) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b01110001100100011000110101000111;
  src1.bits[1] = 0b00001111010011100000001101011111;
  src1.bits[2] = 0b10110001011000010111001000100100;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000101001111011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b01111001010101000000110101000111;
  original.bits[1] = 0b00111001001100010000001100100101;
  original.bits[2] = 0b10110001011000010111001000100101;
  original.bits[3] = 0b10000000000011110000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 68845645467.987654345678987654;
  // src2 = 87654323456.9876545678987653;
}
END_TEST

START_TEST(s21_sub_test9) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b01010100100111010010000110000110;
  src1.bits[1] = 0b00100000110000010111010000110011;
  src1.bits[2] = 0b11011110011100111100100001111111;
  src1.bits[3] = 0b00000000000100100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10011111110010001011011001101110;
  original.bits[1] = 0b11011100110110100011001011010011;
  original.bits[2] = 0b00111100110001100010110001111100;
  original.bits[3] = 0b10000000000100100000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
}
END_TEST

START_TEST(s21_sub_test10) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00001110111111111010100000101010;
  original.bits[1] = 0b00101001110101100000001000110100;
  original.bits[2] = 0b00000000000001011111000010100001;
  original.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
}
END_TEST

START_TEST(s21_sub_test11) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b01011010101111100101111101110011;
  original.bits[1] = 0b00101101001111010011000001101000;
  original.bits[2] = 0b00000100101010001101010101010111;
  original.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test12) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_sub_test13) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_sub(src1, src2);
  original.value_type = 1;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test1) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test2) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000001100100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test3) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000001100100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test4) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000001100100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test5) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test6) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00011100110011110011101011000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test7) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11111111111111111111111111111111;
  original.bits[1] = 0b11111111111111111111111111111111;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
}
END_TEST

START_TEST(s21_mul_test8) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11000110011101000101101010011110;
  original.bits[1] = 0b11111111111111111111111111111111;
  original.bits[2] = 0b00111001100010111010010101100001;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
}
END_TEST

START_TEST(s21_mul_test9) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b01110001110011111110010111001111;
  original.bits[1] = 0b01000100010011101101011110011001;
  original.bits[2] = 0b01011110010101101001110000011100;
  original.bits[3] = 0b00000000000011010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);

  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
}
END_TEST

START_TEST(s21_mul_test10) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00101101101011010001001111000011;
  original.bits[1] = 0b11100101011100100000101001000011;
  original.bits[2] = 0b00001100001010011010000110101010;
  original.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test11) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test12) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test13) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mul_test14) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mul(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test1) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test2) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00001010101010101010101010101011;
  original.bits[1] = 0b00101001011011100000000110010110;
  original.bits[2] = 0b00010101100010101000100110010100;
  original.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test3) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000001111;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test4) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000001111;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test5) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000001111;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test6) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test7) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11001100111001010110111000001001;
  original.bits[1] = 0b01000001100010010010010111001101;
  original.bits[2] = 0b00000000010010001100011000000100;
  original.bits[3] = 0b00000000000110110000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test8) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test9) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111010010101001111101000100000;
  src1.bits[1] = 0b01000010111101001000100110101011;
  src1.bits[2] = 0b00000000001011111000100010010111;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test10) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11001111001110010100110000011011;
  src1.bits[1] = 0b01000101100101010101111100010001;
  src1.bits[2] = 0b00000000000000001010100100011111;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000100110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test11) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test12) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test13) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000101011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000011010000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b01100111011001100111111000100101;
  original.bits[1] = 0b11001001001000001001101010100010;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test14) {
  s21_decimal src1, src2, original;
  src1.value_type = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = 0;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = 1;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_div_test15) {
  s21_decimal src1, src2, original;
  src1.value_type = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = 2;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_div(src1, src2);
  original.value_type = 0;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test1) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test2) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000010;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test3) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test4) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000101101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000100000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000010100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test5) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000101101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000100000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000010100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test6) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10101010000010000011011000010110;
  original.bits[1] = 0b00000000000000000000000000000001;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test7) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10111101010000100101101011101101;
  original.bits[1] = 0b00001001111110101010011110000010;
  original.bits[2] = 0b00000000000000000000000011011001;
  original.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test8) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00001011000011110111000010001101;
  original.bits[1] = 0b10010110101100000101100101010001;
  original.bits[2] = 0b00010001101000010111101110000001;
  original.bits[3] = 0b00000000000111000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test9) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test10) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test11) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test12) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_mod_test13) {
  s21_decimal src1, src2, original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_mod(src1, src2);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_less_test1) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_test2) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_test3) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_test4) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_test5) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_test6) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_test7) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test1) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test2) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test3) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test4) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test5) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test6) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test7) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test8) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test9) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test10) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test11) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test12) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_less_equal_test13) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test1) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test2) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test3) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test4) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test5) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test6) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b01000110001111010001100000000000;
  src2.bits[1] = 0b11010011010011111110100110011101;
  src2.bits[2] = 0b00000000001000111110110110011110;
  src2.bits[3] = 0b00000000000010110000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test7) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test8) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test9) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test10) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test11) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test12) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test13) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_test14) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test1) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000001010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test2) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test3) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test4) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test5) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11011111010000111010111001110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test6) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test7) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test8) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test9) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test10) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test11) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test12) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test13) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test14) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_greater_equal_test15) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test1) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test2) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test3) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test4) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test5) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test6) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test7) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test8) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test9) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test10) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test11) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test12) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test13) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test14) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_equal_test15) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test1) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test2) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test3) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test4) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test5) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test6) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test7) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test8) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test9) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00001000010001000101001100000001;
  src1.bits[1] = 0b01111001100000001001000001110000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test10) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test11) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NORMAL_VALUE;
  src2.bits[0] = 0b11101101000010111011011100101111;
  src2.bits[1] = 0b10110000001111101110110000010010;
  src2.bits[2] = 0b01001100001001001110001100011010;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test12) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NAN;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test13) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NAN;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 0;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test14) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_not_equal_test15) {
  s21_decimal src1, src2;
  int original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.value_type = s21_NEGATIVE_INFINITY;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  original = 1;
  ck_assert_int_eq(original, result);
}
END_TEST

START_TEST(s21_int_to_dec_test1) {
  s21_decimal result, original;
  int src = 1;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_test2) {
  s21_decimal result, original;
  int src = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_test3) {
  s21_decimal result, original;
  int src = -1;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_test4) {
  s21_decimal result, original;
  int src = 3436425;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000001101000110111110001001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_test5) {
  s21_decimal result, original;
  int src = -999;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000001111100111;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test1) {
  float src = 1;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test2) {
  float src = -3;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000011;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test3) {
  float src = 5.289365;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000010100001011010110010101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000001100000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test4) {
  float src = 0.2364752;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000001001000001010101010000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000001110000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test5) {
  float src = 7.34865E+13;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11101000101110100111000100000000;
  original.bits[1] = 0b00000000000000000100001011010101;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test6) {
  float src = INFINITY;
  s21_decimal result = DECIMAL_DEFAULT;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 1;
  s21_decimal original = DECIMAL_DEFAULT;
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test7) {
  float src = NAN;
  s21_decimal result = DECIMAL_DEFAULT;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 1;
  s21_decimal original = DECIMAL_DEFAULT;
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test8) {
  float src = 1.23456e-15;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 1234560;
  original.bits[1] = 0;
  original.bits[2] = 0;
  original.bits[3] = 1376256;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_float_to_dec_test9) {
  float src = 1.23456e-30;
  s21_decimal result, original;
  int my_error = s21_from_float_to_decimal(src, &result);
  int original_error = 0;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0;
  original.bits[1] = 0;
  original.bits[2] = 0;
  original.bits[3] = 0;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test1) {
  s21_decimal src;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int original = 5;
  int original_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test2) {
  s21_decimal src;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int original = 0;
  int original_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test3) {
  s21_decimal src;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int result = 0;
  int original = -2;
  int original_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test4) {
  s21_decimal src;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int original = 65658654;
  int original_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test5) {
  s21_decimal src;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int result = 0;
  int original = -364748;
  int original_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test6) {
  s21_decimal src;
  src.value_type = s21_INFINITY;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int original = 0;
  int original_error = 1;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test7) {
  s21_decimal src;
  src.value_type = s21_NEGATIVE_INFINITY;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int original = 0;
  int original_error = 1;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_int_test8) {
  s21_decimal src;
  src.value_type = s21_NAN;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int original = 0;
  int original_error = 1;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(original, result);
  ck_assert_int_eq(original_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test1) {
  s21_decimal number;
  number.value_type = s21_NORMAL_VALUE;
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  float result_float = -0.8;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test2) {
  s21_decimal number;
  number.value_type = s21_NORMAL_VALUE;
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  float result_float = 0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test3) {
  s21_decimal number;
  number.value_type = s21_NORMAL_VALUE;
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  float result_float = 1;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test4) {
  s21_decimal number;
  number.value_type = s21_NORMAL_VALUE;
  number.bits[0] = 0b00000000000000000001100101111001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  float result_float = 6521;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test5) {
  s21_decimal number;
  number.value_type = s21_NORMAL_VALUE;
  number.bits[0] = 0b01001100110100101000000111000101;
  number.bits[1] = 0b00000000000000000000000000000010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  float result_float = -9878798336;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test7) {
  s21_decimal number;
  number.value_type = s21_INFINITY;
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 1;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test8) {
  s21_decimal number;
  number.value_type = s21_NEGATIVE_INFINITY;
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 1;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_test9) {
  s21_decimal number;
  number.value_type = s21_NAN;
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 1;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_floor_test1) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test2) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000011;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test3) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test4) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000011;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test5) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000001010001100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test6) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test7) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b10110010001111111111110010001001;
  src.bits[1] = 0b00011001111000001100100110111010;
  src.bits[2] = 0b00000000000000000000001000011110;
  src.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11011110100111111111111110100111;
  original.bits[1] = 0b00110101110010011010110111000101;
  original.bits[2] = 0b00000000000000000000000000110110;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test8) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b11011100100001110000101110111001;
  src.bits[1] = 0b00000000000000000000000000001001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test9) {
  s21_decimal src, original;
  src.value_type = s21_INFINITY;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test10) {
  s21_decimal src, original;
  src.value_type = s21_NEGATIVE_INFINITY;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_floor_test11) {
  s21_decimal src, original;
  src.value_type = s21_NAN;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_floor(src);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test1) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test2) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test3) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000010;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test4) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000001010001100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test5) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000011111010011101111100011111;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test6) {
  s21_decimal src, original;
  src.value_type = s21_NORMAL_VALUE;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000101111000110000101001110;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test7) {
  s21_decimal src, original;
  src.value_type = s21_INFINITY;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test8) {
  s21_decimal src, original;
  src.value_type = s21_NEGATIVE_INFINITY;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_round_test9) {
  s21_decimal src, original;
  src.value_type = s21_NAN;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_round(src);
  original.value_type = s21_NAN;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_truncate_test1) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000111001001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_truncate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_truncate_test2) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000011111010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000010;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_truncate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_truncate_test3) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_truncate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_truncate_test4) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10010011100100010011000000000000;
  src1.bits[1] = 0b00100110110100100010010100001001;
  src1.bits[2] = 0b00000000000100011101011101011110;
  src1.bits[3] = 0b10000000000100000000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10000000100011110101101001110011;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = s21_truncate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_truncate_test5) {
  s21_decimal src1, original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_truncate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_truncate_test6) {
  s21_decimal src1, original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_truncate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_negate_test1) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00011011001111010100010001000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00011011001111010100010001000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000001100000000000000000;
  s21_decimal result = s21_negate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_negate_test2) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000110110000000000000000;
  s21_decimal result = s21_negate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_negate_test3) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b11001110100110111101100110011000;
  original.bits[1] = 0b00000001010111101111011100100110;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000001110000000000000000;
  s21_decimal result = s21_negate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_negate_test4) {
  s21_decimal src1, original;
  src1.value_type = s21_NORMAL_VALUE;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  original.value_type = s21_NORMAL_VALUE;
  original.bits[0] = 0b10010001000010101111010011001010;
  original.bits[1] = 0b11000000010001011101010111110010;
  original.bits[2] = 0b00100111111001000001101100000000;
  original.bits[3] = 0b10000000000101010000000000000000;
  s21_decimal result = s21_negate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_negate_test5) {
  s21_decimal src1, original;
  src1.value_type = s21_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  original.value_type = s21_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_negate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

START_TEST(s21_negate_test6) {
  s21_decimal src1, original;
  src1.value_type = s21_NEGATIVE_INFINITY;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  original.value_type = s21_NEGATIVE_INFINITY;
  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = s21_negate(src1);
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
  ck_assert_int_eq(original.value_type, result.value_type);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_add_test1);
  tcase_add_test(tc1_1, s21_add_test2);
  tcase_add_test(tc1_1, s21_add_test3);
  tcase_add_test(tc1_1, s21_add_test4);
  tcase_add_test(tc1_1, s21_add_test5);
  tcase_add_test(tc1_1, s21_add_test6);
  tcase_add_test(tc1_1, s21_add_test7);
  tcase_add_test(tc1_1, s21_add_test8);
  tcase_add_test(tc1_1, s21_add_test9);
  tcase_add_test(tc1_1, s21_add_test10);
  tcase_add_test(tc1_1, s21_add_test11);
  tcase_add_test(tc1_1, s21_add_test12);
  tcase_add_test(tc1_1, s21_add_test13);
  tcase_add_test(tc1_1, s21_sub_test1);
  tcase_add_test(tc1_1, s21_sub_test2);
  tcase_add_test(tc1_1, s21_sub_test3);
  tcase_add_test(tc1_1, s21_sub_test4);
  tcase_add_test(tc1_1, s21_sub_test5);
  tcase_add_test(tc1_1, s21_sub_test6);
  tcase_add_test(tc1_1, s21_sub_test7);
  tcase_add_test(tc1_1, s21_sub_test8);
  tcase_add_test(tc1_1, s21_sub_test9);
  tcase_add_test(tc1_1, s21_sub_test10);
  tcase_add_test(tc1_1, s21_sub_test11);
  tcase_add_test(tc1_1, s21_sub_test12);
  tcase_add_test(tc1_1, s21_sub_test13);
  tcase_add_test(tc1_1, s21_mul_test1);
  tcase_add_test(tc1_1, s21_mul_test2);
  tcase_add_test(tc1_1, s21_mul_test3);
  tcase_add_test(tc1_1, s21_mul_test4);
  tcase_add_test(tc1_1, s21_mul_test5);
  tcase_add_test(tc1_1, s21_mul_test6);
  tcase_add_test(tc1_1, s21_mul_test7);
  tcase_add_test(tc1_1, s21_mul_test8);
  tcase_add_test(tc1_1, s21_mul_test9);
  tcase_add_test(tc1_1, s21_mul_test10);
  tcase_add_test(tc1_1, s21_mul_test11);
  tcase_add_test(tc1_1, s21_mul_test12);
  tcase_add_test(tc1_1, s21_mul_test13);
  tcase_add_test(tc1_1, s21_mul_test14);
  tcase_add_test(tc1_1, s21_div_test1);
  tcase_add_test(tc1_1, s21_div_test2);
  tcase_add_test(tc1_1, s21_div_test3);
  tcase_add_test(tc1_1, s21_div_test4);
  tcase_add_test(tc1_1, s21_div_test5);
  tcase_add_test(tc1_1, s21_div_test6);
  tcase_add_test(tc1_1, s21_div_test7);
  tcase_add_test(tc1_1, s21_div_test8);
  tcase_add_test(tc1_1, s21_div_test9);
  tcase_add_test(tc1_1, s21_div_test10);
  tcase_add_test(tc1_1, s21_div_test11);
  tcase_add_test(tc1_1, s21_div_test12);
  tcase_add_test(tc1_1, s21_div_test13);
  tcase_add_test(tc1_1, s21_div_test14);
  tcase_add_test(tc1_1, s21_div_test15);
  tcase_add_test(tc1_1, s21_mod_test1);
  tcase_add_test(tc1_1, s21_mod_test2);
  tcase_add_test(tc1_1, s21_mod_test3);
  tcase_add_test(tc1_1, s21_mod_test4);
  tcase_add_test(tc1_1, s21_mod_test5);
  tcase_add_test(tc1_1, s21_mod_test6);
  tcase_add_test(tc1_1, s21_mod_test7);
  tcase_add_test(tc1_1, s21_mod_test8);
  tcase_add_test(tc1_1, s21_mod_test9);
  tcase_add_test(tc1_1, s21_mod_test10);
  tcase_add_test(tc1_1, s21_mod_test11);
  tcase_add_test(tc1_1, s21_mod_test12);
  tcase_add_test(tc1_1, s21_mod_test13);
  tcase_add_test(tc1_1, s21_less_test1);
  tcase_add_test(tc1_1, s21_less_test2);
  tcase_add_test(tc1_1, s21_less_test3);
  tcase_add_test(tc1_1, s21_less_test4);
  tcase_add_test(tc1_1, s21_less_test5);
  tcase_add_test(tc1_1, s21_less_test6);
  tcase_add_test(tc1_1, s21_less_test7);
  tcase_add_test(tc1_1, s21_less_equal_test1);
  tcase_add_test(tc1_1, s21_less_equal_test2);
  tcase_add_test(tc1_1, s21_less_equal_test3);
  tcase_add_test(tc1_1, s21_less_equal_test4);
  tcase_add_test(tc1_1, s21_less_equal_test5);
  tcase_add_test(tc1_1, s21_less_equal_test6);
  tcase_add_test(tc1_1, s21_less_equal_test7);
  tcase_add_test(tc1_1, s21_less_equal_test8);
  tcase_add_test(tc1_1, s21_less_equal_test9);
  tcase_add_test(tc1_1, s21_less_equal_test10);
  tcase_add_test(tc1_1, s21_less_equal_test11);
  tcase_add_test(tc1_1, s21_less_equal_test12);
  tcase_add_test(tc1_1, s21_less_equal_test13);
  tcase_add_test(tc1_1, s21_greater_test1);
  tcase_add_test(tc1_1, s21_greater_test2);
  tcase_add_test(tc1_1, s21_greater_test3);
  tcase_add_test(tc1_1, s21_greater_test4);
  tcase_add_test(tc1_1, s21_greater_test5);
  tcase_add_test(tc1_1, s21_greater_test6);
  tcase_add_test(tc1_1, s21_greater_test7);
  tcase_add_test(tc1_1, s21_greater_test8);
  tcase_add_test(tc1_1, s21_greater_test9);
  tcase_add_test(tc1_1, s21_greater_test10);
  tcase_add_test(tc1_1, s21_greater_test11);
  tcase_add_test(tc1_1, s21_greater_test12);
  tcase_add_test(tc1_1, s21_greater_test13);
  tcase_add_test(tc1_1, s21_greater_test14);
  tcase_add_test(tc1_1, s21_greater_equal_test1);
  tcase_add_test(tc1_1, s21_greater_equal_test2);
  tcase_add_test(tc1_1, s21_greater_equal_test3);
  tcase_add_test(tc1_1, s21_greater_equal_test4);
  tcase_add_test(tc1_1, s21_greater_equal_test5);
  tcase_add_test(tc1_1, s21_greater_equal_test6);
  tcase_add_test(tc1_1, s21_greater_equal_test7);
  tcase_add_test(tc1_1, s21_greater_equal_test8);
  tcase_add_test(tc1_1, s21_greater_equal_test9);
  tcase_add_test(tc1_1, s21_greater_equal_test10);
  tcase_add_test(tc1_1, s21_greater_equal_test11);
  tcase_add_test(tc1_1, s21_greater_equal_test12);
  tcase_add_test(tc1_1, s21_greater_equal_test13);
  tcase_add_test(tc1_1, s21_greater_equal_test14);
  tcase_add_test(tc1_1, s21_greater_equal_test15);
  tcase_add_test(tc1_1, s21_equal_test1);
  tcase_add_test(tc1_1, s21_equal_test2);
  tcase_add_test(tc1_1, s21_equal_test3);
  tcase_add_test(tc1_1, s21_equal_test4);
  tcase_add_test(tc1_1, s21_equal_test5);
  tcase_add_test(tc1_1, s21_equal_test6);
  tcase_add_test(tc1_1, s21_equal_test7);
  tcase_add_test(tc1_1, s21_equal_test8);
  tcase_add_test(tc1_1, s21_equal_test9);
  tcase_add_test(tc1_1, s21_equal_test10);
  tcase_add_test(tc1_1, s21_equal_test11);
  tcase_add_test(tc1_1, s21_equal_test12);
  tcase_add_test(tc1_1, s21_equal_test13);
  tcase_add_test(tc1_1, s21_equal_test14);
  tcase_add_test(tc1_1, s21_equal_test15);
  tcase_add_test(tc1_1, s21_not_equal_test1);
  tcase_add_test(tc1_1, s21_not_equal_test2);
  tcase_add_test(tc1_1, s21_not_equal_test3);
  tcase_add_test(tc1_1, s21_not_equal_test4);
  tcase_add_test(tc1_1, s21_not_equal_test5);
  tcase_add_test(tc1_1, s21_not_equal_test6);
  tcase_add_test(tc1_1, s21_not_equal_test7);
  tcase_add_test(tc1_1, s21_not_equal_test8);
  tcase_add_test(tc1_1, s21_not_equal_test9);
  tcase_add_test(tc1_1, s21_not_equal_test10);
  tcase_add_test(tc1_1, s21_not_equal_test11);
  tcase_add_test(tc1_1, s21_not_equal_test12);
  tcase_add_test(tc1_1, s21_not_equal_test13);
  tcase_add_test(tc1_1, s21_not_equal_test14);
  tcase_add_test(tc1_1, s21_not_equal_test15);
  tcase_add_test(tc1_1, s21_int_to_dec_test1);
  tcase_add_test(tc1_1, s21_int_to_dec_test2);
  tcase_add_test(tc1_1, s21_int_to_dec_test3);
  tcase_add_test(tc1_1, s21_int_to_dec_test4);
  tcase_add_test(tc1_1, s21_int_to_dec_test5);
  tcase_add_test(tc1_1, s21_float_to_dec_test1);
  tcase_add_test(tc1_1, s21_float_to_dec_test2);
  tcase_add_test(tc1_1, s21_float_to_dec_test3);
  tcase_add_test(tc1_1, s21_float_to_dec_test4);
  tcase_add_test(tc1_1, s21_float_to_dec_test5);
  tcase_add_test(tc1_1, s21_float_to_dec_test6);
  tcase_add_test(tc1_1, s21_float_to_dec_test7);
  tcase_add_test(tc1_1, s21_float_to_dec_test8);
  tcase_add_test(tc1_1, s21_float_to_dec_test9);
  tcase_add_test(tc1_1, s21_dec_to_int_test1);
  tcase_add_test(tc1_1, s21_dec_to_int_test2);
  tcase_add_test(tc1_1, s21_dec_to_int_test3);
  tcase_add_test(tc1_1, s21_dec_to_int_test4);
  tcase_add_test(tc1_1, s21_dec_to_int_test5);
  tcase_add_test(tc1_1, s21_dec_to_int_test6);
  tcase_add_test(tc1_1, s21_dec_to_int_test7);
  tcase_add_test(tc1_1, s21_dec_to_int_test8);
  tcase_add_test(tc1_1, s21_dec_to_float_test1);
  tcase_add_test(tc1_1, s21_dec_to_float_test2);
  tcase_add_test(tc1_1, s21_dec_to_float_test3);
  tcase_add_test(tc1_1, s21_dec_to_float_test4);
  tcase_add_test(tc1_1, s21_dec_to_float_test5);
  tcase_add_test(tc1_1, s21_dec_to_float_test7);
  tcase_add_test(tc1_1, s21_dec_to_float_test8);
  tcase_add_test(tc1_1, s21_dec_to_float_test9);
  tcase_add_test(tc1_1, s21_floor_test1);
  tcase_add_test(tc1_1, s21_floor_test2);
  tcase_add_test(tc1_1, s21_floor_test3);
  tcase_add_test(tc1_1, s21_floor_test4);
  tcase_add_test(tc1_1, s21_floor_test5);
  tcase_add_test(tc1_1, s21_floor_test6);
  tcase_add_test(tc1_1, s21_floor_test7);
  tcase_add_test(tc1_1, s21_floor_test8);
  tcase_add_test(tc1_1, s21_floor_test9);
  tcase_add_test(tc1_1, s21_floor_test10);
  tcase_add_test(tc1_1, s21_floor_test11);
  tcase_add_test(tc1_1, s21_round_test1);
  tcase_add_test(tc1_1, s21_round_test2);
  tcase_add_test(tc1_1, s21_round_test3);
  tcase_add_test(tc1_1, s21_round_test4);
  tcase_add_test(tc1_1, s21_round_test5);
  tcase_add_test(tc1_1, s21_round_test6);
  tcase_add_test(tc1_1, s21_round_test7);
  tcase_add_test(tc1_1, s21_round_test8);
  tcase_add_test(tc1_1, s21_round_test9);
  tcase_add_test(tc1_1, s21_truncate_test1);
  tcase_add_test(tc1_1, s21_truncate_test2);
  tcase_add_test(tc1_1, s21_truncate_test3);
  tcase_add_test(tc1_1, s21_truncate_test4);
  tcase_add_test(tc1_1, s21_truncate_test5);
  tcase_add_test(tc1_1, s21_truncate_test6);
  tcase_add_test(tc1_1, s21_negate_test1);
  tcase_add_test(tc1_1, s21_negate_test2);
  tcase_add_test(tc1_1, s21_negate_test3);
  tcase_add_test(tc1_1, s21_negate_test4);
  tcase_add_test(tc1_1, s21_negate_test5);
  tcase_add_test(tc1_1, s21_negate_test6);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
