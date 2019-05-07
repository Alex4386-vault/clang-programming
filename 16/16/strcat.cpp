#include <stdio.h>

int main() {
	char str1[81], str2[81], total[161];

	gets_s(str1);

	gets_s(str2);

	int i = 0;
	while (str1[i]) {
		total[i] = str1[i];
		i++;
	}
	int j = 0;
	while (str2[j]) {
		total[i + j] = str2[j];
		j++;
	}
	total[i + j] = 0;

	printf("%s", total);

	
}