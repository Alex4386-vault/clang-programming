#include <stdio.h>

int main() {
	int a = 19308, b = 38431;

	printf("a=%d, b=%d\n", a, b);

	a += b;
	b = a - b;
	a -= b;

	printf("a=%d, b=%d\n", a, b);
}