#include <stdio.h>

int main() {
	int age = 0;
	float height = 0, weight = 0;

	printf("나이 입력하세요\n");
	scanf_s("%d", &age);

	printf("몸무게 입력하세요 (kg)\n");
	scanf_s("%f", &weight);

	printf("키 입력하세요 (cm)\n");
	scanf_s("%f", &height);

	printf("당신의 나이는 %d이고 몸무게는 %.2fkg이고, 키는 %.2fcm 입니다.\n", age, weight, height);
	
	float heightInMeters = height / (float)100;
	printf("당신의 BMI는 %.2f 입니다.\n", weight / (heightInMeters * heightInMeters));

	return 0;
}
