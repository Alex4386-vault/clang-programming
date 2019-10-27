#include <stdio.h>

char handleFileException(FILE *ptr) { return ptr == NULL; }

int main() {
  FILE *cfPtr;
  char myFileName[15] = "clients.dat";
  cfPtr = fopen(myFileName, "w");
  if (handleFileException(cfPtr)) {
      printf("File Could Not Be Opened\n");
      return -1;
  }

  fclose(cfPtr);
  return 0;
}
