#include "s21_matrix.h"

matrix_t s21_create_matrix(int rows, int columns) {
  matrix_t result;
  result.rows = rows;
  result.columns = columns;
  result.matrix_type = ZERO_MATRIX;
  result.matrix = (double **)calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result.matrix[i] = (double *)calloc(columns, sizeof(double *));
  }
  if (rows < 1 || columns < 1) {
    result.matrix_type = INCORRECT_MATRIX;
  }
  return result;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = 1;
  matrix_t tmp;

  if (!eq_index(*A, *B)) {
    flag = 0;
  } else {
    tmp = s21_sub_matrix(A, B);
    if (!its_zero(tmp)) {
      flag = 0;
    }
    s21_remove_matrix(&tmp);
  }
  return flag;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
  matrix_t result;
  result = s21_create_matrix(A->rows, A->columns);
  if (!eq_index(*A, *B)) {
    result.matrix_type = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.columns; j++) {
        result.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
    set_type(&result);
  }
  return result;
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
  matrix_t result, tmp;
  tmp = s21_mult_number(B, -1);
  if (!eq_index(*A, *B)) {
    result = s21_create_matrix(A->rows, A->columns);
    result.matrix_type = INCORRECT_MATRIX;
  } else {
    result = s21_sum_matrix(A, &tmp);
    set_type(&result);
  }
  s21_remove_matrix(&tmp);
  return result;
}

matrix_t s21_mult_number(matrix_t *A, double number) {
  matrix_t result;
  result = s21_create_matrix(A->rows, A->columns);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      result.matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  set_type(&result);

  return result;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
  matrix_t result;
  result = s21_create_matrix(A->rows, B->columns);
  if (A->columns != B->rows) {
    result.matrix_type = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < B->rows; k++) {
          result.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
    set_type(&result);
  }
  return result;
}

matrix_t s21_transpose(matrix_t *A) {
  matrix_t result;
  result = s21_create_matrix(A->columns, A->rows);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      result.matrix[i][j] = A->matrix[j][i];
    }
  }
  set_type(&result);
  return result;
}

matrix_t s21_calc_complements(matrix_t *A) {
  matrix_t result, tmp;
  result = s21_create_matrix(A->columns, A->rows);
  if (quad_mtrx(*A) && A->rows > 1) {
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.columns; j++) {
        tmp = addition(*A, i, j);
        result.matrix[i][j] = pew(i + j) * s21_determinant(&tmp);
        s21_remove_matrix(&tmp);
      }
    }
    set_type(&result);
  } else {
    result.matrix_type = INCORRECT_MATRIX;
  }
  return result;
}

double s21_determinant(matrix_t *A) {
  matrix_t tmp;
  double result = 0;
  if (quad_mtrx(*A)) {
    if (A->rows == 2) {
      result = A->matrix[0][0] * A->matrix[1][1];
      result -= A->matrix[1][0] * A->matrix[0][1];
    } else if (A->rows == 1) {
      result = A->matrix[0][0];
    } else {
      for (int i = 0; i < A->rows; i++) {
        tmp = addition(*A, 0, i);
        result += A->matrix[0][i] * pew(0 + i) * s21_determinant(&tmp);
        s21_remove_matrix(&tmp);
      }
    }
  } else {
    result = NANI;
  }
  return result;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
  matrix_t result;
  result = s21_create_matrix(A->columns, A->rows);
  if (quad_mtrx(*A) && A->rows > 1) {
    double dt;
    dt = s21_determinant(A);
    if (dt != 0) {
      dt = 1 / dt;
      matrix_t tmp1, tmp2, tmp3;
      tmp1 = s21_calc_complements(A);
      tmp2 = s21_transpose(&tmp1);
      tmp3 = s21_mult_number(&tmp2, dt);
      for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.columns; j++) {
          result.matrix[i][j] = tmp3.matrix[i][j];
        }
      }
      s21_remove_matrix(&tmp1);
      s21_remove_matrix(&tmp2);
      s21_remove_matrix(&tmp3);
      set_type(&result);
    } else {
      result.matrix_type = INCORRECT_MATRIX;
    }
  } else {
    result.matrix_type = INCORRECT_MATRIX;
  }
  return result;
}

matrix_t addition(matrix_t A, int m, int n) {
  matrix_t result;
  result = s21_create_matrix(A.rows - 1, A.columns - 1);
  int x = 0, y = 0;
  for (int i = 0; i < A.rows; i++) {
    if (i != m) {
      for (int j = 0; j < A.columns; j++) {
        if (j != n) {
          result.matrix[x][y] = A.matrix[i][j];
          y++;
        }
      }
      y = 0;
      x++;
    }
  }
  set_type(&result);
  return result;
}

void set_type(matrix_t *A) {
  if (zero_mtrx(*A)) {
    A->matrix_type = ZERO_MATRIX;
  } else if (quad_mtrx(*A) && identity_mtrx(*A)) {
    A->matrix_type = IDENTITY_MATRIX;
  } else {
    A->matrix_type = CORRECT_MATRIX;
  }
}

int identity_mtrx(matrix_t A) {
  int flag = 1;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (i == j && A.matrix[i][j] != 1) {
        flag = 0;
        break;
      }
      if (i != j && A.matrix[i][j] != 0) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}

int zero_mtrx(matrix_t A) {
  int flag = 1;
  for (int i = 0; i < A.rows && flag; i++) {
    for (int j = 0; j < A.columns && flag; j++) {
      if (A.matrix[i][j] != 0) {
        flag = 0;
      }
    }
  }
  return flag;
}

int quad_mtrx(matrix_t A) {
  int flag = 1;
  if (A.rows != A.columns) flag = 0;
  return flag;
}

int eq_index(matrix_t A, matrix_t B) {
  int flag = 1;
  if (A.rows != B.rows || A.columns != B.columns) {
    flag = 0;
  }
  return flag;
}

int its_zero(matrix_t A) {
  int flag = 1;
  for (int i = 0; i < A.rows && flag; i++) {
    for (int j = 0; j < A.columns && flag; j++) {
      A.matrix[i][j] *= 10000000;
      if ((int)A.matrix[i][j] != 0) {
        flag = 0;
      }
    }
  }
  return flag;
}

double pew(int y) {
  double x = 1;
  while (y) {
    x *= -1;
    y--;
  }
  return x;
}
