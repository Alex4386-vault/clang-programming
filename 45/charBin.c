#include <stdio.h>

int main() {
    char a;
    scanf("%c", &a);

    // placeholder mask
    a = a & 0xFF;

    for (int i = ((int)sizeof(char) * 8) - 1; i >= 0; i--) {
        printf("%d", (a >> i) & 0b1);
    }
    printf("\n");
}