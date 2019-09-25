#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining employee structure
typedef struct Employee {

    // name of the employee
    char* name;

    // variable for storing current Salary
    double currentSalary;

} Employee;

// returns highest salary employee's pointer on employee pointer array
Employee* theHighestSalaryEmployee(Employee** list, int length) {

    // initing with 0-th index
    double highest = list[0]->currentSalary;

    // the pointer to return
    Employee* highestEmployee = list[0];

    // in the all list
    for (int i = 0; i < length; i++) {
        // if currentSalary is bigger than current highest
        if (list[i]->currentSalary > highest) {

            // update current highest
            highest = list[i]->currentSalary;

            // update highest employee pointer
            highestEmployee = list[i];
        }
    }

    return highestEmployee;
}

// returns lowest salary employee's pointer on employee pointer array
Employee* theLowestSalaryEmployee(Employee** list, int length) {

    // initing with 0-th index
    double lowest = list[0]->currentSalary;

    // the pointer to return
    Employee* lowestEmployee = list[0];

    // in the all list
    for (int i = 0; i < length; i++) {

        // if currentSalary is lower than current lowest
        if (list[i]->currentSalary < lowest) {

            // update current lowest
            lowest = list[i]->currentSalary;

             // update lowest employee pointer
            lowestEmployee = list[i];
        }
    }

    // return lowestEmployee
    return lowestEmployee;
}

int main() {
    // define how many employee in program
    const int howManyEmployee = 5;

    // where employee memory addresses are stored.
    Employee** employeeMemAddressArray = (void *)malloc(sizeof(Employee *) * howManyEmployee);

    // for to specified how many employee
    for (int i = 0; i < howManyEmployee; i++) {

        // malloc-ing employee
        Employee* employee = (void *)malloc(sizeof(Employee));

        // add to arrays of employee pointers
        employeeMemAddressArray[i] = employee;

        // print employee number to client
        printf("Employee #%d: \n", i+1);

        // ask client to enter name
        printf("  Enter Name: ");

        // malloc-ing for employee name
        char* theName = (void *)malloc(sizeof(char)*20);

        // get scanf input
        scanf("%s", theName);

        // get name and save it
        employee->name = theName;

        // ask client to enter salary
        printf("  Enter Salary: ");

        // save as double
        scanf("%lf", &(employee->currentSalary));

        // line return
        printf("\n");
    }

    // to line returns to distinguish which is input section and output section
    printf("\n\n");

    // get the highest employee
    Employee* daHighest = theHighestSalaryEmployee(employeeMemAddressArray, howManyEmployee);

    // get the lowest employee
    Employee* daLowest = theLowestSalaryEmployee(employeeMemAddressArray, howManyEmployee);

    // the highest salary:
    printf("The Highest Salary Employee:\n");
    // show name
    printf("  name: %s\n", daHighest->name);
    // show salary
    printf("  salary: %lf\n", daHighest->currentSalary);
    // line feed
    printf("\n");

    // the lowest salary
    printf("The Lowest Salary Employee:\n");
    // show name
    printf("  name: %s\n", daLowest->name);
    // show salary
    printf("  salary: %lf\n", daLowest->currentSalary);
    // line feed
    printf("\n");

    // everything is done, so I will free them.
    for (int i = 0; i < howManyEmployee; i++) {
        // get employee pointer
        Employee* employee = employeeMemAddressArray[i];
        // free employee name pointer
        free(employee->name);
        // free employee pointer itself
        free(employee);
    }

    // free malloced pointer array either
    free(employeeMemAddressArray);
}