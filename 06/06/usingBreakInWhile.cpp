#include <stdio.h>

int main() {
	float grade, total = 0;

	int bad = 0;
	while (1) {
		printf("\nEnter a grade: ??\b\b");
		scanf("%f", &grade);
		if (grade < 0 || grade > 100) {
			bad = 1;
			break;
		}
		total += grade;
	}

	if (bad == 0) {
		// Why are you here? You can't get here because there is no ending enter the grade
		printf("total grades = %f", total);
	}
	else {
		printf("There was an invalid grade");
	}
}