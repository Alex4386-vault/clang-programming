#include <stdio.h>
#include <string.h>

/**
 * fill the buffer to 0 with specified size.
 * @param buffer the buffer you want to feel with NULL(0)
 * @param bufferSize the size of the buffer
 **/
void clearBuffer(char *buffer, int bufferSize) {
    // for all buffer indexes
    for (int i = 0; i < bufferSize; i++) {
        // save as 0 (NULL)
        buffer[i] = 0;
    }
    return;
}

/**
 * remove provided line-number from the
 * input file pointer and output it to output pointer
 * @param input input file pointer to remove the line (read mode)
 * @param output output file pointer to get file without specified line (write mode)
 * @param num line number you want to remove
 **/
void lineDeleter(FILE *input, FILE *output, int num) {
    // define buffer
    char buffer[1001] = {0,};

    for (int i = 1; !feof(input); i++) {

        // clear the buffer.
        clearBuffer(buffer, 1001);
        
        // debug purpose.
        //printf("%d... ", i);

        // get the string length of 1001 including NULL from input.
        fgets(buffer, 1001, input);

        // debug purpose 
        //printf("%s, ", buffer);

        // if this line is user defined one, skip.
        if (num == i) { continue; }

        // else output it to output file pointer.
        fputs(buffer, output);

        // debug purpose
        //printf("writing!\n");
    }
}

/**
 * Checks how many lines are available in the file
 * @param input the file pointer to check the line counts
 * @return how many lines are available in the file.
 **/
int howManyLines(FILE *input) {

    // loop purpose.
    int count = 1;

    // define buffer
    char buffer[1001] = {0,};

    // until eof
    for (count = 0; !feof(input); count++) {
        // read file to buffer.
        fgets(buffer, 1001, input);
    }
    
    // seek to begin of the file in order to make it easier for later use.
    fseek(input, 0, SEEK_SET);

    // return how many lines are available
    return count;
}

// main function
int main() {

    // open the input.txt file as read mode
    FILE* in = fopen("input.txt", "r");

    // exception handling: File I/O
    if (!in) {
        // user-friendly errormsg
        printf("[ERROR] Unable to read the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        // errorcode 1
        return 1;
    }

    // open the output.txt file as write mode
    FILE* out = fopen("output.txt", "w");

    // exception handling: File I/O
    if (!out) {
        // user-friendly errormsg
        printf("[ERROR] Unable to write the file.\nPlease check read permission or Disk's S.M.A.R.T.\n");
        // errorcode 1
        return 1;
    }

    // variable to save user requested line to remove
    int line = 0;

    // variable to save how many lines are in the file.
    int totalLine = howManyLines(in);

    // infinite loop until break.
    while(1) {

        // ask user to line number to delete
        printf("Enter line number to delete: ");
        scanf("%d", &line);

        // if line number is out of bounds.
        if (line <= 0 || line > totalLine) {
            // say its invalid and loop.
            printf("Invalid line number! Enter again!\n");
        } else {
            // else break.
            break;
        }
    }

    // call line Deleter
    lineDeleter(in, out, line);

    // close file pointers.
    fclose(in);
    fclose(out);

    return 0;
}