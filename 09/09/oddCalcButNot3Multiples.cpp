#include <stdio.h>

int init = 100, end = 200, notMultiples = 3;

int main() {
	int sum = 0;

	for (int i = init; i <= end; i++) {
		if (i % 2 == 1) {
			if (i % notMultiples == 0) {
				continue;
			}
			sum += i;
		}
	}

	printf("sum is %d\n", sum);
	return 0;
}