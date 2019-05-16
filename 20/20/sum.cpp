#include <stdio.h>

int sum(int count) {
	int sum = 0;
	for (int i = 0; i < count && sum <= 200000; i++) {
		int current;
		scanf_s("%d", &current);
		if (current >= 3000) continue;
		sum += current;
	}
	return sum;
}

int main() {
	int count;
	scanf_s("%d", &count);
	printf("%d", sum(count));
	return 0;
}