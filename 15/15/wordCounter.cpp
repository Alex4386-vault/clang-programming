#include <stdio.h>

int main() {
	char msg[100];

	printf("Enter the string: ");
	gets_s(msg);

	bool prevWasWord = false;
	int wordCount = 0;
	for (int i = 0; i < 100; i++) {
		if (msg[i] == ' ') {
			if (prevWasWord) {
				wordCount++;
				prevWasWord = false;
			} else {
				prevWasWord = false;
			}
		} else if (msg[i] != '\0') {
			if (prevWasWord) {

			} else {
				prevWasWord = true;
			}
		} else {
			wordCount++;
			break;
		}
	}
	printf("wordCount: %d", wordCount);
}