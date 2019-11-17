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
    char hobby[10];
};

int main() {
    FILE *fp = safeFileOpen("personal.txt", "r");

    int lineCount = howManyLines(fp);
    
    struct PersonalInfo *data = safeMemoryAllocation(sizeof(struct PersonalInfo) * lineCount);

    for (int i = 0; i < lineCount; i++) {
        char name[10] = "";
        int age = 0;
        char hobby[10] = "";

        fscanf(fp, "%s %d %s", name, &age, hobby);
        strcpy(data[i].name, name);
        data[i].age = age;
        strcpy(data[i].hobby, hobby);
    }

    /* main Decomposing algorithm */
    FILE *out = safeFileOpen("output.txt", "w");
    
    for (int i = 1; i <= 4; i++) {
        fprintf(out, "Age from %d to %d\n", i*10, i*10+9);
        fprintf(out, "--------------------\n");
        for (int j = 0; j < lineCount; j++) {
            if (i*10 <= data[j].age && data[j].age <= i*10+9) {
                fprintf(out, "%s %d %s\n", data[j].name, data[j].age, data[j].hobby);
            }
        }
        fprintf(out, "\n");
    }

    fclose(out);
    fclose(fp);
    free(data);


}