#include <stdio.h>

// Use this only your solution if you are using MSBUILD and SDL Check is enabled.
#define scanf scanf_s

int main() {
	int palin = 0;
	bool isPalin = true;
	scanf("%d", &palin);

	int temp = palin, digits[5] = { 0, }, j = 0;
	for (int i = 10000; i > 0; i /= 10) {
		digits[j] = temp / i;
		temp -= (i * digits[j]);
		j++;
	}

	for (int i = 0; i < 2; i++) {
		if (digits[i] != digits[4 - i]) {
			isPalin = false;
		}
	}

	if (isPalin) {
		printf("%d is a palindrome", palin);
	}
}
