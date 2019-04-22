#include <stdio.h>

#define cities 3
#define days 7

int main() {
	int tempData[cities][days] = { {0,}, };
	float sum = 0;
	int calculatedDays = 0;

	for (int cityIndex = 0; cityIndex < cities; cityIndex++) {
		//if (cityIndex == 1) continue;
		printf("City #%d: ", cityIndex);
		for (int dayIndex = 0; dayIndex < days; dayIndex++) {
			scanf_s("%d", &tempData[cityIndex][dayIndex]);
			float f = ((float)(9.0 / 5.0) * tempData[cityIndex][dayIndex]) + 32;
			//printf("F: %f, givenMe: %d\n", f, tempData[cityIndex][dayIndex]);
			sum += f;
			calculatedDays++;
		}
	}

	printf("average: %f", sum / calculatedDays);
}