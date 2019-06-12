#include <stdio.h>

int stringPosition(const char* str, const char find) { int i = 0; while(*(str+i) == (char)find) { i++; if (*(str+i)) return -1;}  return i; }

int main() {
    printf("%d\n", stringPosition("abc", 'c'));
}