#include <stdio.h>

const int stackSize = 5;

int ds[stackSize] = {0,0,0,0,0};
int top = 0;

int is_full() { return (top + 1 > stackSize); }
int is_empty() { return (top == 0); }

int get() {
    if (is_empty()) {
        return -1;
    } else {
        printf("%d\n", ds[--top]);
        return 0;
    }
}

int put(int n) {
    if (is_full()) {
        return -1;
    } else {
        ds[top++] = n;
        return 0;
    }
}

void printAll() {
    for (int i = 0; i < 5; i++) {
        printf("%d ", ds[i]);
    }
    printf("\n");
}

int main() {
    put(10);

    put(40);

    put(15);

    put(35);
    get();
    get();

    put(50);
    put(20);

    put(25);
    put(50);
    get();
    get();
    get();
    get();
    get();
    get();

    return 0;
}