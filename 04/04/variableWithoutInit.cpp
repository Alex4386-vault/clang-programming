#include <stdio.h>

int main() {
	float avg, total;
	int num_students;

	// conversion : total(float) = 40120(int)
	
	// Implicit Conversion
	total = 40120;
	
	// Type-Casting Conversion : Explicit Conversion
	char a = (char)total;
	printf("%d", a);

	// Expected Results:
	// Run-Time Check Failure #3 - The variable 'num_students' is being used without being initialized.
	// avg = total / num_students;

	return 0;
}