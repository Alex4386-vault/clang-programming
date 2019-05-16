#include <stdio.h>
#define INPUT_LIMIT 255

int main() {
	char a[INPUT_LIMIT], b[INPUT_LIMIT];

	// MSBuild Specific - 
	// With SDL Enabled, scanf_s with %s requires size data.
	scanf_s("%s", a, INPUT_LIMIT);
	scanf_s("%s", b, INPUT_LIMIT);
	int aCount[26] = { 0, }, bCount[26] = { 0, };

	for (int i = 0; i < INPUT_LIMIT; i++) {
		for (int j = 0; j < 26; j++) {
			if ('A' + j == a[i] || 'a' + j == a[i]) {
				aCount[j]++;
			}
		}
	}

	for (int i = 0; i < INPUT_LIMIT; i++) {
		for (int j = 0; j < 26; j++) {
			if ('A' + j == b[i] || 'a' + j == b[i]) {
				bCount[j]++;
			}
		}
	}

	bool isAnagram = true;
	for (int i = 0; i < 26; i++) {
		if (aCount[i] != bCount[i]) {
			isAnagram = false;
			break;
		}
	}

	printf((isAnagram) ? "This is Anagram" : "This is Not Anagram");

	return 0;
}