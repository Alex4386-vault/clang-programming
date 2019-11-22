#include <stdio.h>

int isInUse(int x, int p) {
    return (((0b1 << p) & x) >> p) & 0b1;
}

void setInUse(int *x, int p) {
    *x = *x | (*x << p);
}

int main() {
    int a = 0b00100000;
    printf("5. %s\n", (isInUse(a, 5)) ? "YES":"NO");
    printf("4. %s\n", (isInUse(a, 4)) ? "YES":"NO");
    printf("\n");

    setInUse(&a, 4);
    printf("4. %s\n", (isInUse(a, 5)) ? "YES":"NO");


}