//
//  fibonacci.cpp
//  showcase
//
//  Created by Alex4386 (박상희) on 07/05/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved.
//

#include <stdio.h>
#define MAX 93

unsigned long long int fiboSequence[MAX+1] = {0, };
unsigned long long int getFibo(int n);

int main() {
    for (int i = 1; i <= MAX; i++) {
        fiboSequence[i] = getFibo(i);
        printf("%dth fibonacci sequence: %llu\n", i, fiboSequence[i]);
        
    }
}

unsigned long long int getFibo(int n) {
    return (fiboSequence[n-1] && fiboSequence[n-2]) ? fiboSequence[n-1]+fiboSequence[n-2] :
            (n == 1 || n == 2 ) ? 1 : getFibo(n-1)+getFibo(n-2);
}
