#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int** arr, int cols, int rows) {
  for (int k = 0; k < cols * rows; k++) {//проход по всем элементам строки
      for (int i = 0; i < rows; i ++) {
          for (int j = 0; j < cols; j++) {
              if (i == rows - 1 && j == cols -1) {
                  continue;
                }
              else if (j == cols - 1) {
                  if (arr[i][j] > arr [i + 1][0]) {
                      swap(&arr[i][j], &arr[i + 1][0]);
                    }
                }
              else {
                  if (arr[i][j] > arr [i][j + 1]) {
                      swap(&arr[i][j], &arr[i][j + 1]);
                    }
                }
            }
        }
    }
}

void print2dIntArray(int** array, int cols, int rows) {
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          printf("%2d", *((*(array + i)) + j));
        }
      printf("\n");
    }
  printf("\n");
}

int** init2dIntArray(const int cols, const int rows) {
  int** array = (int**) calloc(sizeof(int*), rows);
  for (int i = 0; i < rows; i++) {
      *(array + i) = (int*) calloc(sizeof (int), cols);
    }
  return array;
}

void fillExample(int** array, int rows, int cols) {
  srand(time(NULL));
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          *((*(array + i)) + j) = rand() % 10;
        }
    }
}

int main()
{
  const int cols = 3;
  const int rows = 3;

  int** arr = init2dIntArray(cols, rows);


  fillExample(arr, cols, rows);
  print2dIntArray(arr, cols, rows);

  bubbleSort(arr, cols, rows);
  print2dIntArray(arr, cols, rows);

  return 0;
}
