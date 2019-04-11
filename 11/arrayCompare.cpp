//
//  arrayCompare.cpp
//  c-programming
//
//  Created by Alex4386 (박상희) on 11/04/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved.
//

#include <stdio.h>

int main() {
    int num1[5] = {0, }, num2[5] = {0, };
    
    bool getOut = false;
    for (int i = -5; i < 5; i++) {
        (i < 0) ? scanf("%d", &num1[i+5]) : scanf("%d", &num2[i]);
    }
    
    for (int i = 0; i < 5 && !getOut; i++) {
        short checkVar = (num1[i]-num2[i]) == 0 ? 0 : (num1[i]-num2[i]) > 0 ? 1 : -1;
        getOut = (bool) checkVar;
        printf("%d ", checkVar);
    }
    printf("\n");
}
