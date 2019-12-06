#include <stdio.h>
#include "str.h"

extern const int a;

int main() {
    printf("%d\n\n", a);

    char str1[20], str2[20];

    fgets(str1, 20, stdin);
    fgets(str2, 20, stdin);

    if (is_same(str1, str2)) {
        printf("%s == %s", str1, str2);
    } else {
        printf("%s != %s", str1, str2);
    }

    return 0;
}