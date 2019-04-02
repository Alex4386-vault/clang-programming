#include <stdio.h>
#include <stdlib.h>

int main() {
	int k = 0, count = 0;
	float grade = 0, total = 0;
	while (true) {
		printf("enter a grade: ?\b");
		scanf("%f", &grade);
		if (((0 >= grade) && (grade >= 100))) {
			count++;

			continue;
		}
		total += grade;
		k = k++;
		if (total >= 7500) {
			break;
		}
	}
	if (count == 0) {
		printf("total grades = %f, total inpuuuts: %d", total, k);
	}
	else {
		printf("invalid inputs = %d and total grades = %f, total inpuuuuuts: %d", count, total, k);
	}
}