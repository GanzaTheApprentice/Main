#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input();
void fill_sort_output(int x);
int random_length(int *length, int x, int r_num);
int check_length(int *length, int x);
void sort(int **arr, int i, int y);
void output(int **arr, int i, int y);

int main(void) {
  fill_sort_output(input());
}

void fill_sort_output(int x) {
  int **arr, length[x], y = 0, z = 0;
  arr = (int **)calloc(x, sizeof(*arr));
  srand(time(NULL));

  while (!y) {
    z = random_length(length, x, rand());
    y = check_length(length, x);
    srand(z);
  }

  for (int i = 0; i < x; i++) {
    arr[i] = (int *)calloc(length[i], sizeof(*arr[i]));
    for (int j = 0; j < length[i]; j++) {
      arr[i][j] = (rand() % 100 + 1);
    }
    sort(arr, i, length[i]);
    output(arr, i, length[i]);
  }

  for (int i = 0; i < x; i++) {
    free(arr[i]);
  }
  free(arr);
}

int random_length(int *length, int x, int r_num) {
  for (int i = 0; i < x; i++) {
    length[i] = (rand() % 50 + 1);
    srand(length[i] + r_num);
  }
  return rand();
}

int check_length(int *length, int x) {
  int flag = 1;
  for (int i = 0; i < x; i++) {
    for (int j = i + 1; j < x; j++) {
      if (length[i] == length[j]) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}

void sort(int **arr, int i, int y) {
  int buf;
  if (i % 2 != 0) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < y; k++) {
        if (arr[i][j] > arr[i][k]) {
          buf = arr[i][j];
          arr[i][j] = arr[i][k];
          arr[i][k] = buf;
        }
      }
    }
  } else {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < y; k++) {
        if (arr[i][j] < arr[i][k]) {
          buf = arr[i][j];
          arr[i][j] = arr[i][k];
          arr[i][k] = buf;
        }
      }
    }
  }
}

void output(int **arr, int i, int y) {
  printf("%d) ", i);
  for (int j = 0; j < y; j++) {
    printf("%d ", arr[i][j]);
  }
  printf("\n");
}

int input() {
  int x = 0;
  while (x <= 0 || x > 20) {
    printf("Введите число: ");
    scanf("%d", &x);
    if (x > 20) {
      printf(
          "\n[Ошибка]\nПожалуйста введите число не более 20.\n"
          "Число ограничено с целью ускорения работы программы\n"
          "и более читаемого вывода.\n\n");
    }
    if (x <= 0) {
      printf("\n[Ошибка]\nНекорректный ввод\n\n");
      exit(1);
    }
  }
  return x;
}
