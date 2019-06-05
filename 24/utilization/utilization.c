#include <stdio.h>

void getInput(char* output) {
    gets(output);
}

int getLength(char* input) {
    int length = 0;
    for (int i = 0; *(input+i) != '\0'; i++) {
        length = i + 1;
    }
    return length;
}