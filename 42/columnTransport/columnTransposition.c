#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // get the length of the password
    printf("Enter length of password: ");
    int passwordSize = 0;
    scanf("%d", &passwordSize);

    // ask user to enter password seperated by spaces
    printf("Please Enter password seperated by spaces: ");
    int *passwordList = (int *)malloc(sizeof(int) * passwordSize);
    for (int i = 0; i < passwordSize; i++) {
        scanf("%d", passwordList+i);
    }
    
    // open file
    FILE *input = fopen("original.txt", "r");
    FILE *output = fopen("cypher.txt", "w");

    // exception handling
    if (input == NULL || output == NULL) {
        printf("[ERROR] couldn't open file\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }
    
    // all the file has at least 1 line.
    int lineCount = 1;
    
    // for every line return was found, add lineCount
    for (char a = getc(input); !feof(input); a = getc(input)) {
        if (a == '\n') lineCount++;
    }

    // display user a linecount of the original file
    printf("LineCount: %d\n\n", lineCount);

    // due to linecount, current location is at the end.
    // seeking to the begining.
    fseek(input, 0, SEEK_SET);

    // define a row to store all the columns.
    char **row;
    row = (char **)malloc(sizeof(char *) * passwordSize);

    // exception handling
    if (row == NULL) return 1;

    // for every rows create columns.
    for (int i = 0; i < passwordSize; i++) {
        char *column;
        column = (char *)malloc(sizeof(char) * lineCount);
        
        // exception handling
        if (column == NULL) return 1;

        //initializing columns.
        for (int j = 0; j < lineCount; j++) {
            column[j] = ' ';
        }
        row[i] = column;
    }
    
    
    // for every line
    for (int i = 0; i < lineCount; i++) {
        char *a;

        

        //having extra size just in case it has multiple spaces.
        a = malloc(sizeof(char) * (3*passwordSize));
        
        // exception handling.
        if (a == NULL) return -1;

        fgets(a, 3*passwordSize, input);
        int k = 0;

        // for this line,
        for (int j = 0; j < strlen(a); j++) {
            // if it is space or line feed, skip. 
            if (a[j] == ' ' || a[j] == '\n' || a[j] == '\r') {
                continue;

            // if this is end of file, get out of loop.
            } else if (feof(input)) {
                break;

            } else {
                // else add to matrix.
                row[k][i] = a[j];
                k++;
            }

        }
        free(a);
    }

    // display to user.
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < passwordSize; j++) {
            printf("%c ", row[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    
    // create variable for storing cipherText
    char *cipherText;
    cipherText = (char *)malloc(sizeof(char) * passwordSize * lineCount);

    // variable to store which index of cipherText is currently being read.
    int cipherTextCount = 0;

    // loop 1-passwordSize to loop through columns.
    for (int i = 1; i <= passwordSize; i++) {

        int o;
        // for all column,
        for (o = 0; o < passwordSize; o++) {
            // if i is column of i-th in password, break.
            if (i == passwordList[o]) break;
        }

        // for current column,
        for (int j = 0; j < lineCount; j++) {
            // if it is space (which was initialization value, skip.)
            if (row[o][j] == ' ') {
                continue;
            }

            // add current index in the matrix to cipherText
            cipherText[cipherTextCount] = row[o][j];
            cipherTextCount++;
        }
    }

    // show cipher text to screen and write cipher text to file
    printf("%s\n", cipherText);
    fprintf(output, "%s", cipherText);

    // free ciphertext
    free(cipherText);

    // free all columns
    for (int i = 0; i < passwordSize; i++) {
        free(row[i]);
    }

    // free all un-freed memories.
    free(row);
    free(passwordList);

    // close file pointer
    fclose(input);
    fclose(output);

}
