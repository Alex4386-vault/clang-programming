#include <stdio.h>

int main() {
	int age = 0;
	float height = 0, weight = 0;

	printf("���� �Է��ϼ���\n");
	scanf_s("%d", &age);

	printf("������ �Է��ϼ��� (kg)\n");
	scanf_s("%f", &weight);

	printf("Ű �Է��ϼ��� (cm)\n");
	scanf_s("%f", &height);

	printf("����� ���̴� %d�̰� �����Դ� %.2fkg�̰�, Ű�� %.2fcm �Դϴ�.\n", age, weight, height);
	
	float heightInMeters = height / (float)100;
	printf("����� BMI�� %.2f �Դϴ�.\n", weight / (heightInMeters * heightInMeters));

	return 0;
}
