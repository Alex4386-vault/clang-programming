#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct to save employee salary data.
struct EmployeeSalary {
    // name
    char name[20];
    
    // department in NULL-terminated string
    char department[11];

    // salary
    int salary[3];
};

// main function
int main() {

    // definition of FILE pointer - read.
    FILE *empFile = fopen("Salary.txt", "r");

    // exception handling: I/O Error
    if (!empFile) {
        // print user-friendly error message.
        printf("[ERROR] Unable to read the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        // finish program with errorcode 1
        return 1;
    }   

    // variable to save how many employees should be saved into empFile
    int howMany = 0;

    // read from the file
    fscanf(empFile, "%d",&howMany);

    // definition of FILE pointer - to save technical people's salary only
    FILE *techFile = fopen("Salary_technical.txt", "w");

    // exception handling again. : I/O error
    if (!techFile) {
        // print user-friendly error message
        printf("[ERROR] Unable to write the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        // finish program with errorcode 1
        return 1;
    }

    // dynamically allocate heap area size of pre-defined header.
    struct EmployeeSalary *empList = malloc(sizeof(struct EmployeeSalary)*howMany);

    // exception handling for memory I/O
    if (!empList) {
        // user-friednly errormsg
        printf("[ERROR] Unable to allocate memory.\nPlease check your computer is currently out of memory.\n");
        // errorcode 1
        return 1;
    }

    // variable to store how many technical people in the file?
    int count = 0;

    // loop until end of file or previously defined howmany people, in case file was damaged.
    for (int i = 0; i < howMany && !feof(empFile); i++) {
        // define EmployeeSalary struct
        struct EmployeeSalary emp = {"", "", {0,}};

        // save it to new EmployeeSalary.
        fscanf(empFile, "%s %s %d %d %d", emp.name, emp.department, &emp.salary[0], &emp.salary[1], &emp.salary[2]);

        // check if emp.department is "Technical"
        if (!strcmp("Technical", emp.department)) {
            // then add to dynmaically allocated list and add count.
            empList[count] = emp;
            count++;
        }
    }

    // write to the file of the how many technical people is there
    fprintf(techFile, "%d\n", count);

    // copy the pointer.
    struct EmployeeSalary *empPtr = empList;

    // for all employeeList.
    for (int i = 0; i < count; i++, empPtr++) {

        // get sum of the salaries
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            // add all salaries.
            sum += empPtr->salary[j];
        }

        // write to file.
        fprintf(techFile, "%s %d %.2f\n", empPtr->name, sum, sum/(float)3);

    }

    // free the dynmaically allocated empList
    free(empList);

    // close File pointer.
    fclose(empFile);
    fclose(techFile);
}
