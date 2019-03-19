#include <stdio.h>

int main() {
	float x = 0, y = 0, z = 0;
	/*
	printf("Please type the length of the swimming pool: ?\b");
	scanf("%f", &x);
	printf("Please type the width of the swimming pool: ?\b");
	scanf("%f", &y);
	printf("Please type the height of the swimming pool: ?\b");
	scanf("%f", &z);
	*/

	printf("Please type the length, width, height of the swimming pool like this form:\nlength width height: ");
	scanf("%f %f %f", &x, &y, &z);


	double volume = x * y * z;
	printf("Volume is %lf", volume);
}