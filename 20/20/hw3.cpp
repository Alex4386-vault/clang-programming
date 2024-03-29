#include <stdio.h>
#define SENTENCE_LENGTH 65535

#ifndef _MSC_VER
	#define gets_s gets
#endif

bool isVowel(char alphabet) {
	return (alphabet == 'a') || (alphabet == 'A') || (alphabet == 'e') || (alphabet == 'E') ||
		(alphabet == 'i') || (alphabet == 'I') || (alphabet == 'o') || (alphabet == 'O') || (alphabet == 'u') || (alphabet == 'U');
}

int main() {
	for (int trial = 0; trial < 3; trial++) {
		char a[SENTENCE_LENGTH];
		gets_s(a);

		for (int i = 0; a[i] && i < SENTENCE_LENGTH; i++) {
			if (isVowel(a[i])) {
				putchar(a[i]);
			}
		}
		putchar(10);
	}
}