#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//01. пузырьковая сортировка двумерного массива
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

//02. алгоритм Трабба-Прадо-Кнута
void print1dIntArray(int* array, int length) {
  for (int i = 0; i < length; i++) {
      printf("%4d%s", array[i], (i == length - 1 ? "\n" : ""));
    }
}

void mirror1dIntArray(int* array, int length) {
  for (int i = 0; i < length / 2; i++) {
      int t = 0;
      t = array[i];
      array[i] = array[(length - 1) - i];
      array[(length - 1) - i] = t;
    }

}

void T_P_K(){
  const int LENGTH = 11;
  int array[LENGTH];

  for (int i = 0; i < LENGTH; i++) {
      scanf("%d", &array[i]);
      fflush(stdin);
    }

  print1dIntArray(array, LENGTH);

  mirror1dIntArray(array,LENGTH);

  print1dIntArray(array, LENGTH);

  printf("\n");

  for (int i = 0; i < LENGTH; i++) {
      if (sqrt(fabs((float)array[i]) + 5 * pow(array[i], 3)) > 400) {
          printf(" NAN");
        }
      else {
          printf(" %2.1f %s", sqrt(fabs((float)array[i]) + 5 * pow(array[i], 3)), (i == LENGTH - 1 ? "\n" : ""));
        }
    }
}

int main()
{
//01. пузырьковая сортировка двумерного массива
  const int cols = 3;
  const int rows = 3;

  int** arr = init2dIntArray(cols, rows);

  fillExample(arr, cols, rows);
  print2dIntArray(arr, cols, rows);
  bubbleSort(arr, cols, rows);
  print2dIntArray(arr, cols, rows);

//02. алгоритм Трабба-Прадо-Кнута
  T_P_K();

  return 0;
}
