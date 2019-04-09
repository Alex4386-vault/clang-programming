#include <stdio.h>

int main() {
	int inNum;
	
	scanf("%d", &inNum);

	switch (inNum) {
	case 1:
		printf("cat\n");
	case 2:
		printf("mouse\n");
	default:
		printf("bat\n");
	}

	return 0;
}