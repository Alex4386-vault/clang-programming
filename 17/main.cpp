//
//  main.cpp
//  showcase
//
//  Created by Alex4386 (박상희) on 21/04/2019.
//  Copyright © 2019 Alex4386 (박상희). All rights reserved.
//

//#include <stdio.h>
//#define size 7
//
//int main() {
//    int a[size] = {0,};
//    for (int i = 0; i < size; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    // Bubble Sort Running LOL
//    for (int i = 0; i < size; i++) {
//        for (int j = i; j < (size-1); j++) {
//            if (a[j] > a[j+1]) {
//                int temp = a[j];
//                a[j] = a[j+1];
//                a[j+1] = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < size; i++) {
//        printf("%d ", a[i]);
//    }
//}
/*
#include <stdio.h>

int main() {
    char a[1000000];
    int total = 0;
    for (int i = 0; i < 1000000; i++) {
        scanf("%c", &a[i]);
    }
    
    for (int i = 0; i < 1000000; i++) {
        printf("%c", a[i]);
        if (a[i] == '\0') {
            printf("EOS");
            total++;
            break;
        }
        if (a[i] == ' ') {
            if (a[i+1] == ' ') {
                continue;
            } else {
                total++;
            }
        }
    }
    printf("%d", total);
}
*/

/*
#include <stdio.h>

int main() {
    int testCases = 0;
    scanf("%d", &testCases);
    for (int currentCase= 0; currentCase < testCases; currentCase++) {
        int repeatCount = 0;
        char text[21] = {0, };
        scanf("%d %s", &repeatCount, text);
        
        for (int i = 0; i < 21 && text[i] != '\0'; i++) {
            for (int j = 0; j < repeatCount; j++) {
                printf("%c", text[i]);
            }
        }
    }
}
*/

/*
#include <stdio.h>

int main() {
    float temp, newTemp;
    char FC;
    
    printf("Enter tempType: ");
    scanf("%c", &FC);
    printf("Enter Temp: ");
    scanf("%f", &temp);
    
    if (FC == 'F') {
        newTemp = (temp - 32) * (5.0 / 9.0);
    } else {
        newTemp = (temp * 9.0 / 5.0) + 32;
    }
    
    printf("converted Temp: %f°%c\n", newTemp, (FC=='F' ? 'C':'F'));
}
*/
