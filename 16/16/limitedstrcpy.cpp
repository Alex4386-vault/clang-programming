#include <stdio.h>
#include <string.h>

int main() {
	char a[] = "Happy Birthday To You.";
	char b[25], c[15];

	printf("String a: %s, Copied String b: %s \n", a, strcpy(b, a));

	strncpy(c, a, 5);

	c[5] = 0;

	printf("c: %s", c);

	return 0;
}
