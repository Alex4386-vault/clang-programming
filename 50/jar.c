#include "commonHeader.h"
#include "common.h"
#include "jar.h"

void initJar(int *jar) {
    srand(time(NULL));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int tmp = i*10+(rand() % 10);

            while (isInArray(jar, tmp, boardSize*boardSize)) {
                tmp = i*10+(rand() % 10);
            }

            jar[5*i+j] = tmp;
        }
    }
}