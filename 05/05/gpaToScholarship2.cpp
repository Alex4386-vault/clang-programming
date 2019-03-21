#include <stdio.h>

int main() {
	double GPA;
	double scholarship;

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
	else if (GPA > 3.0) scholarship = 100000;
	else printf("study harder");

	printf("GPA = %f and scholarship = %f", GPA, scholarship);

	return 0;
}