#include <stdio.h>
#define SIZE 4

int main() {
    int value[SIZE] = {0,1,2,3};
    int *ptr[SIZE] = { 0, };

    for (int i = 0; i < SIZE; i++) {
        ptr[i] = &value[i];
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d-th index data: %d\n", i, value[i]);
        printf("%d-th index data from pointer: %p, %d\n", i, ptr[i], *ptr[i]);
    }
}