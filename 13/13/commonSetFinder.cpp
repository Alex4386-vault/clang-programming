#include <stdio.h>

int main() {
	printf("Enter first number set:\n");
	int firstSet[5] = { 0, };
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &firstSet[i]);
	}

	int secondSet[5] = { 0, };
	printf("Enter second number set:\n");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &secondSet[i]);
	}

	int commonSet[5] = { 0, };
	int currentIndex = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (firstSet[i] == secondSet[j]) {
				bool isThere = false;
				for (int k = 0; k < currentIndex; k++) {
					if (firstSet[i] == commonSet[k]) {
						isThere = true;
					}
				}
				if (!isThere) {
					commonSet[currentIndex] = firstSet[i];
					currentIndex++;
				}
			}
		}
	}

	printf("The common elements:\n");
	for (int i = 0; i < currentIndex; i++) {
		printf("%d ",commonSet[i]);
	}

}