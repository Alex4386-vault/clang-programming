#include <stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num);

	bool isPrime = true;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) {
		printf("소수 입니다.");
	} else {
		printf("아니거든.");
	}
}
