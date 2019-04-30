#include <stdio.h>

int main() {
	char msg[81];

	printf("type a sentence: ");
	gets_s(msg);
	puts(msg);
}