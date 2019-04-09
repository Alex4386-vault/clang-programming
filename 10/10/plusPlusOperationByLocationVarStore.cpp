#include <stdio.h>

int main() {
	int a = 10, b = 10, front, back;
	front = ++a * 5;
	back = b++ * 5;

	printf("a=%d, b=%d\n", a, b);
	printf("++a=%d, b++=%d", front, back);

	return 0;
}