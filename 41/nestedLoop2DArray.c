#include <stdio.h>

int main() {
  int theTwoDimensionalArray[4][3];
  for (int i = 0; i < 4; i++)
    for (int j = i; j < i+3; j++)
      theTwoDimensionalArray[i][j-i] = j;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d ",theTwoDimensionalArray[i][j]);
    printf("\n");
  }
}
