#include <stdio.h>

const int queueSize = 10;

int ds[queueSize] = {0,};
int front = 0, back = 0;

int is_full() { return (back + 1 > queueSize); }
int is_empty() { return (front == back); }

int get() {
    if (is_empty()) {
        return -1;
    } else {
        printf("%d\n", ds[front++]);
        return 0;
    }
}

int put(int n) {
    if (is_full()) {
        return -1;
    } else {
        ds[back++] = n;
        return 0;
    }
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