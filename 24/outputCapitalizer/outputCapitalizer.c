#include <stdio.h>

int main() {
    char *p;
    char s[81] = "He drinks coke each day.";

    for (p=s+10; *p != 0; p++) {
        switch(*p) {
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                *p = *p + ('A'-'a');
                break;
            case ' ':
                *p = '\n';
        }
    }

    printf("%s\n", s);
}