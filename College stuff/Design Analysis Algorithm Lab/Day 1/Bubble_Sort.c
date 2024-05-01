#include <stdio.h>

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1); // Corrected this line
      }
    }
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[5];
  printf("-----Enter array elements: -----\n");
  for (int x = 0; x < 5; x++) {
    printf("Enter %d: ", x + 1);
    if (scanf("%d", &arr[x]) != 1) {
      printf("Error reading input. Exiting.\n");
      return 1;
    }
  }
  int N = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, N);

  printf("Sorted array: ");
  printArray(arr, N);

  return 0;
}
