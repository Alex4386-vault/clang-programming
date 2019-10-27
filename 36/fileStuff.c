#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("test.txt", "w");

	if (fp == NULL) {
		printf("File could not be opened\n");
		return -1;
	}
  fprintf(fp, "This is testing for frpintf...\n");
	fputs("This is testing for fputs...\n", fp);
	
	fclose(fp);

	fp = fopen("test.txt", "r");
	char buff[255];

	fscanf(fp, "%s", buff);
	printf("1: %s\n", buff);
	fgets(buff, 255, fp);
	printf("2: %s\n", buff);
	fgets(buff, 255, fp);
	printf("3: %s\n", buff);

	if (
	fclose(fp);
}
