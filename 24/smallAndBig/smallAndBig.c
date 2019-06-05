#include <stdio.h>

int main() {
    int *smallptr, *bigptr;
    int small, big;
    small = 10;
    big = 10000;
    smallptr = &small;
    bigptr = &big;
    small = *bigptr;
    big = *smallptr;
    *bigptr = 100;

    printf("small: %d, big: %d, smallptr: %p, smallptr's ptr: %p\n", small, big, smallptr, &smallptr);

    return 0;
}