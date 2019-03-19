#include <stdio.h>
#define PI 3.141592653589793138462643383

int main() {
	float r = 0, h = 0;

	printf("Please type the radius, height of circular cylinder like this form:\nradius height: ");
	scanf("%f %f", &r, &h);


	double volume = PI * r * r * h;
	printf("Volume is %lf", volume);
}