#include <stdio.h>

int main() {
	char str1[81], str2[81];

	puts("getting string1: ");
	gets_s(str1);

	puts("getting string2: ");
	gets_s(str2);

	bool isItSame = true;
	for (int i = 0; i < 81; i++) {
		if (str1[i] != str2[i]) {
			isItSame = false;
			break;
		}
	}

	printf("It is %s", ((isItSame) ? "same" : "not same"));
}