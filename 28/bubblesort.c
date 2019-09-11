#include <stdio.h>

/**
 * implementation of bubblesort
 */

void bubbleSort(int* array, const int length);
const int size = 10;

int main() {
    int a[size] = {5,3,2,9,7,1,8,6,4,10};

    bubbleSort(a, size);

    for (int i = 0; i < size; i++) {
        printf("%d ",a[i]);
    }

    printf("\n");
}

void bubbleSort(int* array, const int length) {
    void swap(int *a, int *b);

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
