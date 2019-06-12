#include <stdio.h>

void exchange(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    exchange(&n1, &n2);
    printf("%d %d\n", n1, n2);
}