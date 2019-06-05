#include <stdio.h>

int main() {

    int* ptr;
    int arr[4] = {0,1,2,3};

    for (int i = 0; i < 4; i++) {
        printf("index %d via array: %d\n", i, arr[i]);
        printf("index %d via constant array pointer arithmetic: %d\n", i, *(arr+i));
        ptr = arr;
        printf("index %d via ptr[i] with dynamicPtr: %d\n", i, ptr[i]);
        printf("index %d via dynamic pointer arithmetic: %d\n", i, *(ptr+i));

    }
}