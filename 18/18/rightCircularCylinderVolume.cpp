#define PI 3.141592653589793238462643383

float rightCircCylVolume(float radius, float height) {
	return PI * (radius * radius) * height;
}

#include <stdio.h>
void rightCircCylVolumeCaller() {
	float radius, height;
	printf("Enter Radius: ");
	scanf_s("%f", &radius);

	printf("Enter Height: ");
	scanf_s("%f", &height);

	printf("\nVolume: %f", rightCircCylVolume(radius, height));
}