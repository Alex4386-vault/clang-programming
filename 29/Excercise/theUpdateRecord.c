#include <stdio.h>

struct EmployeeRecord {
    char* name;
    char* hobby;
    long long int age;
    float salary;
};

typedef struct EmployeeRecord EmployeeRecord;

void print_employee_record(EmployeeRecord ec);
void update_records(EmployeeRecord *ec);

int main() {
    EmployeeRecord ang = {"Chris Henry", "Training", 1000000000000000000, 0};
    print_employee_record(ang);
    printf("\n");
    update_records(&ang);
    print_employee_record(ang);
}

void update_records(EmployeeRecord *ec) {
    ec->age = 25;
}

void print_employee_record(EmployeeRecord ec) {
    printf("===[ Employee %15s ]===\n", ec.name);
    printf("Hobby:   %25s\n", ec.hobby);
    printf("Age:     %25lld\n", ec.age);
    printf("Salary: $%25.2f\n", ec.salary);
}
