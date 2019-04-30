#include <stdio.h>

int main() {
	char str[81];
	printf("Enter da String Baby: ");
	int i;
	for (i = 0; i < 81; i++) {
		char in = getchar();
		if (in == '\n') {
			break;
		}
		str[i] = in;
	}
	str[i] = '\0';

	for (int j = 0; j <= i; j++) {
		putchar(str[j]);
	}

}