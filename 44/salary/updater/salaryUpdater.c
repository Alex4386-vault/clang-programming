#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* common */

FILE *safeFileOpen(char *fileName, char* fileMode) {
    FILE *fp = fopen(fileName, fileMode);
    if (fp == NULL) {
        printf("Failed to open %s! Check the file permission or Disk S.M.A.R.T.!\n", fileName);
        exit(1);
    }

    return fp;
}

void *safeMemoryAllocation(size_t size) {
    void *memAddr = (void *)malloc(size);
    if (memAddr == NULL) {
        printf("Failed to allocate memory! Check is it out of memory!");
        exit(1);
    }
    return memAddr;
}

int howManyLines(FILE *input) {
    long a = ftell(input);
    int count = 1;
    fseek(input, 0, SEEK_SET);
    for (char c = 0; !feof(input); c=getc(input)) {
        if (c == '\n') {
            count++;
        }
    }
    fseek(input, a, SEEK_SET);

    return count;
}

/* struct */
struct PersonalInfo {
    char name[10];
    int age;
    float salary;
};

int main() {
    FILE *fp = safeFileOpen("salary_v1.txt", "r");

    int lineCount = howManyLines(fp);
    
    struct PersonalInfo *data = safeMemoryAllocation(sizeof(struct PersonalInfo) * lineCount);

    for (int i = 0; i < lineCount; i++) {
        char name[10] = "";
        int age = 0;
        float salary = 0.0;

        fscanf(fp, "%s %d %f", name, &age, &salary);
        strcpy(data[i].name, name);
        data[i].age = age;
        data[i].salary = salary;
    }

    fclose(fp);

    /* main Decomposing algorithm */
    FILE *v2 = safeFileOpen("salary_v2.txt", "w");
    
    for (int j = 0; j < lineCount; j++) {
        if (40 <= data[j].age && data[j].age <= 49) {
            data[j].salary *= 1.1;
        }
        fprintf(v2, "%s %d %.1f\n", data[j].name, data[j].age, data[j].salary);
    }

    fclose(v2);
    free(data);

    v2 = safeFileOpen("salary_v2.txt", "r");
    lineCount = howManyLines(v2);
    data = safeMemoryAllocation(sizeof(struct PersonalInfo) * lineCount);

    for (int i = 0; i < lineCount; i++) {
        char name[10] = "";
        int age = 0;
        float salary = 0.0;

        fscanf(fp, "%s %d %f", name, &age, &salary);
        strcpy(data[i].name, name);
        data[i].age = age;
        data[i].salary = salary;
    }

    fclose(v2);

    /* main Decomposing algorithm */
    FILE *v3 = safeFileOpen("salary_v3.txt", "w");

    for (int j = 0; j < lineCount; j++) {
        if (30 <= data[j].age && data[j].age <= 39) {
            data[j].salary *= 1.2;
        }
        fprintf(v3, "%s %d %.1f\n", data[j].name, data[j].age, data[j].salary);
    }

    fclose(v3);
    free(data);

}