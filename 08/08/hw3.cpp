#include <stdio.h>
#define Ice 9

int main() {
	int get = 0;
	scanf("%d", &get);
	
	int temp = get, ice9 = 0;
	for (int i = 10000; i > 0; i /= 10) {
		int a = temp / i;
		temp -= (i * a);
		if (a == Ice) {
			ice9++;
		}
	}

	printf("amount of 9s: %d", ice9);
}

/*
 Spell Card:
 Ice Sign "Icicle Fall"

    0
   / \
  / 1 \
 /\   /\
 \ \ / /
  \ V /
*/
