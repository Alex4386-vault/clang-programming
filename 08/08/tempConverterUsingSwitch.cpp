#include <stdio.h>

int main() {
	int FC;
	float F, C, temp;

	printf("type the temperature: ?\b");
	scanf("%f", &temp);

	do {
		printf("is it Fahrenheit(1) or Celcius(2): ?\b");
		scanf("%d", &FC);

		switch(FC) {
		case 1:
			F = (temp - 32.0) * 5.0 / 9.0; C = temp;
			break;
		case 2:
			C = temp; F = temp * 9.0 / 5.0 + 32;
			break;
		default:
			printf("Invalid Input\n");
			break;
		}
	} while (!(FC == 1 || FC == 2));

	printf("Converted Temperature: %f¡É, %f¢µ", C, F);
}