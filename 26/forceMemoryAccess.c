#include <stdio.h>

int main() {
    int *p = (int*)0x000a;

    // Expected Bad Code: Accessing unaccessable Memory address: 0x000a
    printf("%d", *p);
}