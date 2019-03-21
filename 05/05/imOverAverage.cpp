#include <stdio.h>

int main() {
	int howMany = 0;
	scanf("%d", &howMany);

	for (int trial = 0; trial < howMany; trial++) {
		int	inputSize = 0;
		scanf("%d", &inputSize);
		int store[1000];
		double sum = 0;
		for (int currentInputTry = 0; currentInputTry < inputSize; currentInputTry++) {
			scanf("%d", &store[currentInputTry]);
			sum += store[currentInputTry];
		}
		int peopleOverAverage = 0;
		double average = sum / inputSize;
		for (int currentInputTry = 0; currentInputTry < inputSize; currentInputTry++) {
			if (store[currentInputTry] >= average) {
				peopleOverAverage++;
			}
		}
		printf("%.3f%%\n", (inputSize - peopleOverAverage) / (float)inputSize * 100.0);
	}
}