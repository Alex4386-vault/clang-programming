#include <stdio.h>

int main() {
	int oddSum = 0, evenSum = 0;
	for (int i = 0; i < 5; i++) {
		int o;
		scanf("%d", &o);
		if (o % 2 == 0) {
			evenSum += o;
		} else {
			oddSum += o;
		}
	}
	printf("oddSum: %d, evenSum: %d", oddSum, evenSum);
}