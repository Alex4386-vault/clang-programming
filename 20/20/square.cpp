#include <stdio.h>

int square(int x);

int main() {
	for (int i = 1; i <= 10; i++) {
		printf("%d ", square(i));
	}
	return 0;
}

int square(int x) {
	return x * x;
}