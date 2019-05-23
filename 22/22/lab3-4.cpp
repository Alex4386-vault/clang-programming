#include <stdio.h>
#include <Math.h>

int myatoi(char* input) {
	int numStart = 0;
	if (input[0] == '-' || input[0] == '+') {
		numStart = 1;
	}

	int strLength = 0;
	for (int i = numStart; i < 255; i++) {
		if (input[i] == 0 || !('0' <= input[i] && input[i] <= '9')) { strLength = i; break; }
	}

	int sum = 0;
	int d = 0;
	for (int i = strLength-1; i >= numStart; i--) {

		int currentNum = input[i] - '0';
		sum += (int)pow(10, d) * currentNum;

		d++;
	}

	return (numStart == 1) ? (input[0] == '-') ? -1*sum : sum : sum;
}

int main() {
	while (true) {
		char a[255] = { 0, };
		scanf_s("%s", a, sizeof(a));

		printf("%d\n\n", myatoi(a));
	}
}