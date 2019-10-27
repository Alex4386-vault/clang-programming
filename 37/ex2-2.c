#include <stdio.h>
#include <stdlib.h>

struct CAR {
    char name[20];
    int year;
};

const int length = 2;

int main() {
    FILE *fp;
    fp = fopen("cars.txt", "r");

    struct CAR **cars = (struct CAR **)malloc(sizeof(struct CAR *) * length); 
    if (!cars) {
        return -1;
    }

    for (int i = 0; i < length; i++) {
        cars[i] = malloc(sizeof(struct CAR));
        if (!cars[i]) {
            return -1;
        }
    }

    for (int i = 0; i < length; i++) {
        fscanf(fp, "%s %d", cars[i]->name, &cars[i]->year);
        printf("%s\t%d\n", cars[i]->name, cars[i]->year);
    }

    fclose(fp);
}
