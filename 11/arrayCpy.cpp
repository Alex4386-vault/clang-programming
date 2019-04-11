//
//  arrayCpy.cpp
//  c-programming
//
//  Created by Alex4386 (박상희) on 11/04/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved.
//

#include <stdio.h>
#define LEN 5

int main() {
    int num1[LEN] = {0, }, num2[LEN] = {0, };
    
    for (int i = 0; i < LEN; i++) {
        printf("index %d of num1: ",i);
        scanf("%d", &num1[i]);
    }
    
    printf("\n\nArrayCopy Triggered!\n");
    
    for (int i = 0; i < LEN; i++) {
        printf("copying index %d of num1 to num2: data: %d\n",i, num1[i]);
        num2[i] = num1[i];
    }
    printf("\n\n");
    
    for (int i = 0; i < LEN; i++) {
        printf("index %d of num2: %d\n", i, num2[i]);
    }
}
