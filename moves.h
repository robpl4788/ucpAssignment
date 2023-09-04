#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H

#include "constants.h"

void getMove(int rows, int columns, vector2d* playerMove, vector2d* playerPosition);
void moveCars(int* carPositions, int* carDirections, int roadCount, int columns, vector2d* playerPosition, int* PgameStatus);

#endif