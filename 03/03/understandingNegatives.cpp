#include <stdio.h>

int main() {
	signed char a = 0b10010101;

	// Negative decimals understanding
	// 0b00000011 (3) -> 1의 보수 계산
	// 0b11111100 -> 3의 1의 보수
	// 0b11111101 -> 3의 2의 보수

	signed char o = ~a;
	o++;

	signed char b = 0b01101011;

	if (-a == b) {
		printf("SUCCESS!\n");
		printf("%d, %d\n", b, o);
	}

	signed char c = 128;
	printf("%d", c);

	signed char d = 202; // 0b11001010
	printf("%d", d);
}