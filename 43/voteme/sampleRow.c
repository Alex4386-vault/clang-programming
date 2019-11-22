#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* common */

// open file, when it failed, exit the program
FILE *safeFileOpen(char *fileName, char* fileMode) {
    FILE *fp = fopen(fileName, fileMode);
    if (fp == NULL) {
        printf("Failed to open %s! Check the file permission or Disk S.M.A.R.T.!\n", fileName);
        exit(1);
    }

    return fp;
}

// malloc but when it failed, exit the program
void *safeMemoryAllocation(size_t size) {
    void *memAddr = (void *)malloc(size);
    if (memAddr == NULL) {
        printf("Failed to allocate memory! Check is it out of memory!");
        exit(1);
    }
    return memAddr;
}

// free all dynamically allocated double pointer
void freeAll(void **ptr, int length) {
    for (int i = 0; i < length; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

/* File Operations */

// Check how many line return characters are found in the file
int howManyLines(FILE *input) {

    // current location of file
    long a = ftell(input);

    // files have at least 1 lines
    int count = 1;

    // go to beginning
    fseek(input, 0, SEEK_SET);

    // for all characters
    for (char c = 0; !feof(input); c=getc(input)) {
        // if line return increase 1
        if (c == '\n') {
            count++;
        }
    }

    // to the previous location
    fseek(input, a, SEEK_SET);

    return count;
}

/* internal stuff */

// maximum length of individual region
const int regionsLength = 20;

// maximum length of individual candidate.
const int candidatesLength = 20;

// get array of candidates
char **getCandidates(FILE *input) {

    // get current location of file pointer
    long loc = ftell(input);

    // go to most front
    fseek(input, 0, SEEK_SET);

    // check how many lines are found in the file
    int lines = howManyLines(input);

    // allocate memory for array
    char **candidates = (char **)safeMemoryAllocation(sizeof(char *) * lines);

    // initialize memory for imndividual candidates.
    for (int i = 0; i < lines; i++) {
        candidates[i] = (char *)safeMemoryAllocation(sizeof(char *) * candidatesLength);
        strcpy(candidates[i], "");
    }

    // temporary variables
    char regionName[regionsLength] = "";
    int age = 0;
    char candidateName[candidatesLength] = "";

    // current candidate index.
    int candidateIndex = 0;

    // for every indexes
    for (fscanf(input, "%s %d %s\n", regionName, &age, candidateName); !feof(input); fscanf(input, "%s %d %s\n", regionName, &age, candidateName)) {
        
        // tmp variable for save is this candidate was already included.
        char isIncluded = 0;

        // for all candidates in the list
        for (int i = 0; i < lines && candidates[i][0] != 0; i++) {

            // if candidate is found, change it is included
            if (!strcmp(candidates[i], candidateName)) {
                isIncluded = 1;
            }
        }

        // if it is not included copy string.
        if (!isIncluded) {
            strcpy(candidates[candidateIndex], candidateName);
            candidateIndex++;
        }
    }

    // seek to prev. location
    fseek(input, loc, SEEK_SET);

    return candidates;
}

/* main */
int main() {
    // open file
    FILE *fp = safeFileOpen("vote.txt", "r");
    // read line count
    int lineCount = howManyLines(fp);

    // read candidates
    char **candidates = getCandidates(fp);

    // check how many candidates are in the candidates
    int candidatesCount = 0;
    // checking loop
    for (candidatesCount = 0; candidates[candidatesCount][0] != 0; candidatesCount++) { }

    // dynamically allocate for saving how many votes.
    int *candidatesVotes = (int *)safeMemoryAllocation(sizeof(int) * candidatesCount);
    for (int i = 0; i < candidatesCount; i++) {
        candidatesVotes[i] = 0;
    }

    // sample rate: ex. 2-4-6 -> sampleRate = 2
    //              ex. 3-6-9 -> sampleRate = 3
    int sampleRate = 1;

    // ask sampleRate
    printf("Enter the sampleRate for the vote : ");
    scanf("%d", &sampleRate);

    int totalSamples = 0;

    // for every lines,
    for (int i = 1; i <= lineCount && !feof(fp); i++) {
        char regionName[regionsLength] = "";
        int age = 0;
        char candidateName[candidatesLength] = "";

        if (feof(fp)) break;

        fscanf(fp, "%s %d %s\n", regionName, &age, candidateName);

        // check it is current sample rate.
        if (i % sampleRate == 0) {
            // if it is, check for all candidates.
            for (int j = 0; j < candidatesCount; j++) {
                // write for cadidatesVotes.ddxsesesdsdsrasdfytrewaertyuysatytrd
                if (!strcmp(candidates[j], candidateName)) {
                    candidatesVotes[j]++;
                    totalSamples++;
                }
            }
        }
    }

    // for all candidates, print vote percents
    for (int i = 0; i < candidatesCount; i++) {
        printf("%s: %.1lf%%\n", candidates[i], ((double)candidatesVotes[i] / totalSamples) * 100);
    }

    // free section.
    freeAll((void **)candidates, lineCount);
    free(candidatesVotes);
    fclose(fp);

    return 0;
}
