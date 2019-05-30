#include <stdio.h>

void absArray(double in[], int size) {
    for (int i = 0; i < size; i++) {
        in[i] = (in[i] < 0) ? -1 * in[i] : in[i];
    }
}

int main() {
    double a[3] = {1.2, -1.2, 0};
    absArray(a, 3);

    printf("%lf %lf %lf\n", a[0], a[1], a[2]);
}