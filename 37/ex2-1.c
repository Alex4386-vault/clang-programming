#include <stdio.h>

struct CAR {
    char name[20];
    int year;
};

const int length = 2;

int main() {
    FILE *fp;
    struct CAR cars[length] = {
        {"Avante", 2017},
        {"Sonata", 2012}
    };

    fp = fopen("cars.txt", "w");

    for (int i = 0; i < length; i++) {
        fprintf(fp, "%s %d\n", cars[i].name, cars[i].year);
    }

    fclose(fp);
}