#include <stdio.h>

void calculate(int* a, int* b, int* ret);

int main() {

    int a,b;
    scanf("%d %d", &a, &b);

    int c[4] = {0,0,0,0};
    calculate(&a, &b, c);
    printf("%d %d %d %d\n", c[0], c[1], c[2], c[3]);

    return 0;
}

void calculate(int* a, int* b, int* c) {
    c[0] = *a * *b;
    c[1] = *a / *b;
    c[2] = *a % *b;
    c[3] = *a + *b;
}
