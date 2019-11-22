#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    int wa = 1;
    for (; n > 0; n--) wa *= n;
    return wa;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: %s {number}\n", argv[0]);
    } else {
        printf("%d\n", factorial(atoi(argv[1])));
    }
    return 0;
}