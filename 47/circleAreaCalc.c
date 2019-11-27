#include <stdio.h>
#define PI 3.14

int main() {
    double area, radius;

    fputs("Please type the radius : ", stdout);
    scanf("%lf", &radius);
    
    area = PI * radius * radius;

    printf("The area of circle is %lf\n", area);
}