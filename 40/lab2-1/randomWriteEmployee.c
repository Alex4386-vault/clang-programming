#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct EmployeeSalary {
    char name[20];
    char department[11];
    int salary[3];
};

char names[10][20] = {
    "CHOI",
    "HWANG",
    "KIM",
    "KANG",
    "LEE",
    "PARK",
    "WANG",
    "OK",
    "AHN",
    "CHRIS"
};

char departments[3][11] = {
    "Technical",
    "Management",
    "Production"
};

struct EmployeeSalary employeeSalaryConstructor() {
    struct EmployeeSalary emp = { "", "", { 1 + (rand() % 20), 1 + (rand() % 20), 1 + (rand() % 20)} };
    strcpy(emp.name, names[(int)rand() % 10]);
    strcpy(emp.department, departments[(int)rand() % 3]);
    return emp;
}

int main() {
    srand(time(NULL));
    
    int howMany = 0;
    printf("How many data should I generate? ");
    scanf("%d", &howMany);

    FILE *salaryRandom = fopen("Salary.txt","w");
    if (!salaryRandom) {
        printf("[ERROR] Unable to write the file.\nPlease check write permission or Disk's S.M.A.R.T.\n");
        return 1;
    }
    
    fprintf(salaryRandom, "%d\n", howMany);
    
    for (int i = 0; i < howMany; i++) {
        struct EmployeeSalary empl = employeeSalaryConstructor();

        fprintf(salaryRandom, "%s %s %d %d %d\n", empl.name, empl.department, empl.salary[0], empl.salary[1], empl.salary[2]);
    }

    fclose(salaryRandom);
    
    
}