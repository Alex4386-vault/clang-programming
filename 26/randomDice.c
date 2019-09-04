#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 25565

int rollDice();
void outputStatistics(int *rollResults, int length);

int main() {
    srand(time(NULL));

    printf("How many times you want to roll?");

    int rollCount;
    scanf("%d", &rollCount);

    int diceRollResults[MAX_ROLLS] = {0,};

    for (int i = 0; i < rollCount; i++) {
        diceRollResults[i] = rollDice();
    }

    outputStatistics(diceRollResults, rollCount);

}

/**
 * Returns a FAIR DICE ROLL (pseudo-random)
 */
int rollDice() {
    return (rand() % 6) + 1;
}

/**
 * 
 */
void outputStatistics(int *rollResults, int length) {
    int count[6] = {0,};

    for (int i = 0; i < length; i++) {
        count[rollResults[i] - 1]++;
    }
    
    for (int i = 0; i < 6; i++) {
        printf("Dice Number %d / frequency: %d, probability: %f\n", (i+1), count[i], count[i]/(double)length);
    }
}