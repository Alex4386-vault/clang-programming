// Errors on this file is intended.

#include <stdio.h>

int y;

int main() {
    int x = 5;
    int y;

    const int *const ptr = &x;

    ptr = &y; // illegal operation: ptr is constant pointer, so it can't be modified

    *ptr = 10; // this is also illegal operation: it is pointer of const int, so it can't be modified.

    return 0;
}