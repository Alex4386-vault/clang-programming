#include <stdio.h>
#include <string.h>

int main() {
	char str[81];

	strcpy_s(str, "these ");
	strcat_s(str, "strings ");
	strcat_s(str, "are ");
	strcat_s(str, "concatenated.");
	puts(str);

	printf("\nstr's length: %d", strlen(str));
}
