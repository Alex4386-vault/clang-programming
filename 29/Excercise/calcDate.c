#include <stdio.h>

struct DATE {
    int day, month, year;
};

int calculateDays(struct DATE date) {
    return date.day + (date.month * 30) + ((date.year - 1900) * 365);
}

int main() {
    struct DATE d = {9, 10, 2200};

    printf("%d\n", calculateDays(d));
    return 0;
}