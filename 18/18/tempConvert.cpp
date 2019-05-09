#include <stdio.h>
#include "tempConvert.h"

void tempConvertCaller() {
	char FC;
	float temp;

	printf("Which Scale? (F/C): ?\b");
	scanf_s("%c", &FC);
	printf("Type temperature: ?\b");
	scanf_s("%f", &temp);

	printf("%f¡Æ%c", tempConvert(FC, temp), (FC == 'C') ? 'F' : (FC == 'F') ? 'C' : 'E');
}

float tempConvert(char FC, float temp) {
	return (FC == 'F') ? (temp - 32) * (5.0 / 9.0) : (FC == 'C') ? (temp * 9.0) / 5.0 + 32 : NULL;
}