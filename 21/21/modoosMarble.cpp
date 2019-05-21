#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int doubles = 0;

	for (int i = 0; i < 10; i++) {
		srand(clock());
		int dice1 = rand() % 6;
		int dice2 = rand() % 6;

		if (dice1 == dice2) {
			doubles++;
		}
		printf("%d\t", dice1);
		if ((2 * i + 1) % 5 == 0) {
			printf("\n");
		}
		printf("%d\t", dice2);
		if ((2 * (i+1)) % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	printf("DOUBLE: %d, %s", doubles, (doubles >= 5) ? "Landmark construction!" : "YOU LOSE, MORE ÇöÁú REQUIRED!");
	return 0;
}