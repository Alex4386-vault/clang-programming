#include <stdio.h>

int main() {
	printf("Type 7 temperature values:\n");
	double tempSave[7] = { 0, };
	double total = 0;

	for (int i = 0; i < 7; i++) {
		scanf_s("%lf", &tempSave[i]);
		total += tempSave[i];
	}
	
	double average = total / 7.0;
	printf("Average temperature: %lf\n", average);

	int count = 0;
	for (int i = 0; i < 7; i++) {
		if (tempSave[i] < average) {
			count++;
		}
	}
	printf("The number of days below average temperature: %d", count);

	return 0;
}