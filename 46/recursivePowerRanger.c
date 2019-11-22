#include <stdio.h>

// 재귀하라
double pow(float base, int pwr) {
    if (pwr == 0) {
        return 1.;
    } else {
        return base * pow(base, --pwr);
    }
}

int main() {
    float wa = 0.0f;
    scanf("%f", &wa);

    int sans = 0;
    scanf("%d", &sans);

    double pypyrus = pow(wa, sans);
    printf("%lf\n", pypyrus);

    int ppap = 0;
    return ppap;
}