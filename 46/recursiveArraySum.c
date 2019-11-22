#include <stdio.h>

// 우~ 우우, 우우, 우우우~ 재귀해.
int recursiveArraySum(int *a, int n) {
    if (n == 1) {
        return a[0];
    } else {
        return a[n-1] + recursiveArraySum(a, n-1);
    }
}

int main() {
    int a[5] = {1,2,10,12,0};
    a[4] = recursiveArraySum(a,4);

    printf("%d\n", a[4]);
    return 0;
}