
const int a = 10;

char is_same(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) return 0;
        str1++; str2++;
    }

    if (!*str2) return 1;

    return 0;
}
