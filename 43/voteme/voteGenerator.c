#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* common */

FILE *safeFileOpen(char *fileName, char* fileMode) {
    FILE *fp = fopen(fileName, fileMode);
    if (fp == NULL) {
        printf("Failed to open %s! Check the file permission or Disk S.M.A.R.T.!\n", fileName);
        exit(1);
    }

    return fp;
}

void *safeMemoryAllocation(size_t size) {
    void *memAddr = (void *)malloc(size);
    if (memAddr == NULL) {
        printf("Failed to allocate memory! Check is it out of memory!");
        exit(1);
    }
    return memAddr;
}

/* Region */
const int regionsCount = 10;

char regions[regionsCount][20] = {
    "Kentucky",
    "Idaho",
    "Alaska",
    "Hawaii",
    "Texas",
    "Arizona",
    "Massachusetts",
    "Michigan",
    "Ohio",
    "Virginia"
};

/* candidates */
const int candidatesCount = 3;

char candidates[candidatesCount][20] = {
    "Washington",
    "Lincoln",
    "Clinton"
};


int main() {
    FILE *fp = safeFileOpen("vote.txt", "w");
    srand(time(NULL));

    int howMany = 0;
    printf("How many votes should be generated? : ");
    scanf("%d", &howMany);

    for (int i = 0; i < howMany; i++) {
        fprintf(fp, "%s %d %s\n", regions[rand() % regionsCount], rand() % 100 + 20, candidates[rand() % candidatesCount]);
    }

    fclose(fp);
}