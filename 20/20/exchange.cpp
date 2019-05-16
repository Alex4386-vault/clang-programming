#include <stdio.h>

void swap(int* a, int* b);
void exchange();

int main1 = 10, main2 = 20;

int main() {
	printf("%d, %d\n", main1, main2);

	//swap(&main1, &main2);
	exchange();
	printf("%d, %d\n", main1, main2);

	return 0;
	
}

//swappable via pointer
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void exchange(/*int a, int b*/) {
	int tmp = main1;
	main2 = main1;
	main2 = tmp;
}