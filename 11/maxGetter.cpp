//
//  maxGetter.cpp
//  c-programming
//
//  Created by Alex4386 (박상희) on 11/04/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved.
//

#include <stdio.h>

#define LENGTH 10

int main() {
    int input[LENGTH] = {0, }, sum = 0;
    for (int i = 0; i < LENGTH; i++) {
        printf("input: ");
        scanf("%d", &input[i]);
    }
    
    int maxValue = input[0], minValue = input[0];
    
    for (int i = 0; i < LENGTH; i++) {
        if (maxValue < input[i]) {
            maxValue = input[i];
        }
        if (minValue > input[i]) {
            minValue = input[i];
        }
        
        sum += input[i];
    }

    printf("max: %d, min: %d, average: %.3f\n", maxValue, minValue, (float)sum/LENGTH);
    
    return 0;
}

