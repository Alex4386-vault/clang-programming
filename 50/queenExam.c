//201935023 김수현

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintMatrix(int m[][10], int row, int col)
{
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         printf("%4d", m[i][j]);
      }
      printf("\n");
   }
}


void SetMatrix(int m[][10], int row, int col)
{
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         m[i][j] = rand() % 11; //0~10까지
         if (rand() % 2 == 0)m[i][j] *= -1; //반반의 확률로 음수
      }
   }
}