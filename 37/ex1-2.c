#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("file.txt", "r");
    if (!fp) {
        return 1;
    }

    char buffer[255];
    for (int i = 1; i < 4; i++) {
        fscanf(fp, "%s", buffer);
        printf("Read String%d [%s]\n", i, buffer);
    }
    int temp = 0;
    fscanf(fp, "%d", &temp);
    printf("Read Integer [%d]\n", temp);

    return -1;
}