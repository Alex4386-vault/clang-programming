// ���� ����ٰ� Ǯ����� ������

/*
���� N���� �̷���� ���� A�� ���� X�� �־�����.�̶�, A���� X���� ���� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� X�� �־�����. (1 �� N, X �� 10, 000)

��° �ٿ� ���� A�� �̷�� ���� N���� �־�����.�־����� ������ ��� 1���� ũ�ų� ����, 10, 000���� �۰ų� ���� �����̴�.
*/

#include <stdio.h>

int main() {
	int store[10000] = { 0, };
	int biggerThan = 1;
	int size = 0;

	scanf("%d %d", &size, &biggerThan);
	for (int i = 0; i < size; i++) {
		scanf("%d", &store[i]);
	}

	for (int i = 0; i < size; i++) {
		if (store[i] < biggerThan) {
			printf("%d ", store[i]);
		}
	}
}