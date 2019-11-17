#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // open file pointer
    FILE *original = fopen("phone_book.txt", "r");
    FILE *compressed = fopen("compressed.txt", "w");

    // exception handling
    if (original == NULL) {
        printf("[ERROR] couldn't open phone_book.txt!\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }

    // exception handling
    if (compressed == NULL) {
        printf("[ERROR] couldn't open compressed.txt!\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }

    // set compression key
    char compressKey[10] = "77";

    // write the compression key at the beginning of the file.
    fprintf(compressed, "%s\n", compressKey);

    // define temporary character arrat for storing current line.
    char tmp[10] = "";

    // define a pointer to check for compressionKey and remove.
    for (char *a = tmp; !feof(original); a = tmp) {

        // read line from file.
        fgets(a, 10, original);

        // debug.
        // printf("%s %s", compressKey, tmp);

        // check beginning matches with compressKey.
        for (int i = 0; i < strlen(compressKey); i++) {
            // if it match, increase a which means that character is excluded from the output file.
            if (compressKey[i] == tmp[i]) {
                a++;
            } else {
            // else print inadequate compressKey and out.
                printf("inadequate compressKey!!!\n");
                return 1;
            }
        }

        //printf("output: %s \nNext:\n", a);

        // print to file.
        fprintf(compressed, "%s", a);

        // make first byte null, so basically cleaning tmp.
        tmp[0] = 0;
    }

    // close file pointer.
    fclose(original);
    fclose(compressed);
    return 0;
}