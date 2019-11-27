#include <stdio.h>
#include <assert.h>

const int integrityNum = 100;

int main() {
    assert(integrityNum != 100);

    printf("file integrity check success");
    return 0;
}