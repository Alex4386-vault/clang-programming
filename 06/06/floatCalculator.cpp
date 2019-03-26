#include <stdio.h>

int main() {
	int trial = 0, i = 25;
	float num = 0;
	while (trial < i) {
		float j;
		scanf("%f", &j);
		num = num + j;
		trial++;
	}
	printf("sum: %f, average: %f", num, num / i);
}