/**
 * DATA:
 *  Bingo
 * 
 * DESCRIPTION:
 *  A board is a grid of boardSize x boardSize 
 * 
 * 
 **/

#include "bingoBoard.h"

typedef struct Player {
    BingoBoard board;
    char name[10];
    int score;
} Player;
