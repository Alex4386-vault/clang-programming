int fibonacci(int n) {
	int prevprev = 0, prev = 1, current;

	for (int i = 0; i < n; i++) {
		if (i <= 1) {
			current = i;
		}
		else {
			current = prevprev + prev;
			prevprev = prev;
			prev = current;
		}
	}

	return current;
}

#include <stdio.h>

void fibonacciCaller(int a) {
	printf("%dth fibonacci: %d", a, fibonacci(a));
}

void fibonacciRangeGetter(int start, int finish) {
	for (int i = start; i <= finish; i++) {
		printf("%dth fibonacci: %d\n", i, fibonacci(i));
	}
}