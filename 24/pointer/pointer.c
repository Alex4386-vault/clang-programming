#include <stdio.h>

int main() {

    /**
     *   *addr = addr 안에 있는 내용.
     *   &variable = variable의 주소
     **/

    int i;
    float f;
    int *iPointer;
    float *fPointer;
    

    i = 200;
    f = 100;
    iPointer = &i;
    fPointer = &f;

    *iPointer = *iPointer - 10;
    *fPointer = *fPointer - 5.2;
    
    printf("i = %d\n", i);
    printf("iPointer address = %p\n", iPointer);
    printf("i accessed by iPointer = %d\n", *iPointer);
    printf("\n");

    printf("f = %f\n", f);
    printf("fPointer address = %p\n", fPointer);
    printf("f accessed by iPointer = %f\n", *fPointer);

    return 0;
}