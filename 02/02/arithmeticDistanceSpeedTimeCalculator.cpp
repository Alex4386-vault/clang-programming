#include <stdio.h>

void main() {
	float distance, speed, time;

	printf("\nPlease type in the distance to travel: \n");
	scanf("%f", &distance);
	printf("\nPlease type in the average speed: \n");
	scanf("%f", &speed);

	time = distance / speed;
	printf("time: %f", time);
}