// ���� ����ٰ� Ǯ����� ������

/*
�����̴� �⸻��縦 ���ƴ�. �����̴� ������ �����ؼ� ���� ��������� �ߴ�. �ϴ� �����̴� �ڱ� ���� �߿� �ִ��� �����. �� ���� M�̶�� �Ѵ�. �׸��� ���� ��� ������ ����/M*100���� ���ƴ�.

���� ���, �������� �ְ����� 70�̰�, ���������� 50�̾����� ���������� 50/70*100�� �Ǿ� 71.43���� �ȴ�.

�������� ������ ���� ������ ���� ������� ��, ���ο� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */

#include <stdio.h>

int main() {
	int size;
	int store[1000] = { 0, };
	float sum = 0;
	int highest = 0;

	scanf("%d", &size);
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &store[i]);
	}
	
	for (int i = 0; i < size; i++) {
		if (highest <= store[i]) {
			highest = store[i];
		}
	}
	
	for (int i = 0; i < size; i++) {
		sum = sum + (float)((store[i] * 100) / (float)highest);
	}

	printf("%lf", sum / size);

}