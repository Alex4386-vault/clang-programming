#include <stdio.h>

int main() {
	int a, b, c;
	int sort;
	scanf("%d %d %d", &a, &b, &c);

	if (c >= a && c >= b) {
		sort = c;
	}
	else if (b >= a && b >= c) {
		sort = b;
	}
	else if (a >= b && a >= c) {
		sort = a;
	}
	else {
		sort = 0;
	}
	printf("%d", sort);
	
}