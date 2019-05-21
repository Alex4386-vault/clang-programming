#include <stdio.h>
#include <math.h>
#define count 10

double totalCalc(double* a, int size) { double total = 0.0; while(size--) { total += a[size]; } return total; }
double meanCalc(double* a, int size) { return totalCalc(a, size) / size; }
double diffCalc(double* a, int size) { double mean = meanCalc(a, size); double diff = 0; int b = size; while (size--) { diff += pow(a[size] - mean, 2); } return diff / b; }

int main() {
	double a[10] = { 0.0, };
	double total = 0.0;

	for (int i = 0; i < count; i++) {
		scanf_s("%lf", &a[i]);
		total += a[i];
	}

	double mean = meanCalc(a, count);
	double diff = diffCalc(a, count);
	double stdDev = sqrt(diff);

	printf("mean: %lf, difference: %lf, standard deviation: %lf", mean, diff, stdDev);



	return 0;
}
