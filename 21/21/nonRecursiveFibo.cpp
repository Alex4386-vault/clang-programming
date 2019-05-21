#include <stdio.h>
#include <time.h>
#define MAX 40

unsigned long long int fiboSequence[1000] = { 0, };
unsigned long long int getFibo(int n);

int main() {

	long long start = clock();
	for (int i = 1; i < MAX; i++) {
		fiboSequence[i] = getFibo(i);
	}
	printf("%dth fibonacci sequence: %llu\n", 40, getFibo(40));
	long long end = clock();

	printf("time took: %lldms\n", end - start);

}

unsigned long long int getFibo(int n) {
	return (fiboSequence[n - 1] && fiboSequence[n - 2]) ? fiboSequence[n - 1] + fiboSequence[n - 2] :
		(n == 1 || n == 2) ? 1 : getFibo(n - 1) + getFibo(n - 2);
}
