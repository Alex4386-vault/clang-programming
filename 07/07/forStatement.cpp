#include <stdio.h>

int main() {
	int forTotal = 0, whileTotal = 0;

	int i = 1;
	while (i <= 5) {
		whileTotal += i;
		i++;
	}

	for (int i = 1; i <= 5; i++) {
		forTotal += i;
	}

	printf("%d %d", whileTotal, forTotal);
}