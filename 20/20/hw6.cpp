#include <stdio.h>
#include <math.h>

#ifndef _MSC_VER
	#define scanf_s scanf
#endif

int functionThatTakesAnIntegerAndReturnsTheSumOfItsDigits(int a) { int i; for (i = 9; i > 0; i--) { if ((int)(a / pow(10, i)) != 0) break; } int count = 0; int j = i; do count += (int)(a / pow(10, j)) % 10; while(j--); return count;}

int main() {
	int a;
	scanf_s("%d", &a);
/*
	int i;
	for (i = 9; i > 0; i--) {
		if ((int)(a / pow(10, i)) != 0) {
			break;
		}
	}

	int count = 0;
	for (int j = i; j >= 0; j--) {
		count += (int)(a / pow(10, j)) % 10;
	}
*/

	printf("%d\n", functionThatTakesAnIntegerAndReturnsTheSumOfItsDigits(a));
	return 0;
}