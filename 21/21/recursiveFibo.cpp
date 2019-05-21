#include <stdio.h>
#include <time.h>

unsigned long long fibo(int n) { return (n == 1 || n == 2) ? 1 : fibo(n - 1) + fibo(n - 2); }

int main() {
	int faf;
	scanf_s("%d", &faf);
	// Y2.038K prevention
	long long start = clock();
	printf("fibonacci(%d): %llu\n", faf, fibo(faf));
	// Y2.038K prevention
	long long end = clock();

	printf("time took: %lldms\n", end - start);
	return 0;
}
