#include <stdio.h>

int main() {
	puts("ÀÔ·Â:");

	char str2[100];
	gets_s(str2);

	char str1[100] = { 0, };
	for (int i = 0; str2[i] && i < 100; i++) {
		str1[i] = str2[i];
	}

	puts(str1);
	
}