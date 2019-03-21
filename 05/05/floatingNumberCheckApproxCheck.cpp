#include <stdio.h>

int main() {
	double a, b;
	double approx;
	scanf("%lf %lf", &a, &b);
	if ((a - b) < 0.001 && (a - b) > -0.001) {
		approx = 0;
	}
	else {
		approx = (a - b) / 2.0;
	}
	printf("%lf", approx);
}