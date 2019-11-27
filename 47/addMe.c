#include <stdio.h>

#define ADD
//#undef ADD

int main(void) {
    double num1 = 3.3, num2 = 1.1, result = 0.0;

    #ifdef ADD
    result = num1 + num2;
    printf("ADD result : %lf\n", result);
    #endif

    return 0;
}