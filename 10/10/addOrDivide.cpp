#include <stdio.h>

int main() {
	int N = -1, N1, N2, result;

	scanf("%d", &N1); scanf("%d", &N2); scanf("%d", &N);

	switch (N) {
	case 0:
		result = N1 + N2;
		printf("result = %d", result);
		break;
	case 2:
		result = N1 / N2;
		printf("result = %d", result);
		break;
	default:
		printf("invalid input");
		break;
	}

	return 0;
}