#include <stdio.h>

int main() {
	int max;
	for (int i = 0; i < 10; i++) {
		int currentNum;
		scanf("%d", &currentNum);
		if (i == 0) {
			max = currentNum;
		}
		if (currentNum > max) {
			max = currentNum;
		}
	}
}