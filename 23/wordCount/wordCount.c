#include <stdio.h>

int true = 1, false = 0;

int wordCount(char a[]) {
    int count = 0;
    int prevWasSpace = true;
    for (int i = 0; a[i]; i++) {
        if (a[i] == ' ') {
            prevWasSpace = true;
            
        } else {
            if (prevWasSpace) {
                count++;
            }
            prevWasSpace = false;
        }
    } 
}


int main() {
    printf("wordCount: %d\n", wordCount("   ang gi mo    tti"));
}
