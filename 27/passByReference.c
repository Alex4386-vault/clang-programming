#include <stdio.h>

void increase2(int x) {
    x = x + 2;
    printf("X is %d in increase 2\n", x);
}

void increase2ByPointer(int* x) {
    *x = *x + 2;
    printf("X is %d in increase 2 by pointer\n", *x);
}

int main() {
    int x = 2;
    printf("X is %d\n", x);
    increase2(x);
    printf("X is %d at outside!\n", x);

    printf("\n");

    printf("X is %d\n", x);
    increase2ByPointer(&x);
    printf("X is %d at outside!\n", x);

}

int cubeByValue(int x) {
    return x*x*x;
}

void cubeByReference(int* x) {
    *x = (*x)*(*x)*(*x);
}