#include <stdio.h>
#include <stdlib.h>

int input();
void fill_sort_output(int x);
void sort(int **arr, int i, int y);
void output(int **arr, int i, int y);

int main(void) {
  fill_sort_output(input());
}

int input() {
  printf("Кол-во массивов: ");
  int x = 0;
  scanf("%d", &x);
  return x;
}

void fill_sort_output(int x) {
  int **arr, y;
  arr = (int **)calloc(x, sizeof(*arr));
  for (int i = 0; i < x; i++) {
    y = (rand() % 30 + 1);
    srand(i);
    arr[i] = (int *)calloc(y, sizeof(*arr[i]));
    for (int j = 0; j < y; j++) {
      arr[i][j] = (rand() % 100 + 1);
    }
    sort(arr, i, y);
    output(arr, i, y);
  }
  for (int i = 0; i < x; i++) {
    free(arr[i]);
  }
  free(arr);
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
