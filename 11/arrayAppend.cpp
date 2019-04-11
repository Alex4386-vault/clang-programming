//
//  arrayAppend.cpp
//  c-programming
//
//  Created by Alex4386 (박상희) on 11/04/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved.
//

#include <stdio.h>

int main() {
    int num1[15] = {0,}, num2[5] = {0, };
    
    for (int i = 0; i < 5; i++) {
        printf("num2 index %d: ", i);
        scanf("%d", &num2[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        printf("num1 index %d: ", i);
        scanf("%d", &num1[i]);
    }
    
    for (int i = 10; i < 15; i++) {
        num1[i] = num2[i-10];
    }
    
    printf("\n\nRUN\n");
    for (int i = 0; i < 15; i++) {
        printf("num1 index %d: %d\n", i, num1[i]);
    }
    
    return 0;
}
