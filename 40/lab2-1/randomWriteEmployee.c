#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct to save employee salary data.
struct EmployeeSalary {
    // name
    char name[20];
    
    // department in NULL-terminated string
    char department[11];

    // salary
    int salary[3];
};

// name array
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

// department array
char departments[3][11] = {
    "Technical",
    "Management",
    "Production"
};

/**
 * construct new EmployeeStruct Struct with random data.
 * 
 * @return constructed EmployeeSalary struct.
 **/
struct EmployeeSalary employeeSalaryConstructor() {
    // create struct
    struct EmployeeSalary emp = { "", "", { 1 + (rand() % 20), 1 + (rand() % 20), 1 + (rand() % 20)} };
    // get random name from name array
    strcpy(emp.name, names[(int)rand() % 10]);
    // get random department from departments array
    strcpy(emp.department, departments[(int)rand() % 3]);
    // return struct
    return emp;
}

// main function
int main() {
    // set random seed as current time epoch
    srand(time(NULL));
    
    // variable for howMany.
    int howMany = 0;

    // ask user howMany 
    printf("How many data should I generate? ");
    scanf("%d", &howMany);

    // create file pointer - write
    FILE *salaryRandom = fopen("Salary.txt","w");

    // File I/O Exception Handling
    if (!salaryRandom) {
        // user-friendly errormsh
        printf("[ERROR] Unable to write the file.\nPlease check write permission or Disk's S.M.A.R.T.\n");
        // errorcode 1
        return 1;
    }
    
    // print howmany to file
    fprintf(salaryRandom, "%d\n", howMany);
    
    // for every employee
    for (int i = 0; i < howMany; i++) {
        // create new struct using random constructor defined above
        struct EmployeeSalary empl = employeeSalaryConstructor();

        // and write to the file
        fprintf(salaryRandom, "%s %s %d %d %d\n", empl.name, empl.department, empl.salary[0], empl.salary[1], empl.salary[2]);
    }

    // close the file pointer.
    fclose(salaryRandom);
    
    
}