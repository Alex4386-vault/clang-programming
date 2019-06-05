#include <stdio.h>

int main() {
    int *ptr;
    int var = 1000;

    ptr = &var;
    printf("variable: %d\n", var);
    printf("variable address: %p\n", &var);

    printf("pointer value: %p\n", ptr);
    printf("value of address at pointer vale: %d\n", *ptr);


    return 0;
}