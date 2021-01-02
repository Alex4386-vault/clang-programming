#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// the data to pass to threads
struct ThreadArgs {

  // base Number to start the loop
  unsigned long long int baseNumber;

  // how many times the loop should be run?
  unsigned long long int range;

  // the pointer to return after the result
  unsigned long long int *result;
};

unsigned long long int primeNoCountWOEventualConsistency = 0;

int checkPrime(unsigned long long int num);
void *threadProcess(void *threadArgs);

int main(int argc, char *argv[]) {

  // argument check
  if (argc < 2) {
    printf("ERROR: Invalid Usage!\n");
    return 1;
  }

  // default threadCount
  int threadCount = 10;

  // set custom thread counts to optimize for each systems
  if (argc >= 3) {
    int tempThreadCount = atoi(argv[2]);
    if (tempThreadCount > 0) {
      printf("INFO: Set threadCount to %d\n", tempThreadCount);
      threadCount = tempThreadCount;
    }
  }

  // get threadId allocation
  pthread_t *threadIds;

  // allocate from memory
  threadIds = (pthread_t *)malloc(sizeof(pthread_t) * threadCount);
  if (threadIds == NULL) {
    printf("ERROR: Memory Allocation Failed!");
    return 1;
  }

  // the array on heap to store thread outputs
  unsigned long long int *threadOutputs = (unsigned long long int *)malloc(sizeof(unsigned long long int ) * threadCount);
  if (threadOutputs == NULL) {
    printf("ERROR: Memory Allocation Failed!");
    return 1;
  }

  // initialize threadOutputs
  for (int i = 0; i < threadCount; i++) {
    threadOutputs[i] = 0;
  }

  // get input number from commandline args
  unsigned long long int num = strtoull(argv[1], NULL, 10);

  // prime Number counts
  unsigned long long int primeNoCount = 0;

  // allocating range per threads
  unsigned long long int rangePerThread = num / threadCount;
  // last thread should have remainder for process
  unsigned long long int lastThreadRangePlus = num % threadCount;

  // start timer
  struct timespec timeStart;
  clock_gettime(CLOCK_MONOTONIC, &timeStart);
  
  // do async runs
  for (int i = 0; i < threadCount; i++) {

    // get args
    struct ThreadArgs *args = (struct ThreadArgs *)malloc(sizeof(struct ThreadArgs));

    // memory allocation for thread args failed.
    if (args == NULL) {
      printf("ERROR: Memory Allocation Failed!\n");
      return 1;
    }

    // set arguments
    args->range = rangePerThread;
    args->baseNumber = rangePerThread * i;

    // temporary saving point for implementing eventual consistency
    args->result = threadOutputs+i;
    
    // if it is last thread, add remainders
    if (i == threadCount - 1) { args->range += lastThreadRangePlus; }

    // create async thread
    pthread_create(threadIds+i, NULL, threadProcess, args);
  }

  // run await
  for (int i = 0; i < threadCount; i++) {
    // run await for all threads
    pthread_join(threadIds[i], NULL);

    // if await is done, add thread's output to final data.
    primeNoCount += threadOutputs[i];
  }

  // end timer
  struct timespec timeEnd;
  clock_gettime(CLOCK_MONOTONIC, &timeEnd);

  // calculate elapsed seconds
  double elapsedSec = timeEnd.tv_sec - timeStart.tv_sec + ((timeEnd.tv_nsec - timeStart.tv_nsec) / 1e+9);
  
  // print.
  printf("INFO: elapsedTime: %.4lf seconds\n", elapsedSec);
  printf("INFO: result w/o eventual consistency: %llu prime numbers.\n", primeNoCountWOEventualConsistency);
  printf("INFO: result w/  eventual consistency: %llu prime numbers.\n", primeNoCount);

  return 0;
}


// bad algorithm,
// but this is only to waste cycle to show dramatic
// difference between single threading and multi threading
int checkPrime(unsigned long long int  num) {
  if (num < 2) return 0;
  
  for (int i = 2; i*i <= num; i++) {
    if (num % i == 0) return 0;
  }
  
  return 1;
}

// the process to run on each process
void *threadProcess(void *threadArg) {
  // save
  struct ThreadArgs *arg = (struct ThreadArgs *)threadArg;
  
  // real procedure
  for (int i = arg->baseNumber, j = 0; j < arg->range; i++, j++) {
    if (checkPrime(i)) { (* (arg->result))++; primeNoCountWOEventualConsistency++; }
  }

  // debug output
  printf("DEBUG: [Thread] %llu, %llu: %llu\n", arg->baseNumber, arg->range, *(arg->result));

  // free the arg since we don't need it anymore
  free(threadArg);
  return NULL;
}