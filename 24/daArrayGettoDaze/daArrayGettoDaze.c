#include <stdio.h>

int main() {


    int arr[3] = {1,2,3};
    printf("Pointers: %p\n", arr);
    printf("0th index: %p\n", &arr[0]);
    printf("1st index: %p\n", &arr[1]);
    printf("2nd index: %p\n", &arr[2]);

    int* ptr;
    ptr = arr;

    printf("Access by Dynmaic Pointers: %p\n", arr);
    printf("0th index: %p\n", ptr);
    printf("1st index: %p\n", ptr+1);
    printf("2nd index: %p\n", ptr+2);

    return 0;
}