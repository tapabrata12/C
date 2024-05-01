// W.A.P to multiply 2X2 matrix
#include <stdio.h>

int arr1[2][2], arr2[2][2], Add[2][2], Mul[2][2];

void add();
void mul();

void add() {
  printf("Elements of the sum of matrices:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      Add[i][j] = arr1[i][j] + arr2[i][j];
      printf("%d ", Add[i][j]);
    }
    printf("\n");
  }
}

void mul() {
  printf("Elements of the product of matrices:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      Mul[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        Mul[i][j] += arr1[i][k] * arr2[k][j];
      }
      printf("%d ", Mul[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  char choice;
  printf("--------Enter the values of the first matrix--------\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Enter value of element [%d][%d]: ", i, j);
      scanf("%d", &arr1[i][j]);
    }
  }

  printf("--------Enter the values of the second matrix--------\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Enter value of element [%d][%d]: ", i, j);
      scanf("%d", &arr2[i][j]);
    }
  }

  printf("Press 'A' or 'a' for addition and 'M' or 'm' for multiplication: ");
  scanf(" %c", &choice);

  if (choice == 'M' || choice == 'm') {
    mul();
  } else if (choice == 'A' || choice == 'a') {
    add();
  } else {
    printf("Bad choice!!\n");
  }

  return 0;
}
