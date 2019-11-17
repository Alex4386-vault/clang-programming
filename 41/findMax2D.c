#include <stdio.h>


int main() {
  int matrix[3][4]  = {{0,1,0,2},{-1,2,4,3},{0,-1,3,1}};
  int max = -100;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      max = matrix[i][j] > max ? max : matrix[i][j];

  printf("%d\n", max);
}
