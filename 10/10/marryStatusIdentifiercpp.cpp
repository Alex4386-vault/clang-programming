#include <stdio.h>

int main() {
	int mStatus;

	scanf("%d", &mStatus);

	switch (mStatus) {
	case 1:
		printf("married");
		break;
	case 2:
		printf("single");
		break;
	case 3:
		printf("divorced");
		break;
	case 4:
		printf("widowed");
		break;
	default:
		printf("invalid code");
	}
	return 0;
}