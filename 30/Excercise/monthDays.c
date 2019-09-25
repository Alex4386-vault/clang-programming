#include <stdio.h>

struct MonthDays {
    char monthName[10];
    int days;
};

typedef struct MonthDays MonthDays;

MonthDays monthDays[12] = {
    { "January", 31 },
    { "February", 28 },
    { "March", 31 },
    { "April", 30 },
    { "May", 31 },
    { "June", 30 },
    { "July", 31 },
    { "August", 31 },
    { "September", 30 },
    { "October", 31 },
    { "November", 30 },
    { "December", 31 }
};

void printMonthDays(MonthDays md) {
    printf("%9s - days: %2d\n", md.monthName, md.days);
}

int main() {
    for (int i = 0; i < 12; i++) {
        printMonthDays(monthDays[i]);
    }    

    return 0;
}
