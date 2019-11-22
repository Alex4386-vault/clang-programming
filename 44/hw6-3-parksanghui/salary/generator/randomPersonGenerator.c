// This is not a main file, so this is not required to make a comment.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Person {
    char name[10];
    int age;
    float salary ;
} Person;

char names[10][10] = {
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

FILE *safeFileOpen(char *fileName, char* fileMode) {
    FILE *fp = fopen(fileName, fileMode);
    if (fp == NULL) {
        printf("Failed to open %s! Check the file permission or Disk S.M.A.R.T.!\n", fileName);
        exit(1);
    }

    return fp;
}

Person personGenerator() {
    Person person = {
        "",
        (int)(rand() % 40 + 10),
        (int)((rand() % 120) * 10000)
    };
    strcpy(person.name, names[rand() % 10]);
    return person;
}

int main() {
    srand(time(NULL));
    FILE *fp = safeFileOpen("salary_v1.txt", "w");

    int howMany = 0;
    scanf("%d", &howMany);

    for (int  i = 0; i < howMany; i++) {
        Person person = personGenerator();
        fprintf(fp, "%s %d %.1f\n", person.name, person.age, person.salary);
    }

    fclose(fp);
}
