#include <stdio.h>

void main() {
	int num1, num2, num3;

	printf("\nPlease type an integer: \n");
	scanf("%d", &num1);
	printf("\nPlease type another integer: \n");
	scanf("%d", &num2);

	num3 = num1 + num2;
	printf("result = %d", num3);
}