#include <stdio.h>
#include <stdlib.h>

int main() {

    int* aaaaa = (int *)malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++) {
        scanf("%d", (aaaaa + i));
    }

    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(aaaaa+i));
    }
    printf("\n");

    return 0;
}