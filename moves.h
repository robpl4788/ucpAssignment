#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H

#include "constants.h"

int makeMove(BoardState* board, Vector2d move);
void getMove(int rows, int columns, int* undo, Vector2d* playerMove, Vector2d* playerPosition);


#endif