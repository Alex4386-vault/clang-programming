#include <stdio.h>

int main() {
	int strOccur = 0;
	char a[255] = { 0, };
	char key[255] = { 0, };
	
	printf("Enter Sentence: ");
	gets_s(a);

	printf("Enter Keyword: ");
	gets_s(key);
	

	// Check the length of the keyword via checking the null character
	int lengthOfKey = 0;
	for (int i = 0; i < 255; i++) {
		if (key[i] == 0) {
			lengthOfKey = i;
		}
	}


	for (int i = 0; i < 255 - lengthOfKey; i++) {
		if (a[i] == key[0]) {
			bool check = true;
			for (int j = 0; j < lengthOfKey; j++) {
				if (a[i + j] != key[j]) {
					check = false;
				}
			}
			strOccur = (check) ? strOccur + 1 : strOccur;
		}
	}

	printf("keyword '%s' found %d times\n", key, strOccur);


}