#include <stdio.h>

int main() {
	int a = 0, b = 0;
	++a;
	++b;

	printf("a=%d, b=%d\n", a, b);
	b = a++; // b = a, a = a+1
	printf("a=%d, b=%d\n", a, b);
	b = ++a; // a = a+1, b = a
	printf("a=%d, b=%d\n", a, b);

	printf("a=%d, b=%d\n", a++, b++);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}