#include <stdio.h>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	
	if (a == b * 2 || b == a * 2) {
		printf("%d", a + b);
	}
	else {
		printf("condition not satisfied");
	}
}