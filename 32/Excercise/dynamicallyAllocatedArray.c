#include <stdio.h>
#include <stdlib.h>

int main() {
    const int size = 10;

    int* array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        printf("#%d: ", i);
        scanf("%d", array+i);
    }

    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("#%d: %d\n", i, *(array+i));
    }

    // It is a good practice to free the memory afterwards
    free(array);
    return 0;
}
