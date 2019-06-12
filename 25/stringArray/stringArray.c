#include <stdio.h>
#define SIZE 4

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void swapDoublePointer(char** a, char** b) {
    char* c = *a;
    *a = *b;
    *b = c;
}

int main() {
    char* strArray[SIZE] = { "Kim", "Lee", "Park", "Choi"};

    for (int i = 0; i < SIZE; i++) {
        printf("%d-th string: %s\n", i, strArray[i]);
    }

    swapDoublePointer(&strArray[1], &strArray[2]);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d-th string: %s\n", i, strArray[i]);
    }


    return 0;
}