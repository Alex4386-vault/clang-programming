#include <stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num);

	bool isPrime = true;
	for (int i = 2; i <= (num / 2); i++) {
		if (num % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) {
		printf("%d is prime!", num);
	} else {
		printf("NOPE.");
	}
}
