#include <stdio.h>

int main() {
	float grade, total = 0;

	do {
		printf("\nEnter a grade: ??\b\b");
		scanf("%f", &grade);
		total += grade;
	} while (grade >= 0 && grade <= 100);

	printf("There was an invalid grade");
}