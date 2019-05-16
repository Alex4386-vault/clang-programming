#include <math.h>
#include <stdio.h>

int main() {

	printf("The coefficients of Quadratic Equation ax^2+bx+c=0 are a, b and c\n");
	printf("Enter values of a, b and c: ");
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);

	int theD = (b * b) - (4 * a * c);
	
	if (theD > 0) {
		// Two Root
		printf("Two real and different roots\n");
	}
	else if (theD == 0) {
		// One Root
		printf("Two real and same roots\n");

	}
	else {
		// Imaginary (Complex)
		printf("Two complex and different roots\n");

		return 0;
	}

	// Two Roots
	float theDSqrt = sqrt(theD);
	float root1 = (theDSqrt - b) / (float)(2 * a);
	float root2 = (-theDSqrt - b) / (float)(2 * a);

	printf("Roots are %f and %f\n", root1, root2);
	

	return 0;
}