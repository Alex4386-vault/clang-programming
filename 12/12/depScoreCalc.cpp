#include <stdio.h>

#define STU_SIZE 5
#define COU_SIZE 3

int main() {
	int grade[5][3] = { {0,}, };
	int total = 0;
	int studentStartTotal = 0;

	for (int stuCode = 0; stuCode < STU_SIZE; stuCode++) {
		printf("student Code #%d: ", stuCode);
		for (int couCode = 0; couCode < COU_SIZE; couCode++) {
			scanf("%d", &grade[stuCode][couCode]);
			total += grade[stuCode][couCode];
		}
	}

	printf("\n");
	printf("Student Averages:\n");
	for (int stuCode = 0; stuCode < STU_SIZE; stuCode++) {
		int couScoreTotal = 0;
		for (int couCode = 0; couCode < COU_SIZE; couCode++) {
			couScoreTotal += grade[stuCode][couCode];
		}
		printf("student Code #%d average: %f\n", stuCode, ((float)couScoreTotal / COU_SIZE));
	}

	printf("\n");
	printf("Course Averages:\n");
	for (int couCode = 0; couCode < COU_SIZE; couCode++) {
		int stuScoreTotal = 0;
		for (int stuCode = 0; stuCode < STU_SIZE; stuCode++) {
			stuScoreTotal += grade[stuCode][couCode];
		}
		printf("course Code #%d average: %f\n", couCode, ((float)stuScoreTotal / STU_SIZE));
	}

	return 0;
}