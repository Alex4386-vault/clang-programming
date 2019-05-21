#include <stdio.h>

// Get Maximum value
int maximum(int x, int y, int z);

// Get Array and returns maximum value
int maximumArray(int* a, int size);

int main() {
	int a[3] = { 0, };
	for (int i = 0; i < 3; i++) scanf_s("%d", &a[i]);
	printf("max: %d\n", maximum(a[0], a[1], a[2]));
	printf("max: %d\n", maximumArray(a, 3));
	return 0;
}

int maximum(int x, int y, int z) { return (x > y) ? (z > x) ? z : x : (z > y) ? z : y; }

int maximumArray(int* a, int size) { int max = a[0]; while (size--) { max = (a[size] > max) ? a[i] : max; } return max; }
