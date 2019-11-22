#include <stdio.h>
#include <stdlib.h>

long long int *fiboCache;
long long int fibo(int n) { long long int wa = (fiboCache[n-1] != 0) ? fiboCache[n-1] : (n >= 2) ? fibo(n-1)+fibo(n-2):n; fiboCache[n-1] = wa; return wa; }

int main() {
    int a;
    scanf("%d", &a);
    fiboCache = (long long int *)malloc(sizeof(long long int) * a);
    for (int i = 0; i < a; i++) fiboCache[i] = 0ll;
    printf("%lld\n", fibo(a));
    free(fiboCache);
}