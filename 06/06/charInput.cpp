#include <stdio.h>

int main() {
	char mstatus;
	
	scanf("%c", &mstatus);

	if (mstatus == 'M' || mstatus == 'm') {
		printf("married");

	} else if (mstatus == 'S' || mstatus == 's') {
		printf("single");

	} else if (mstatus == 'D' || mstatus == 'd') {
		printf("divorced");

	} else if (mstatus == 'W' || mstatus == 'w') {
		printf("widowed");

	} else {
		printf("Invalid Code");
	}
	printf("\n");
}
