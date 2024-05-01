#include <stdio.h>
#define n 5
int arr[n];

void QuickSort(int low, int high);
int Partition(int low, int high);

int main(void) {

  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  QuickSort(0, n - 1);
  printf("Sorted array will be:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

void QuickSort(int low, int high) {
  if (low < high) {
    int PartionIndex = Partition(low, high);
    QuickSort(low, PartionIndex - 1);
    QuickSort(PartionIndex + 1, high);
  }
}

int Partition(int low, int high) {
  int temp;
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {

    while (arr[i] <= pivot && i <= high) {
      i++;
    }
    while (arr[j] > pivot && j >= low) {
      j--;
    }
    if (i < j) { // This condition when i crosses over j then we don't want to
                 // execute it
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;
  return j;
}
