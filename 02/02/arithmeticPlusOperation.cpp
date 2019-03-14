#include <stdio.h>

int requestValues(int count);


void main() {
	/*
	int num1, num2, num3;

	printf("\nPlease type an integer: \n");
	scanf("%d", &num1);
	printf("\nPlease type another integer: \n");
	scanf("%d", &num2);

	num3 = num1 + num2;
	printf("result = %d", num3);
	*/

	char whichArith;
	int a = 0, b = 0;

	printf("Let's do some math!\n");
	printf("which arithmetic operation you want to do?\n\n");
	printf("+ - * /\n\n");
	printf("Enter your choice: ?\b");

	scanf("%c", &whichArith);
	printf("\n");

	a = requestValues(1);
	b = requestValues(2);

	switch (whichArith) {
	case '+':
		printf("result: %d", a + b);
		break;
	case '-':
		printf("result: %d", a - b);
		break;
	case '*':
		printf("result: %lf", a * b);
		break;
	case '/':
		printf("result: %lf", a / b);
		break;
	}
}

int requestValues(int count) {
	int a = 0;
	if (count == 1) {
		printf("first value: ?\b");
	} else if (count == 2) {
		printf("second value: ?\b");
	} else {
		return 0;
	}
	scanf("%d", &a);
	printf("\n");
	return a;
}