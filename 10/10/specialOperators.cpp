#include <stdio.h>

int main() {
	int a = 10, b = 2;

	printf("a=%d, b=%d\n", a, b);

	printf("a += b\n");
	a += b;

	printf("a=%d, b=%d\n", a, b);

	printf("a -= b\n");
	a -= b;

	printf("a=%d, b=%d\n", a, b);

	printf("a *= b\n");
	a *= b;

	printf("a=%d, b=%d\n", a, b);
	
	printf("a /= b\n");
	a /= b;

	printf("a=%d, b=%d\n", a, b);
	
	printf("a %%= b\n");
	a %= b;

	printf("a=%d, b=%d\n", a, b);

	return 0;
}