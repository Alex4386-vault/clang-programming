#include <stdio.h>

int main() {
	int i;
	FILE *fp;

	double price[2] = {139.25, 19.03};
	char *description[2] = {"glove", "CD"};

	fp = fopen("price.dat", "w");

	if (fp == NULL) {
		printf("\nFile could not be written");
		return -1;
	}

	for (int i = 0; i < 2; i++) {
		fprintf(fp, "%s %6.2f\n", description[i], price[i]);
	}
	fclose(fp);

	return 0;
}
