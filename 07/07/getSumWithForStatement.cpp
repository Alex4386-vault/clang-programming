#include <stdio.h>

int main() {
	int sum = 0;

	for (int k = 1; k <= 5; k++) {
		int input = 0;
		printf("Enter number: ?\b");
		scanf("%d", &input);
		sum += input;
	}

	printf("sum is %d\n", sum);
}