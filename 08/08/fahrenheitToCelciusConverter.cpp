#include <stdio.h>

int main() {
	int FC;
	float F, C, temp;

	printf("type the temperature: ?\b");
	scanf("%f", &temp);

	do {
		printf("is it Fahrenheit(1) or Celcius(2): ?\b");
		scanf("%d", &FC);

		if (FC == 1) {
			F = (temp - 32.0) * 5.0 / 9.0; C = temp;
		}
		else if (FC == 2) {
			C = temp; F = temp * 9.0 / 5.0 + 32;
		}
		else
			printf("\nInvalid Input");
	} while (!(FC == 1 || FC == 2));

	printf("Converted Temperature: %f¡É, %f¢µ", C, F);
}