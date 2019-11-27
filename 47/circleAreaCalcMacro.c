#include <stdio.h>
#define PI 3.14
#define CIRCLE_AREA(x) (PI*(x)*(x))

int main() {
    double area, radius;

    fputs("Please type the radius : ", stdout);
    scanf("%lf", &radius);
    
    area = CIRCLE_AREA(radius);

    printf("The area of circle is %lf\n", area);

    #undef CIRCLE_AREA
    #define PI_PRECISION 3.141592653589793238462643383
    #define CIRCLE_AREA(x) (PI_PRECISION * (x) * (x))
    
    area = CIRCLE_AREA(radius);

    printf("The precise area of circle is %lf\n", area);
}

