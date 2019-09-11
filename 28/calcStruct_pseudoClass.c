/**
 * 
 * Implementing pseudo class with
 * C's struct system
 * 
 **/

#include <stdio.h>

struct calcStruct {
    int a;
    int b;
};

struct calcStruct *calcStructThis;

int calcStruct_Add() {
    return calcStructThis->a + calcStructThis->b;
}

int calcStruct_Minus() {
    return calcStructThis->a - calcStructThis->b;
}

int calcStruct_Multiply() {
    return calcStructThis->a * calcStructThis->b;
}

int calcStruct_Divide() {
    return calcStructThis->a / calcStructThis->b;
}

int calcStruct_Remainder() {
    return calcStructThis->a / calcStructThis->b;
}

int main() {
    struct calcStruct calculator;

    calculator.a = 10;
    calculator.b = 5;

    calcStructThis = &calculator;

    printf("%d\n",calcStruct_Add());
    printf("%d\n",calcStruct_Minus());
    printf("%d\n",calcStruct_Multiply());
    printf("%d\n",calcStruct_Divide());
    printf("%d\n",calcStruct_Remainder());



}
