#include <stdio.h>

float taxRate = 0.65;

int main() {
	float salesTax, price;

	do {
		scanf("%f", &price);

		salesTax = taxRate * price;
	} while (price >= 0.2);
}