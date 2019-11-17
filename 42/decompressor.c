#include <stdio.h>

int main() {

    // open files
    FILE *comp = fopen("compressed.txt", "r");
    FILE *decomp = fopen("decompressed.txt", "w");

    // exception handling.
    if (comp == NULL) {
        printf("[ERROR] couldn't open compressed.txt!\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }

    // exception handling.
    if (decomp == NULL) {
        printf("[ERROR] couldn't open decompressed.txt!\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }

    // declare array for storing compression Key.
    char compressedKey[10];
    // get compression key from file.
    fgets(compressedKey, 10, comp);

    // if compressed key line contains line return at the end, change that to null.
    for (int i = 0; i < 10; i++) {
        if (compressedKey[i] == '\n') {
            compressedKey[i] = 0;
        }
    }

    // until end of the file.
    for (char a[10] = ""; !feof(comp); ) {
        // read line to a.
        fgets(a, 10, comp);
        //printf("%s%s", compressedKey, a);

        // output compressed key and a to file.
        fprintf(decomp, "%s%s", compressedKey, a);
    }

    // close files.
    fclose(comp);
    fclose(decomp);

    return 0;
}