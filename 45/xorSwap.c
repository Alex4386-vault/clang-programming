#include <stdio.h>

void swap(int *x, int *y) {
    // 0000 1010
    // 0000 0101




    // 0000 1111
    // 0000 0101
    *x = *x ^ *y;


    // 0000 1111
    // 0000 1010
    *y = *x ^ *y;


    // 0000 0101
    // 0000 1010
    *x = *x ^ *y;

}

int main() {
    int a = 10;
    int b = 5;
    printf("%d %d\n",a,b);

    swap(&a, &b);
    printf("%d %d\n",a,b);

}