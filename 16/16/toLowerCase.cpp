#include <stdio.h>

int main() {
	char str[81];

	gets_s(str);

	for (int i = 0; str[i]; i++) {
		if (65 <= str[i] && str[i] <= 90) {
			str[i] = str[i] + 32;
		} else if (97 <= str[i] && str[i] <= 122) {
			str[i] = str[i] - 32;
		} 
	}

	puts(str);
	
}