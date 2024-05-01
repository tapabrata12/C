#include <stdio.h>
#define n 5
int arr[n];
void Insertion_Sort();
int main(void) {

  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
  Insertion_Sort();

  printf("Sorted array will be:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

void Insertion_Sort() {
  int temp;
  for (int j = 0; j < n; j++) {
    int k = j;
    while (k > 0 && arr[k] < arr[k - 1]) {
      temp = arr[k];
      arr[k] = arr[k - 1];
      arr[k - 1] = temp;
      k--;
    }
  }
}
