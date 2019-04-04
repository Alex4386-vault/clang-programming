#include <stdio.h>

int main() {
	int side1 = 0, side2 = 0;

	printf("Enter sides: ? ?\b\b\b");
	scanf_s("%d %d", &side1, &side2);

	for (int i = 0; i < side1; i++) {
		for (int j = 0; j < side2; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}