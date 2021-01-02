#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bad algorithm,
// but this is only to waste cycle to show dramatic
// difference between single threading and multi threading
int checkPrime(int num) {
  if (num < 2) return 0;
  
  for (int i = 2; i*i <= num; i++) {
    if (num % i == 0) return 0;
  }
  
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: Invalid Usage!\n");
    return 1;
  }

  int num = atoi(argv[1]);
  int primeNoCount = 0;

  clock_t timeStart = clock();
  //struct timespec timeStart;
  //clock_gettime(CLOCK_MONOTONIC, &timeStart);
  
  for (int i = 0; i < num; i++) primeNoCount = (checkPrime(i)) ? primeNoCount + 1 : primeNoCount;

  clock_t timeEnd = clock();
  //struct timespec timeEnd;
  //clock_gettime(CLOCK_MONOTONIC, &timeEnd);

  double elapsedSec = (double) (timeEnd - timeStart) / CLOCKS_PER_SEC;
  //double elapsedSec = timeEnd.tv_sec - timeStart.tv_sec + ((timeEnd.tv_nsec - timeStart.tv_nsec) / 1e+9);
  
  printf("INFO: elapsedTime: %.4lf seconds\n", elapsedSec);
  printf("INFO: result: %d prime numbers.\n", primeNoCount);

  return 0;
}
