#include <stdio.h>

int main() {
	int sortThis[10] = { 10,4,5,7,8,2,3,4,1,9 };

	for (int i = 0; i < 10; i++) {
		int min = sortThis[i], minIndex = i;
		for (int j = i; j < 10; j++) {
			if (min > sortThis[j]) {
				min = sortThis[j];
				minIndex = j;
			}
		}

		// swap the values-- 
		int tmp = sortThis[i];
		sortThis[i] = sortThis[minIndex];
		sortThis[minIndex] = tmp;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", sortThis[i]);
	}
}