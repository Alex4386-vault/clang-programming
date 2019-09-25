#include <stdio.h>
#include <stdlib.h>

int main() {
    int theArrayLength;
    int *theHeapPtr;
    printf("Enter how many elements: ");
    scanf("%d", &theArrayLength);

    theHeapPtr = (int *)calloc(theArrayLength, sizeof(int));
    //theHeapPtr = (int *)malloc(theArrayLength * sizeof(int));

    if (theHeapPtr == NULL) {
        printf("Allocation Error! Out Of Memory!!");
        exit(1);
    } 

    printf("Enter elements of array: ");
    for (int i = 0; i < theArrayLength; i++) {
        scanf("%d", theHeapPtr+i);
    }

    int sum = 0;
    long long int mult = 1;
    for (int i = 0; i < theArrayLength; i++) {
        sum += *(theHeapPtr + i);
        mult = *(theHeapPtr + i);
    }

    printf("\n\nsum = %d, mult = %lld\n", sum, mult);

    free(theHeapPtr);

    return 0;
}