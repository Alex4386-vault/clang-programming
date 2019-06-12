#include <stdio.h>

int stringLength(char*s){int l=0; while(*(s+l)){l++;} return l;}
void reverseString(char* str);
void swap(char* a, char* b);

int main() {
    char a[100] = "abcd";
    reverseString(a);
    printf("%s\n", a);
}

void reverseString(char* str) {
    int l = stringLength(str);
    for (int i = 0; i <= (int)l/2; i++) {
        swap(&str[i], &str[l-i]);
    }
    for (int i = 0; i < l; i++) {
        swap(&str[i], &str[i+1]);
    }
}

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}
