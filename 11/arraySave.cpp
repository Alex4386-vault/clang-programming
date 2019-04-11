//
//  main.cpp
//  c-programming
//
//  Created by Alex4386 (박상희) on 10/04/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved...?
//

#include <stdio.h>

int main() {
    int grade[5] = {0, };
    for (int i = 0; i < 5; i++) {
        printf("Type grade for index %d: ", i);
        scanf("%d", &grade[i]);
    }
    
    int sum = 0;
    printf("\n\nREAD DATA\n");
    
    for (int i = 0; i < 5; i++) {
        printf("index %d: %d\n", i, grade[i]);
        sum += grade[i];
    }
    
    printf("\n\nTOTAL SUM: %d\n",sum);
    return 0;
}
