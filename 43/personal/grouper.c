#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* common */

// open file, when it failed, exit the program
FILE *safeFileOpen(char *fileName, char* fileMode) {
    FILE *fp = fopen(fileName, fileMode);
    if (fp == NULL) {
        printf("Failed to open %s! Check the file permission or Disk S.M.A.R.T.!\n", fileName);
        exit(1);
    }

    return fp;
}

// malloc but when it failed, exit the program
void *safeMemoryAllocation(size_t size) {
    void *memAddr = (void *)malloc(size);
    if (memAddr == NULL) {
        printf("Failed to allocate memory! Check is it out of memory!");
        exit(1);
    }
    return memAddr;
}


// Check how many line return characters are found in the file
int howManyLines(FILE *input) {

    // current location of file
    long a = ftell(input);

    // files have at least 1 lines
    int count = 1;

    // go to beginning
    fseek(input, 0, SEEK_SET);

    // for all characters
    for (char c = 0; !feof(input); c=getc(input)) {
        // if line return increas 1
        if (c == '\n') {
            count++;
        }
    }

    // to the previous location
    fseek(input, a, SEEK_SET);

    return count;
}

// free all dynamically allocated double pointer
void freeAll(void **ptr, int length) {
    for (int i = 0; i < length; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

/* age */

// get ages from the file.
int *getAges(FILE *input) {

    // save location temporaril;y
    long loc = ftell(input);
    
    // go to beginning.
    fseek(input, 0, SEEK_SET);

    // get lines
    int lines = howManyLines(input);

    // get ages array
    int *ages = (int *)safeMemoryAllocation(sizeof(int) * lines);
    
    // initalize
    for (int i = 0; i < lines; i++) {
        ages[i] = -1;
    }

    // temporary variables
    char name[10] = "";
    int age = 0;
    char hobby[10] = "";

    // current Age index to save at ages array
    int currentAgesIndex = 0;

    // for each lines
    for (fscanf(input, "%s %d %s\n", name, &age, hobby); !feof(input); fscanf(input, "%s %d %s\n", name, &age, hobby)) {
        
        // tmp variable to check this ahge is already included
        char isIncluded = 0;

        // until end of the ages array
        for (int i = 0; i < lines && ages[i] >= 0; i++) {

            // if found, update isIncluded
            if (ages[i] == age) {
                isIncluded = 1;
            }
        }

        // add if it is not found.
        if (!isIncluded) {
            ages[currentAgesIndex] = age;
            currentAgesIndex++;
        }
    }

    // return to location specified
    fseek(input, loc, SEEK_SET);
    return ages;
}

// group by ages
int groupByAge(FILE *input) {
    // go to beginning
    fseek(input, 0, SEEK_SET);

    // read line and ages.
    int lines = howManyLines(input);
    int *ages = getAges(input);

    // open file "age.txt" to save
    FILE *fp = (FILE *)safeFileOpen("age.txt", "w");
    
    // for all lines
    for (int i = 0; i < lines && ages[i] >= 0; i++) {

        // temporary variable.
        int currentAge = ages[i];
        char name[10] = "";
        int age = 0;
        char hobby[10] = "";

        // read all line.
        for (fscanf(input, "%s %d %s\n", name, &age, hobby); !feof(input); fscanf(input, "%s %d %s\n", name, &age, hobby)) {
            // if age is current Age, write
            if (age == currentAge) {
                fprintf(fp, "%s %d %s\n", name, age, hobby);
            }
        }

        // goto beginning.
        fseek(input, 0, SEEK_SET);
    }
    fclose(fp);
    free(ages);

    return 0;
}

// max length for individual hobbies
const int hobbiesLength = 10;

// get Hobbies for 
char **getHobbies(FILE *input) {
    // save current location tmp.
    long loc = ftell(input);
    
    // go to beginning.
    fseek(input, 0, SEEK_SET);

    // read lines
    int lines = howManyLines(input);
    // allocate memory for string pointer
    char **hobbies = (char **)safeMemoryAllocation(sizeof(char *) * lines);
    // initialize each index
    for (int i = 0; i < lines; i++) {
        hobbies[i] = (char *)safeMemoryAllocation(sizeof(char) * hobbiesLength);
        strcpy(hobbies[i], "");
    }
    
    // tmp variable
    char name[10] = "";
    int age = 0;
    char hobby[10] = "";

    // tmp variable to current Hobbies index
    int currentHobbiesIndex = 0;

    // for each lines, read info
    for (fscanf(input, "%s %d %s\n", name, &age, hobby); !feof(input); fscanf(input, "%s %d %s\n", name, &age, hobby)) {
        
        // check it is included.
        char isIncluded = 0;

        // for all hobbies, check it is included in the hobbies array
        for (int i = 0; i < lines && hobbies[i][0] != 0; i++) {
            if (!strcmp(hobbies[i], hobby)) {
                isIncluded = 1;
            }
        }

        // if it is not included, add to list.
        if (!isIncluded) {
            strcpy(hobbies[currentHobbiesIndex], hobby);
            currentHobbiesIndex++;
        }
    }

    // return to previously saved location.
    fseek(input, loc, SEEK_SET);
    return hobbies;
}

// function to group by hobby.
int groupByHobby(FILE *input) {

    // go to beginning.
    fseek(input, 0, SEEK_SET);

    // read lines
    int lines = howManyLines(input);

    // read hobbies
    char **hobbies = getHobbies(input);

    // rfile pointer
    FILE *fp = (FILE *)safeFileOpen("hobby.txt", "w");

    // for all hobbies
    for (int i = 0; i < lines && strcmp(hobbies[i], ""); i++) {
        
        // tmp variable to save current looping hobby.
        char *currentHobby = hobbies[i];

        // tmp variable
        char name[10] = "";
        int age = 0;
        char hobby[10] = "";

        // read current line until end 
        for (fscanf(input, "%s %d %s\n", name, &age, hobby); !feof(input); fscanf(input, "%s %d %s\n", name, &age, hobby)) {
            // check current hobby at hobbies 
            if (!strcmp(hobby, currentHobby)) {
                fprintf(fp, "%s %d %s\n", name, age, hobby);
            }
        }

        // go to beginning
        fseek(input, 0, SEEK_SET);
    }

    // close file
    fclose(fp);

    // free all hobbies
    freeAll((void **)hobbies, lines);

    return 0;
}

int main() {

    // open file
    FILE *fp = safeFileOpen("personal.txt", "r");

    // ask user which you want to group
    printf("Group by which? (a for age, h for hobby) : ");

    // save command
    char cmd;

    // read char from cmd.
    cmd = fgetc(stdin);

    // flush stdin.
    fflush(stdin);

    // if user wants to classify via age
    if (cmd == 'a' || cmd == 'A') {
        return groupByAge(fp);

    // if user wants to classify via hobby
    } else if (cmd == 'h' || cmd == 'H') {
        return groupByHobby(fp);

    // wrong command.
    } else {
        printf("Wrong command! Exiting....\n");
        exit(0);
    }

}
