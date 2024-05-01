#include <stdio.h>

void strassen_multiply(int A[2][2], int B[2][2], int C[2][2]) {
  int P1 = A[0][0] * (B[0][1] - B[1][1]);
  int P2 = (A[0][0] + A[0][1]) * B[1][1];
  int P3 = (A[1][0] + A[1][1]) * B[0][0];
  int P4 = A[1][1] * (B[1][0] - B[0][0]);
  int P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
  int P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
  int P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

  C[0][0] = P5 + P4 - P2 + P6;
  C[0][1] = P1 + P2;
  C[1][0] = P3 + P4;
  C[1][1] = P5 + P1 - P3 - P7;
}

int main() {
  int A[2][2];
  int B[2][2];

  printf("--------Enter the values of the first matrix--------\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Enter value of element [%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  printf("--------Enter the values of the second matrix--------\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Enter value of element [%d][%d]: ", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  int C[2][2];
  strassen_multiply(A, B, C);

  printf("Resultant matrix C:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
