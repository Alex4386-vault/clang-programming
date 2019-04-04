#include <stdio.h>

int main() {
	int code = 0;
	printf("Type the manufacturer code (1 to 4):?\b");
	scanf_s("%d", &code);

	// The Question told us to use if-else chain, NOT SWITCH.
	if (code == 1) {
		printf("Samsung");
	}
	else if (code == 2) {
		printf("LG");
	}
	else if (code == 3) {
		printf("Apple");
	}
	else if (code == 4) {
		printf("Google");
	}
	else {
		printf("invalid code");
	}
	printf("\n");
	return 0;
}
