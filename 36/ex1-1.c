#include <stdio.h>

int main() {
  int i = 0;
  FILE *fp;
  double price;
  char rbuff[255];

  fp = fopen("price.dat", "r");
  if (fp == NULL) {
    printf("The File Could Not be Read");
    return -1;
  }

  // = 2 items are updated
  while(fscanf(fp, "%s %lf", rbuff, &price) == 2) {
    printf("%d: %s %6.2f\n", i++, rbuff, price);
  }
  fclose(fp);
}
