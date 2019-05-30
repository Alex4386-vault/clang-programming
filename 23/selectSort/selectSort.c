#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

//select sort the sortMe array
void selectSort(int sortMe[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (sortMe[j] < sortMe[smallestIndex]) {
                smallestIndex = j;
            }
        }

        swap(&sortMe[i], &sortMe[smallestIndex]);
    }
}

void printArray(int input[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");
}

int main() {
    int a[10] = {3,1,2,5,37,743,3274,2738,3894,28};
    printArray(a, 10);
    selectSort(a, 10);
    printArray(a, 10);
    return 0;
}
