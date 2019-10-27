#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[255];

    fp = fopen("file.txt", "w");
    if (!fp) {
        return 1;
    }

    fprintf(fp, "We are in 2019");

    fclose(fp);
    return 0;
}
 