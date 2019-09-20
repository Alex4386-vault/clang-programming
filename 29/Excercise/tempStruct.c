#include <stdio.h>

struct point {
    int x,y;
} pt1;

typedef struct point point;

//Temp Struct.
struct {
    int this, is, tempStruct;
} tempStruct;

int main() {
    tempStruct.this = 10;
    printf("%d", tempStruct.this);
    
    return 0;
}
