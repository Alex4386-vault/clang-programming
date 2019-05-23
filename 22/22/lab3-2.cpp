#include <stdio.h>

bool isAlphabet(char a) { return (('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')); }
void delchar();
void delchar2(int howMany, int start);

char process[255] = { 0, };
char output[255] = { 0, };

int main() {
	char input[255] = { 0, };

	gets_s(process);
	delchar();
	printf("%s\n", output);

	for (int i = 0; i < 255; i++) {
		process[i] = output[i];
	}

	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	delchar2(b, a);
	printf("%s\n", output);
}

void delchar() {
	int j = 0;
	for (int i = 0; i < 255; i++) {
		if (isAlphabet(process[i])) {
			output[j] = process[i];
			j++;
		}
	}
}

void delchar2(int howMany, int start) {
	int j = 0;
	for (int i = 0; i < 255; i++) {
		
		if ((start-1 <= i) && (i < start + howMany - 1)) continue;
		output[j] = process[i];
		j++;
	}
}
