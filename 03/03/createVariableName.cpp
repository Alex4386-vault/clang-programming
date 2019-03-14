#include <stdio.h>

const bool TRUE = 0x1;
const bool FALSE = 0x0;

const char MAX_BYTE = 0x7F;
const char MIN_BYTE = 0x80;

const short MAX_SHORT = 0x7FFF;
const short MIN_SHORT = 0x8000;

const int MAX_INT = 0x7FFFFFFF;
const int MIN_INT = 0x80000000;

const long long int MAX_LONGLONGINT = 0x7FFFFFFFFFFFFFFF;

int main() {
	// 좋은 변수 이름이 아닌것
	int _0x6FA7929A76 = 0x7FFFFFFF;

	// HA HA HA
	_0x6FA7929A76++;

	// 난독화다 케케케
	printf("%d", _0x6FA7929A76);

	if (_0x6FA7929A76 == MIN_INT) {
		printf("OVERFLOW!!!!");
	}
	return 0;
}