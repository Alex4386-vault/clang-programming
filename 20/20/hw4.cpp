#include <stdio.h>

int main() {
	printf("Enter the character to fill the rectangle: ");

	char rect_filler;
	scanf_s("%c", &rect_filler);

	printf("Enter sides: ");
	int width, height;
	scanf_s("%d %d", &height, &width);
	printf("\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c ", rect_filler);
		}
		printf("\n\n");
	}
}