#include "common.h"

char isInArray(int* array, int a, int length) {
    for (int i = 0; i < length; i++) {
        if (a == array[i]) {
            return 0;
        }
    }
    return 1;
}
