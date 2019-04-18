#include <stdio.h>

int main() {
	int counts[5] = { 0, };

	while (true) {
		int input = -2;
		printf("Enter a numeric grade: ");
		scanf_s("%d", &input);

		char grade;
		switch (input) {
			case 4:
				grade = 'A';
				break;
			case 3:
				grade = 'B';
				break;
			case 2:
				grade = 'C';
				break;
			case 1:
				grade = 'D';
				break;
			case 0:
				grade = 'F';
				break;
			case -1:
				grade = 'H';
				break;
			default:
				grade = 'G';
				break;
		}

		if (grade == 'G') {
			printf("You can only type 1 or 2 or 3 or 4.\n");
			continue;
		} else if (input == -1) {
			printf("\nThe totals for converted letter grade are:\n");
			printf("A: %d\n", counts[4]);
			printf("B: %d\n", counts[3]);
			printf("C: %d\n", counts[2]);
			printf("D: %d\n", counts[1]);
			printf("F: %d\n", counts[0]);
			break;

		} else {
			printf("You got %c.\n", grade);
			counts[input]++;
		}


	}

}