#include <stdio.h>

void add20point2(float *num);

int main() {
    float ang = 10;
    printf("%f\n", ang);
    add20point2(&ang);
    printf("%f\n", ang);
    return 0;
}

void add20point2(float *num) {
    *num += 20.2;
}