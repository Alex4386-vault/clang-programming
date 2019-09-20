#include <stdio.h>

struct Date {
    int year, month, day;
};

struct Employer {
    char* name;
    float salary;
    struct Date hiredDate;
};

void printData(struct Employer employer) {
    printf("===[ Employee %15s ]===\n", employer.name);
    printf("  Hired: %04d-%02d-%02d\n", employer.hiredDate.year, employer.hiredDate.month, employer.hiredDate.day);
    printf("  Salary: $%.2f\n", employer.salary);
}


int main() {
    struct Employer chris = {"Chris", 10000, {2019, 03, 01}};
    printData(chris);

    return 0;
}

