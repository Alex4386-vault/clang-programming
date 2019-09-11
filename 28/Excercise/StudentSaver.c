#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Gender {
    Male = 0,
    Female = 1,
    Other = 2
} Gender;

typedef struct StudentRecord {
    char name[15];
    int id;
    char dept[5];
    Gender gender;
} StudentRecord;

void printStudentRecord(StudentRecord *sturec) {
    printf("The student is ");
    if (sturec->gender == Male) {
        printf("Mr. ");
    } else if (sturec->gender == Female) {
        printf("Ms. ");
    } 

    printf("%s\n", sturec->name);
    printf("Student ID: %9d @ %s Dept.\n", sturec->id, sturec->dept);

    printf("\n");
}

int main() {
    StudentRecord studentRecord[2];
    strcpy(studentRecord[0].name, "Sanghui Park");
    studentRecord[0].id = 201935044;
    strcpy(studentRecord[0].dept, "SW");
    studentRecord[0].gender = Male;

    printStudentRecord(&studentRecord[0]);

    StudentRecord wonPark = { "Won Park", 12345, "SW", Male };
    studentRecord[1] = wonPark;

    printStudentRecord(&studentRecord[1]);

    return 0;
}
