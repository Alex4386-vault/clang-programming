#include <stdio.h>
#define INPUT_LIMIT 255

// if it is compiled via MSBuild,
// Convert scanf to scanf_s.
// since scanf_s requires the size of the variable on %s
//
// I would rather stick with ANSI C
#ifdef _MSC_VER
#define scanf(a,b) scanf_s(a,b,sizeof(b))
#endif

int main() {
	char a[INPUT_LIMIT] = {0, }, b[INPUT_LIMIT] = {0, };

	scanf("%s", a);
	scanf("%s", b);
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
	printf("\n");

	return 0;
}