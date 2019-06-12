#include <stdio.h>
#define SIZE 100

void stringCopy(char* original, char* destination);

int main() {
    char str1[SIZE] = "Hello, World! It's Saraj.";
    char str2[SIZE];
    char str3[SIZE];

    stringCopy(str1, str2);
    stringCopy(str1, str3);

    printf("%s %s\n", str1, str2);
    printf("%s %s\n", str1, str3);
}

void stringCopy(char* original, char* destination) {
    int current = 0;
    while (original[current]) {
        destination[current] = original[current];
        current++;
    }
    destination[current] = 0;
}

void stringCopyByPointer(char* original, char* destination) {
    int current = 0;
    char* arrayDest = destination;
    while (*(original+current)) {
        arrayDest = original+current;
        current++;
        arrayDest += 1;
    }
    arrayDest = 0;
}