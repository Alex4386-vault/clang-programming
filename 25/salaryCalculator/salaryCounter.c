#include <stdio.h>
#define SIZE 4

void totalPay(float* base, float* overTime, float* total);
void arrayPrint(float* array, int size);

int main() {
    float base[4] = {100, 200, 300, 1000};

    // 벌써 6시네요, 자, 출퇴근 기록기 찍고 옵니다.
    float overTime[4] = { 0, 0, 0, 500 };
    
    float total[4] = { 0, };
    totalPay(base, overTime, total);

    arrayPrint(total, SIZE);
}

void totalPay(float* base, float* overTime, float* total) {
    for (int i = 0; i < SIZE; i++) {
        total[i] = base[i] + overTime[i];
    }
}

void arrayPrint(float* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}
