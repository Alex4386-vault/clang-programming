#include <stdio.h>

int main() {
	double GPA;
	int scholarship;

	printf("Type your GPA: ?\b");
	scanf("%lf", &GPA);

	// Validity Check
	if (GPA > 4.5 || GPA < 0) {
		printf("Invalid GPA!!!!");
		return 0;
	}

	if (GPA >= 3.5) {
		scholarship = 1000000;
		printf("congratulations");
	}
	else printf("study harder");

	return 0;
}