#include <stdio.h>

int charCount(char string[]);

int main() {
    printf("%d\n", charCount("abcd"));
}

int charCount(char string[]) {
    int charCount = 0;

    for (int i = 0; string[i]; i++) {
        charCount++;
    }

    return charCount;
}