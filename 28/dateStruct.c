#include <stdio.h>

enum WeekDay { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

struct Date {
    int year;
    int month;
    int day;
    enum WeekDay weekday;
};

