#include <stdio.h>

int main() {
    printf("File name    : %s\n", __FILE__);
    printf("Line No.     : %d\n", __LINE__);
    printf("Compile Date : %s\n", __DATE__);
    printf("Compile Time : %s\n", __TIME__); 
}
