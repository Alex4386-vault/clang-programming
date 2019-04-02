#include <stdio.h>

int main() {
	for (int i = 1; i <= 9; i++) {
		/*if (i == 3) {
			continue;
		}*/
		printf("\n\n%d ´Ü", i);
		printf("\n-------------");
		for (int j = 1; j <= 9; j++) {
			printf("\n%d¡¿%d=%d", i, j, i*j);
		}
	}
}
