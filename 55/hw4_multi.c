#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// the data to pass to threads
struct ThreadArgs {

  // base Number to start the loop
  int baseNumber;

  // how many times the loop should be run?
  int range;

  // the pointer to return after the result
  int *result;
};

int primeNoCountWOEventualConsistency = 0;

int checkPrime(int num);
void *threadProcess(void *threadArgs);

int main(int argc, char *argv[]) {

  // argument check
  if (argc < 2) {
    printf("ERROR: Invalid Usage!\n");
    printf("ERROR: Usage: %s <upper limit> <? number of processes>\n", argv[0]);
    return 1;
  }

  // default threadCount
  int threadCount = 10;

  // set custom thread counts to optimize for each systems
  // try running with command ./hw4_multi 100000 `nproc`
  if (argc >= 3) {
    int tempThreadCount = atoi(argv[2]);

    // if user's thread count is valid, set the threadcount to user definition.
    if (tempThreadCount > 0) {
      printf("INFO : [Thread] Set threadCount to %d.\n", tempThreadCount);
      threadCount = tempThreadCount;
    }
  }

  // get threadId allocation
  pthread_t *threadIds;

  // allocate from memory
  threadIds = (pthread_t *)malloc(sizeof(pthread_t) * threadCount);
  if (threadIds == NULL) {
    printf("ERROR: Memory Allocation Failed! - threadId\n");
    return 1;
  }

  // the array on heap to store thread outputs
  int *threadOutputs = (int *)malloc(sizeof(int) * threadCount);
  if (threadOutputs == NULL) {
    printf("ERROR: Memory Allocation Failed! - threadOutputs\n");
    return 1;
  }

  // initialize threadOutputs
  for (int i = 0; i < threadCount; i++) {
    threadOutputs[i] = 0;
  }

  // get input number from commandline args
  int num = atoi(argv[1]);

  // prime Number counts
  int primeNoCount = 0;

  // allocating range per threads
  int rangePerThread = num / threadCount;
  // last thread should have remainder for process
  int lastThreadRangePlus = num % threadCount;

  // start timer
  struct timespec timeStart;
  clock_gettime(CLOCK_MONOTONIC, &timeStart);
  printf("INFO : [ Timer] Starting Timer.\n");

  printf("INFO : [Thread] Threading Started with %d threads.\n\n", threadCount);
  
  // do async runs
  for (int i = 0; i < threadCount; i++) {

    // get args
    struct ThreadArgs *args = (struct ThreadArgs *)malloc(sizeof(struct ThreadArgs));

    // check for memory allocation for thread args failed.
    if (args == NULL) {
      printf("ERROR: Memory Allocation Failed! - threadArgs\n");
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

    // its ok not to free because the threads will do it by themselves.
  }

  // run await
  for (int i = 0; i < threadCount; i++) {
    // run await for all threads
    pthread_join(threadIds[i], NULL);

    // if await is done, add thread's output to final data.
    primeNoCount += threadOutputs[i];
  }

  // thread operations are completed. It is now safe to free threadIds.
  free(threadIds);

  // free the eventual consistency temporary array since all awaits are completed and summed up.
  free(threadOutputs);

  printf("\n");

  // end timer
  struct timespec timeEnd;
  clock_gettime(CLOCK_MONOTONIC, &timeEnd);

  // calculate elapsed seconds
  double elapsedSec = timeEnd.tv_sec - timeStart.tv_sec + ((timeEnd.tv_nsec - timeStart.tv_nsec) / 1e+9);
  
  // print.
  printf("INFO : [ Timer] Timer Ended. elapsedTime: %.4lf seconds\n\n", elapsedSec);

  // output.
  printf("INFO : [Result] result w/o eventual consistency: %d prime numbers.\n", primeNoCountWOEventualConsistency);
  printf("INFO : [Result] result w/  eventual consistency: %d prime numbers.\n", primeNoCount);

  return 0;
}


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

// the process to run on each process
void *threadProcess(void *threadArg) {
  // save arguments for this thread.
  struct ThreadArgs *arg = (struct ThreadArgs *)threadArg;
  
  // real procedure
  for (int i = arg->baseNumber, j = 0; j < arg->range; i++, j++) {
    // if it is prime, count.
    if (checkPrime(i)) { 
      // critical section
      primeNoCount++; 
    }
  }

  // debug output - with temp result datas.
  printf("DEBUG: [Thread] baseNumber: %7d with range: %7d : %7d prime numbers\n", arg->baseNumber, arg->range, *(arg->result));

  // free the arg since we don't need it anymore
  free(threadArg);

  return NULL;
}