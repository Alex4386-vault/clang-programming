#include <stdlib.h>
#include <stdio.h>

int main() {
	int num;
	double dnum;
	
	//Ascii TO Int
	num = atoi("30000");
	num = num / 1000;

	//Ascii TO Float
	dnum = atof("333.99");
	dnum = dnum / 3.0;

	printf("num: %d, dnum: %f", num, dnum);
	return 0;
}
