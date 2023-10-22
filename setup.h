#ifndef SETUP_H
#define SETUP_H

#include <stdio.h>

#include "constants.h"

int validateInputs(int argc, char* argv[], FILE** gameFile);
int initBoardState(BoardState* board, FILE* inputFile);

#endif