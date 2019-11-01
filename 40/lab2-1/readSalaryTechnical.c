#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct EmployeeSalary {
    char name[20];
    char department[11];
    int salary[3];
};

int main() {
    FILE *empFile = fopen("Salary.txt", "r");

    if (!empFile) {
        printf("[ERROR] Unable to read the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        return 1;
    }   

    int howMany = 0;
    fscanf(empFile, "%d",&howMany);

    FILE *techFile = fopen("Salary_technical.txt", "w");

    if (!techFile) {
        printf("[ERROR] Unable to write the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        return 1;
    }

    struct EmployeeSalary *empList = malloc(sizeof(struct EmployeeSalary)*howMany);

    if (!empList) {
        printf("[ERROR] Unable to allocate memory.\nPlease check your computer is currently out of memory.\n");
        return 1;
    }


    int count = 0;
    for (int i = 0; i < howMany && !feof(empFile); i++) {
        struct EmployeeSalary emp = {"", "", {0,}};
        fscanf(empFile, "%s %s %d %d %d", emp.name, emp.department, &emp.salary[0], &emp.salary[1], &emp.salary[2]);

        if (!strcmp("Technical", emp.department)) {
            empList[count] = emp;
            count++;
        }
    }

    fprintf(techFile, "%d\n", count);
    struct EmployeeSalary *empPtr = empList;
    for (int i = 0; i < count; i++, empPtr++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum = empPtr->salary[j];
        }
        fprintf(techFile, "%s %d %.2f\n", empPtr->name, sum, sum/(float)3);

    }

    fclose(empFile);
    fclose(techFile);
}
