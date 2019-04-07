#include <stdio.h>

// Use this only if you are using MSBUILD and SDL Check is enabled.
#define scanf scanf_s

int main() {
	int palin = 0;
	bool isPalin = true;
	scanf("%d", &palin);

	int temp = palin, a = 0, b = 0, c = 0, d = 0, e = 0, j = 0;
	for (int i = 10000; i > 0; i /= 10) {

		// We didn't learn array yet.
		int currentNum = temp / i;

		switch (j) {
		case 0:
			a = currentNum;
			break;
		case 1:
			b = currentNum;
			break;
		case 2:
			c = currentNum;
			break;
		case 3:
			d = currentNum;
			break;
		case 4:
			e = currentNum;
			break;
		default:
			printf("ERROR!");
			return 0;
		}
		temp -= (i * currentNum);
		j++;
	}

	if (a != e || b != d) {
		isPalin = false;
	}


	if (isPalin) {
		printf("%d is a palindrome", palin);
	}
}
