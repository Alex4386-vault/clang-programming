#include <stdio.h>
#include <Math.h>

int main() {
	int a;
	scanf_s("%d", &a);

	int i;
	for (i = 9; i > 0; i--) {
		if ((int)(a / pow(10, i)) != 0) {
			break;
		}
	}

	int count = 0;
	for (int j = i; j >= 0; j--) {
		count += (int)(a / pow(10, j)) % 10;
	}

	printf("%d", count);
	return 0;
}