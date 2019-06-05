#include <stdio.h>

int main() {
    int x = 40, y = 20, sol1,sol2,sol3;
    int *xptr, *yptr, *wptr;

    xptr = &x;
    yptr = &y;

    sol1 = **&xptr; // sol1 = *xptr;
    sol2 = 4 * *xptr / *yptr + 22;
    sol3 = *(wptr = &y);

    printf("sol1: %d, sol2: %d, sol3: %d\n", sol1, sol2, sol3);
}