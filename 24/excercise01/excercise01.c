#include <stdio.h>

int main() {

    int x = 10, y = 20, z[100];
    int *pointer;

    pointer = &x;
    y = *pointer; // y has value of x

    *pointer = 100; // at pointer's address put 100.
    pointer = &z[0]; // pointer is updated at 0 location of z

    printf("x: %d, y: %d\n", x, y);
    printf("z Pointer: %p, pointer: %p\n", z, pointer);
}