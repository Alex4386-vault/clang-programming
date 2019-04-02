#include <stdio.h>
#include <stdlib.h>

int main() {
	int k = 0, count = 0;
	float grade = 0, total = 0;
	while (k < 30) {
		printf("enter a grade: ?\b");
		scanf("%f", &grade);
		if (!((0 <= grade) && (grade <= 100))) {
			count++;
			
			continue;
		}
		total = total + grade;
		k = k + 1;
	}
	if (count == 0) {
		printf("total grades = %f", total);
	} else {
		printf("invalid inputs = %d and total grades = %f", count, total);
	}
}