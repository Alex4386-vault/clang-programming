#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // open file
    FILE *input = fopen("cypher.txt", "r");
    FILE *output = fopen("decrypted.txt", "w");

    // exception handling
    if (input == NULL || output == NULL) {
        printf("[ERROR] couldn't open file\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }

    // get file size
    fseek(input, 0, SEEK_END);
    // adding 1 because it counts from 0
    long long int size = ftell(input) + 1;
    // go back to beginning
    fseek(input, 0, SEEK_SET);

    // satilizing ciphertext - creating memory section
    char *rawCipherText = (char *)malloc(sizeof(char) * size);
    char *cipherText = (char *)malloc(sizeof(char) * size);

    // exception handling
    if (rawCipherText == NULL || cipherText == NULL) return -1;

    //get cipher text
    fgets(rawCipherText, size, input);
    // for all characters
    for (int i = 0, k = 0; i < size; i++) {
        // ignore line return, carrige return and spaces.
        if (rawCipherText[i] == ' ' || rawCipherText[i] == '\r' || rawCipherText[i] == '\n') {
            continue;
        } else {
            // for every charcter that passed the test goes to satilized ciphertext variable
            cipherText[k] = rawCipherText[i];
            k++;
            // setting NULL at end in advance.
            cipherText[k] = 0;
        }
    }

    // rawciphertext is no longer required. freeing memory
    free(rawCipherText);
    // check length of the ciphertext
    int length = strlen(cipherText);

    // get length of password.
    int passwordLength = 0;
    printf("Enter the length of the password : ");
    scanf("%d", &passwordLength);

    // get password from user 
    // create passwordList variable to store password
    int *passwordList = (int *)malloc(sizeof(int) * passwordLength);

    // exception handling
    if (passwordList == NULL) return -1;

    // show prompt
    printf("Enter password seperated by spaces : ");

    // and save it to passwordList.
    for (int i = 0; i < passwordLength; i++) {
        scanf("%d", passwordList+i);
    }

    // check there is null characters at the end to meet the passwordLength
    // else lasts will have extended columns.
    char isNullCipher = (length % passwordLength == 0);
    
    // basic line counts for non-extended columns
    int baseLineCount = (int)(length / passwordLength);
    // line counts for extended columns
    int lineCount = isNullCipher ? (int)(length / passwordLength) : (int)(length / passwordLength) + 1;

    // the section to store columns and rows.
    char **row = (char **)malloc(sizeof(char *) * passwordLength);

    // exception handling
    if (row == NULL) return -1;

    // initializing and allocating columns to rows.
    for (int i = 0; i < passwordLength; i++) {
        char *column = (char *)malloc(sizeof(char) * lineCount);

        // exception handling
        if (column == NULL) return -1;

        //initialzing columns.
        for (int j = 0; j < lineCount; j++) {
            column[j] = ' ';
        }
        row[i] = column;
    }

    // variable to store which index of the ciphertext is currently reading.
    int currentCipherIndex = 0;

    // precendence loop. 1 to passwordLength
    for (int i = 1; i <= passwordLength; i++) {
        int k = -1;
        // check which column has most precedence
        for (int j = 0; j < passwordLength; j++) {
            // if this is it, save current index and break the loop.
            if (passwordList[j] == i) {
                k = j;
                break;
            }
        }
        // if it was not found. terminate the program.
        if (k == -1) return -1;

        // get cipher text and put it until the line limit reqched.
        for (int j = 0; j < baseLineCount; j++) {
            row[k][j] = cipherText[currentCipherIndex];
            currentCipherIndex++;
        }

        // this logic is only for extended columns which requires more rows
        // than other columns.
        if (!isNullCipher && passwordLength - i < (length % passwordLength)) {
            row[k][lineCount - 1] = cipherText[currentCipherIndex];
            currentCipherIndex++;
        }
    }

    // show and export it to text file. for each rows.
    for (int i = 0; i < lineCount; i++) {

        // display each columnns and
        for (int j = 0; j < passwordLength; j++) {
            printf("%c ", row[j][i]);
            fprintf(output, "%c ", row[j][i]);
        }

        // line return.
        printf("\n");

        
        fprintf(output, "\n");
        
    }
    
    // free all the columns.
    for (int i = 0; i < passwordLength; i++) {
        free(row[i]);
    }
    // rows and all the variables that was required.
    free(row);
    free(cipherText);
    free(passwordList);

    // close file pointer.
    fclose(input);
    fclose(output);
}