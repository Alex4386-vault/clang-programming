#include <stdio.h>

int main() {
    int color = 0xFFAC9ADE;
    int theGreenMask = 0xFF << 8;

    char maGreen = 0xF4;
    color = (color & ~theGreenMask) | ((maGreen << 8) & theGreenMask);

    printf("%x\n", color);
}

