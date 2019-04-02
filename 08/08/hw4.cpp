#include <stdio.h>

int main() {
	float base = 0;
	int exp = 0;
	scanf("%f %d", &base, &exp);

	if (exp <= 0) {
		return 0;
	}

	float result = 1;

	for (int i = 0; i < exp; i++) {
		result *= base;
	}

	printf("%f", result);
}
