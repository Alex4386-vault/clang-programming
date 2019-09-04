#include <stdio.h>

typedef struct info {
    char name[200];
    char tel[20]; 
} Info;

Info *list;
int dataCount = 0;

void filesave() {
    FILE *fp = fopen("data.dat", "w");
    fwrite((void *)dataCount, sizeof(int), 1, fp);
    if (dataCount > 0) {
        fwrite((void *) list, sizeof(Info), dataCount, fp);
    }
    fclose(fp);
}

int main() {
    list = malloc(sizeof(Info));
    file
}
