#include <stdio.h>

unsigned long long factorial(int i) { return (i == 0) ? 1 : factorial(i-1) * i; }

int main() {
	int faf;
	scanf_s("%d", &faf);
	printf("factorial(%d): %llu\n", faf, factorial(faf));
	return 0;
}
