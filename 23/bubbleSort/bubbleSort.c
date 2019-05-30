#include <stdio.h>

// swap the a and b's addresses
void swap(int* a, int* b) {
    int* tmp = b;
    b = a;
    a = tmp;
}

//bubble sort the sortMe array
void bubbleSort(int sortMe[], int size) {
    // 1, 2, 3, 4, Bubble, Bubble. https://www.youtube.com/watch?v=gu0eDWj05do
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size - i; j++) {
            if (sortMe[i] > sortMe[j]) {
                swap(&sortMe[i], &sortMe[j]);
            }
        }
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
    bubbleSort(a, 10);
    printArray(a, 10);
    return 0;
}
