#include <stdio.h>

// Use this only your solution if you are using MSBUILD and SDL Check is enabled.
#define scanf scanf_s

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
