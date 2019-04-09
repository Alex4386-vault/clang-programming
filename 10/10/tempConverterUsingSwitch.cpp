#include <stdio.h>

int main() {
	char FC;
	float F, C, temp;

	printf("type the temperature: ");
	scanf("%f", &temp);

	do {
		printf("is it Fahrenheit(F or f) or Celcius(C or c): ");
		scanf("%c", &FC);

		switch (FC) {
		case 'F':
		case 'f':
			F = (temp - 32.0) * 5.0 / 9.0; C = temp;
			break;
		case 'C':
		case 'c':
			C = temp; F = temp * 9.0 / 5.0 + 32;
			break;
		default:
			printf("Invalid Input\n");
			break;
		}
	} while (!(FC == 'F' || FC == 'f' || FC == 'C' || FC == 'c'));

	printf("Converted Temperature: %f¡É, %f¢µ", C, F);
}