#include <stdio.h>

void main() {
	char a = -10;
	// 0xF6 = 0b11110110

	unsigned char b = a;
	
	printf("%d %d", a, b);
}
