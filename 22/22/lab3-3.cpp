#include <stdio.h>
#include <Math.h>

#define PI 3.141592

double a,b,c;

void square() { printf("%lf", pow(a, 2)); }
void circle() { printf("%lf", pow(a, 2) * PI); }
void triangle() {
	scanf_s("%lf", &b);
	scanf_s("%lf", &c);
	double s = (a + b + c) / 2;
	double val = s * (s - a) * (s - b) * (s - c);
	if (val < 0) {
		printf("We cannot make triangle with current input values");
	}
	else {
		printf("%lf", sqrt(val));
	}
}

int main() {
	int menu = 0;
	do {
		printf("Select Menu: ");
		scanf_s("%d", &menu);
	} while (menu != 1 && menu != 2 && menu != 3);

	scanf_s("%lf", &a);
	switch (menu) {
		case 1:
			square();
			break;
		case 2:
			circle();
			break;
		case 3:
			triangle();
			
			break;
	}

	return 0;
}