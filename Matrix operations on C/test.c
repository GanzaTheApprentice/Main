#include <check.h>

#include "s21_matrix.h"

START_TEST(create_01) {
  matrix_t A;
  int rows = 4, columns = 2;
  A = s21_create_matrix(rows, columns);
  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) ck_assert_uint_eq(A.matrix[i][j], 0.0);
  ck_assert_int_eq(A.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_02) {
  matrix_t A;
  int rows = 0, columns = 0;
  A = s21_create_matrix(rows, columns);
  ck_assert_int_eq(A.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(equal_01) {
  matrix_t A;
  matrix_t B;
  A = s21_create_matrix(3, 3);
  B = s21_create_matrix(3, 3);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_02) {
  matrix_t A;
  matrix_t B;
  A = s21_create_matrix(2, 4);
  B = s21_create_matrix(3, 3);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_03) {
  matrix_t A;
  matrix_t B;
  A = s21_create_matrix(3, 3);
  B = s21_create_matrix(3, 3);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (i + i) * (j + j);
    }
  }
  A.matrix_type = CORRECT_MATRIX;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_04) {
  matrix_t A;
  matrix_t B;
  A = s21_create_matrix(4, 4);
  B = s21_create_matrix(4, 4);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 2.11111113333;
    }
  }
  A.matrix_type = CORRECT_MATRIX;
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 2.1111111;
    }
  }
  B.matrix_type = CORRECT_MATRIX;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(equal_05) {
  matrix_t A;
  matrix_t B;
  A = s21_create_matrix(3, 3);
  B = s21_create_matrix(3, 3);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 2.1111111;
    }
  }
  A.matrix_type = CORRECT_MATRIX;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      B.matrix[i][j] = 2.11111113333;
    }
  }
  B.matrix_type = CORRECT_MATRIX;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_01) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(2, 3);
  B = s21_create_matrix(2, 3);
  C = s21_sum_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sum_02) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(3, 2);
  B = s21_create_matrix(2, 3);
  C = s21_sum_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sum_03) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(2, 2);
  B = s21_create_matrix(2, 2);
  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix_type = CORRECT_MATRIX;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 0.0;
  B.matrix_type = CORRECT_MATRIX;
  C = s21_sum_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, IDENTITY_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sum_04) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double true_result[] = {0.0, 4.0, 7.0, 14.0};
  A = s21_create_matrix(2, 2);
  B = s21_create_matrix(2, 2);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 12.0;
  A.matrix_type = CORRECT_MATRIX;
  B.matrix[0][0] = -1.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 2.0;
  B.matrix_type = CORRECT_MATRIX;
  C = s21_sum_matrix(&A, &B);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_uint_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sub_01) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(2, 3);
  B = s21_create_matrix(2, 3);
  C = s21_sub_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sub_02) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(3, 2);
  B = s21_create_matrix(2, 3);
  C = s21_sub_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sub_03) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(2, 2);
  B = s21_create_matrix(2, 2);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 2.0;
  A.matrix_type = CORRECT_MATRIX;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 1.0;
  B.matrix_type = CORRECT_MATRIX;
  C = s21_sub_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, IDENTITY_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(sub_04) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double true_result[] = {2.0, -8.0, 1.0, 10.0};
  A = s21_create_matrix(2, 2);
  B = s21_create_matrix(2, 2);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 12.0;
  A.matrix_type = CORRECT_MATRIX;
  B.matrix[0][0] = -1.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 2.0;
  B.matrix_type = CORRECT_MATRIX;
  C = s21_sub_matrix(&A, &B);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_uint_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_number_01) {
  matrix_t A;
  matrix_t C;
  double number = 12.12;
  A = s21_create_matrix(2, 3);
  C = s21_mult_number(&A, number);
  ck_assert_int_eq(C.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_number_02) {
  matrix_t A;
  matrix_t C;
  double number = 2.00;
  A = s21_create_matrix(2, 2);
  A.matrix[0][0] = 0.5;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.5;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_mult_number(&A, number);
  ck_assert_int_eq(C.matrix_type, IDENTITY_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_number_03) {
  matrix_t A;
  matrix_t C;
  double true_result[] = {5.0, -6.0, 4.5, 1.0};
  double number = 2.00;
  A = s21_create_matrix(2, 2);
  A.matrix[0][0] = 2.5;
  A.matrix[0][1] = -3.0;
  A.matrix[1][0] = 2.25;
  A.matrix[1][1] = 0.5;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_mult_number(&A, number);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_uint_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_01) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(2, 3);
  B = s21_create_matrix(3, 2);
  C = s21_mult_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_02) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(3, 4);
  B = s21_create_matrix(2, 3);
  C = s21_mult_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_03) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  A = s21_create_matrix(2, 2);
  B = s21_create_matrix(2, 2);
  A.matrix[0][0] = 0.5;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.5;
  A.matrix_type = CORRECT_MATRIX;
  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 2.0;
  B.matrix_type = CORRECT_MATRIX;
  C = s21_mult_matrix(&A, &B);
  ck_assert_int_eq(C.matrix_type, IDENTITY_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(mult_04) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double true_result[] = {10.0, 8.0, 4.75, 24.5};
  A = s21_create_matrix(2, 3);
  B = s21_create_matrix(3, 2);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = -1.0;
  A.matrix_type = CORRECT_MATRIX;
  B.matrix[0][0] = -1.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 2.0;
  B.matrix[2][0] = 4.25;
  B.matrix[2][1] = 1.5;
  B.matrix_type = CORRECT_MATRIX;
  C = s21_mult_matrix(&A, &B);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_int_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_01) {
  matrix_t A;
  matrix_t C;
  A = s21_create_matrix(2, 3);
  C = s21_transpose(&A);
  ck_assert_int_eq(C.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_02) {
  matrix_t A;
  matrix_t C;
  A = s21_create_matrix(2, 2);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix_type = IDENTITY_MATRIX;
  C = s21_transpose(&A);
  ck_assert_int_eq(C.matrix_type, IDENTITY_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_03) {
  matrix_t A;
  matrix_t C;
  double true_result[] = {1.0, 4.0, 2.0, 5.0, 3, 6};
  A = s21_create_matrix(2, 3);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_transpose(&A);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_uint_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(calc_complements_01) {
  matrix_t A;
  matrix_t C;
  A = s21_create_matrix(3, 3);
  C = s21_calc_complements(&A);
  ck_assert_int_eq(C.matrix_type, ZERO_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(calc_complements_02) {
  matrix_t A;
  matrix_t C;
  A = s21_create_matrix(1, 4);
  C = s21_calc_complements(&A);
  ck_assert_int_eq(C.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(calc_complements_03) {
  matrix_t A;
  matrix_t C;
  double true_result[] = {-1, 38, -27, 1, -41, 29, -1, 34, -24};
  A = s21_create_matrix(3, 3);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_calc_complements(&A);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_int_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(calc_complements_04) {
  matrix_t A;
  matrix_t C;
  double true_result[] = {63,  64,  -60, -2, -16, -88, 66,  2,
                          -24, -18, 12,  30, 14,  116, -36, -31};
  A = s21_create_matrix(4, 4);
  A.matrix[0][0] = 4.0;
  A.matrix[0][1] = 1.0;
  A.matrix[0][2] = 2.2;
  A.matrix[0][3] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 2.0;
  A.matrix[1][2] = 6.3;
  A.matrix[1][3] = 2.0;
  A.matrix[2][0] = 1.0;
  A.matrix[2][1] = 3.0;
  A.matrix[2][2] = 4.0;
  A.matrix[2][3] = 7.0;
  A.matrix[3][0] = 1.0;
  A.matrix[3][1] = 3.0;
  A.matrix[3][2] = 4.24;
  A.matrix[3][3] = 1.0;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_calc_complements(&A);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_int_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_int_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(determinant_01) {
  matrix_t A;
  double determinate = 0;
  A = s21_create_matrix(3, 3);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  A.matrix_type = CORRECT_MATRIX;
  determinate = s21_determinant(&A);
  ck_assert_double_eq(determinate, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_02) {
  matrix_t A;
  double determinate = 0;
  A = s21_create_matrix(1, 1);
  A.matrix[0][0] = 1.0;
  A.matrix_type = CORRECT_MATRIX;
  determinate = s21_determinant(&A);
  ck_assert_double_eq(determinate, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_03) {
  matrix_t A;
  double determinate = 0;
  A = s21_create_matrix(5, 5);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;
  A.matrix[0][4] = -5.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 7.0;
  A.matrix[1][2] = -8.0;
  A.matrix[1][3] = 9.0;
  A.matrix[1][4] = 10.0;
  A.matrix[2][0] = -11.0;
  A.matrix[2][1] = 12.0;
  A.matrix[2][2] = 13.0;
  A.matrix[2][3] = -14.0;
  A.matrix[2][4] = 15.0;
  A.matrix[3][0] = -16.0;
  A.matrix[3][1] = 2.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = -19.0;
  A.matrix[3][4] = 20.0;
  A.matrix[4][0] = -21.0;
  A.matrix[4][1] = -1.0;
  A.matrix[4][2] = 23.0;
  A.matrix[4][3] = -24.0;
  A.matrix[4][4] = 2.0;
  A.matrix_type = CORRECT_MATRIX;
  determinate = s21_determinant(&A);
  ck_assert_double_eq(determinate, -2250);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_01) {
  matrix_t A;
  matrix_t C;
  A = s21_create_matrix(3, 3);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_inverse_matrix(&A);
  ck_assert_double_eq(C.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_02) {
  matrix_t A;
  matrix_t C;
  A = s21_create_matrix(2, 3);
  C = s21_inverse_matrix(&A);
  ck_assert_double_eq(C.matrix_type, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_03) {
  matrix_t A;
  matrix_t C;
  double true_result[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  A = s21_create_matrix(3, 3);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  A.matrix_type = CORRECT_MATRIX;
  C = s21_inverse_matrix(&A);
  for (int i = 0, k = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      ck_assert_uint_eq(C.matrix[i][j], true_result[k]);
      k += 1;
    }
  }
  ck_assert_double_eq(C.matrix_type, CORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("All inclusive");
  SRunner *sr = srunner_create(s1);
  int nf;

  TCase *tc1_1 = tcase_create("All inclusive");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_01);
  tcase_add_test(tc1_1, create_02);
  tcase_add_test(tc1_1, equal_01);
  tcase_add_test(tc1_1, equal_02);
  tcase_add_test(tc1_1, equal_03);
  tcase_add_test(tc1_1, equal_04);
  tcase_add_test(tc1_1, equal_05);
  tcase_add_test(tc1_1, sum_01);
  tcase_add_test(tc1_1, sum_02);
  tcase_add_test(tc1_1, sum_03);
  tcase_add_test(tc1_1, sum_04);
  tcase_add_test(tc1_1, sub_01);
  tcase_add_test(tc1_1, sub_02);
  tcase_add_test(tc1_1, sub_03);
  tcase_add_test(tc1_1, sub_04);
  tcase_add_test(tc1_1, mult_number_01);
  tcase_add_test(tc1_1, mult_number_02);
  tcase_add_test(tc1_1, mult_number_03);
  tcase_add_test(tc1_1, mult_01);
  tcase_add_test(tc1_1, mult_02);
  tcase_add_test(tc1_1, mult_03);
  tcase_add_test(tc1_1, mult_04);
  tcase_add_test(tc1_1, transpose_01);
  tcase_add_test(tc1_1, transpose_02);
  tcase_add_test(tc1_1, transpose_03);
  tcase_add_test(tc1_1, calc_complements_01);
  tcase_add_test(tc1_1, calc_complements_02);
  tcase_add_test(tc1_1, calc_complements_03);
  tcase_add_test(tc1_1, calc_complements_04);
  tcase_add_test(tc1_1, determinant_01);
  tcase_add_test(tc1_1, determinant_02);
  tcase_add_test(tc1_1, determinant_03);
  tcase_add_test(tc1_1, inverse_01);
  tcase_add_test(tc1_1, inverse_02);
  tcase_add_test(tc1_1, inverse_03);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
