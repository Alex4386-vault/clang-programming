#include <stdio.h>

void printArray(int input[], int size);
void addArray(int size, int input[], int value);
void add2Array(int first[], int firstSize, int second[], int secondSize, int result[]);

int main() {
    int a[3] = {1,2,3};
    printArray(a, 3);
    addArray(3, a, 3);
    printArray(a, 3);

    int b[3] = {4,5,6};
    int c[3] = {0,};
    add2Array(a, 3, b, 3, c);
    printArray(c, 3);
    return 0;
}

void printArray(int input[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]/*  */);
    }
    printf("\n");
}

void addArray(int size, int input[], int value) {
    for (int i = 0; i < size; i++) {
        input[i] += value;
    }
}

void add2Array(int first[], int firstSize, int second[], int secondSize, int result[]) {
    int smallerSize = (firstSize > secondSize) ? secondSize: firstSize;
    for (int i = 0; i < smallerSize; i++) {
        result[i] = first[i] + second[i];
    }
}