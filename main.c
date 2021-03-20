#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int** arr, int length) {
  for (int j = 0; j < 9; j++) {
      if (arr[0][j] > arr[0][j +1]){
          swap(&arr[0][j], &arr[0][j + 1]);
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

void fillExample(int** array) {
  *((*(array + 0)) + 0) = 2;
  *((*(array + 0)) + 1) = 8;
  *((*(array + 0)) + 2) = 5;
  *((*(array + 1)) + 0) = 4;
  *((*(array + 1)) + 1) = 9;
  *((*(array + 1)) + 2) = 6;
  *((*(array + 2)) + 0) = 1;
  *((*(array + 2)) + 1) = 7;
  *((*(array + 2)) + 2) = 3;
}

int main()
{
  int** arr = init2dIntArray(3, 3);


  fillExample(arr);
  print2dIntArray(arr, 6, 3);

  swap((*(arr + 0)) + 2, (*(arr + 0)) + 0);

  print2dIntArray(arr, 3, 3);

  return 0;
}
