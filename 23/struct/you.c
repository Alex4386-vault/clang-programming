#include <stdio.h>

struct ningen {
    char* name;
    int isAngGimotti;

    // 씹덕인지 확인하는 변수
    int isSsipDuck;
};

int main() {
    struct ningen you;
    you.name = "한웅희";
    you.isAngGimotti = 1;
    you.isSsipDuck = 1;

    printf("%s: %d, %d\n", you.name, you.isAngGimotti, you.isSsipDuck);
}
