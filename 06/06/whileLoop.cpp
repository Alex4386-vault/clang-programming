#include <stdio.h>
/*
int main() {
	int num, total = 0, k = 0;

	printf("Please type a number: ?\b");
	scanf("%d", &num);

	while (num >= 0) {
		k = k++;
		total += num;
		printf("Please type a number: ?\b");
		scanf("%d", &num);
	}

	printf("numbers read = %d, total = %d and average = %.3lf", k, total, (double)total/k);

}
*/

#include "빠숑.h"

정수 메인 괄호열고 괄호닫고 열고
	정수 숫자, 전체 는 0, 횟수 는 0 앙

	형식출력 괄호열고 "숫자입력: ?\b" 괄호닫고 앙
	형식입력 괄호열고 "%d", 포인터 숫자 괄호닫고 앙

	반복 괄호열고 숫자 가보다크거나같다 0 괄호닫고 열고
		횟수 하나더하기 앙
		전체 더한다 숫자 앙
		형식출력 괄호열고 "숫자입력: ?\b" 괄호닫고 앙
		형식입력 괄호열고 "%d", 포인터 숫자 괄호닫고 앙
	닫고

	형식출력 괄호열고 "횟수: %d, 전체: %d, 평균: %.3lf", 횟수, 전체, 괄호열고 따블 괄호닫고 전체 나누기 횟수 괄호닫고 앙
	리턴제로부터시작하는이세계생활
닫고
