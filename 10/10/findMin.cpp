#include <stdio.h>

int main() {
	int min;
	for (int i = 0; i < 10; i++) {
		int currentNum;
		scanf("%d", &currentNum);
		if (i == 0) {
			min = currentNum;
		}
		if (currentNum < min) {
			min = currentNum;
		}
	}
}