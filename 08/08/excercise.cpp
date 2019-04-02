#include <stdio.h>

int coursesPerStudent = 3, studentsInDept = 5;

int main() {
	int sum = 0;
	int deptTotal = 0;

	for (int i = 0; i < studentsInDept; i++) {
		int studentTotal = 0;
		for (int j = 0; j < coursesPerStudent; j++) {
			int score = 0;
			scanf("%d", &score);
			studentTotal += score;
		}
		printf("student average: %f\n", studentTotal / (float)coursesPerStudent);
		deptTotal += studentTotal;
	}

	printf("department average: %f\n", deptTotal / (float)(coursesPerStudent * studentsInDept));

}
