#include <stdio.h>

int main() {

	printf("  일  월  화  수  목  금  토\n");
	int myDay = 2;
	for (int i = myDay; i >= 0; i--) {
		printf("   ");
	}
	printf(" ");
	for (int i = 1; i <= 31; i++) {
		if (i < 10) {
			printf(" ");
		}
		printf("%d", i);
		printf("  ");
		myDay++;
		myDay = myDay % 7;
		if (myDay == 0) {
			printf("\n  ");
		}
	}
	return 0;
}