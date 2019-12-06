
#include "bingo.h"
#include "jar.h"

int jar[boardSize * boardSize] = { 0, };
int calledNumber[boardSize * boardSize] = { 0, };

int initGame() {
    initJar(jar);
}

