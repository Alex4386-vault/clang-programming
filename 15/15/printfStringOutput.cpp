#include <stdio.h>

int main() {
	char message[] = "I Love C Programming.";

	printf("%s", message);

	// reserve 25 character space
	// ex. I Love You
	// [               I Love You]
	printf("\n %%25s: ");
	printf("%25s", message);

	// reserve 25 character space, and only display 4 of them
	// ex. I Love You
	// [                     I Lo]
	printf("\n %%25.4s: ");
	printf("%25.4s", message);
}