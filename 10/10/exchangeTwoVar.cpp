#include <stdio.h>

int main() {
	int a = 19308, b = 38431;

	printf("a=%d, b=%d\n", a, b);

	int tmp = a;
	a = b;
	b = tmp;

	printf("a=%d, b=%d\n", a, b);
}