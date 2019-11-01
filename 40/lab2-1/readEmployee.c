#include <stdio.h>

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

    // open salary file as readable
    FILE *empFile = fopen("Salary.txt", "r");

    // File I/O error: exception handling
    if (!empFile) {
        // user-friendly errormsg
        printf("[ERROR] Unable to read the file.\nPlease check read permission or Disk's S.M.A.R.T.");
        // errorcode 1
        return 1;
    }   

    // variable to save howMany employee is saved in the file
    int howMany = 0;

    // load from file
    fscanf(empFile, "%d",&howMany);

    // loop until end of file or previously defined howmany people, in case file was damaged.
    for (int i = 0; i < howMany && !feof(empFile); i++) {
        // define EmployeeSalary struct
        struct EmployeeSalary emp = {"", "", {0,}};

         // save it to new EmployeeSalary.
        fscanf(empFile, "%s %s %d %d %d", emp.name, emp.department, &emp.salary[0], &emp.salary[1], &emp.salary[2]);

        // print employee
        printf("Employee name: %s\n\tdept: %s\n\tLast Three Year Salaries: %d, %d, %d\n\n", emp.name, emp.department, emp.salary[0], emp.salary[1], emp.salary[2]);
    }

    // close file pointer.
    fclose(empFile);
}
