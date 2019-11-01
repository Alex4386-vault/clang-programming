#include <stdio.h>

struct EmployeeSalary {
    char name[20];
    char department[11];
    int salary[3];
};

int main() {
    FILE *empFile = fopen("Salary.txt", "r");

    if (!empFile) {
        printf("[ERROR] Unable to read the file.\nPlease check read permission or Disk's S.M.A.R.T.");
        return 1;
    }   

    int howMany = 0;
    fscanf(empFile, "%d",&howMany);

    for (int i = 0; i < howMany && !feof(empFile); i++) {
        struct EmployeeSalary emp = {"", "", {0,}};
        fscanf(empFile, "%s %s %d %d %d", emp.name, emp.department, &emp.salary[0], &emp.salary[1], &emp.salary[2]);

        printf("Employee name: %s\n\tdept: %s\n\tLast Three Year Salaries: %d, %d, %d\n\n", emp.name, emp.department, emp.salary[0], emp.salary[1], emp.salary[2]);
    }

    fclose(empFile);
}
