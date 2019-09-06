/**
 * pseudo-object oriented programming in C,
 * + how object oriented programming was implemented in C++
 */ 

#include <stdio.h>

struct ClassTest {
    int a;
    int b;
};

struct ClassTest *classTestThis;

int classTestSum() {
    return (*classTestThis).a + (*classTestThis).b;
}

int main() {
    struct ClassTest class;
    class.a = 10;
    class.b = 20;
    classTestThis = &class;
    printf("%d\n", classTestSum());
}
