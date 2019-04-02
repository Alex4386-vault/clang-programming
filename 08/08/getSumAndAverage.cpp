#include <stdio.h>

int max = 5;

int main() {
	int count = 0;
	float total = 0;

	/*
	while (count < max) {
		float num = 0;
		printf("Enter a Number: ?\b");
		scanf("%f", &num);
		total += num;
		count++;
	}
	*/
	do {
		float num = 0;
		printf("Enter a Number: ?\b");
		scanf("%f", &num);
		total += num;
		count++;
	} while (count < max);

	float average = total / max;
	printf("average: %f", average);
}