#include <stdio.h>

#include "moves.h"
#include "terminal.h"
#include "constants.h"

void getMove(int rows, int columns, vector2d* playerMove, vector2d* playerPosition)
{
    char input;
    
    disableBuffer();
    scanf(" %c", &input);
    enableBuffer();

    if (input == 'w' && playerPosition->y != 0)
    {
        playerMove->y = -1;
    }
    else if (input == 's' && playerPosition->y != rows - 1)
    {
        playerMove->y = 1;
    }
    else if (input == 'a' && playerPosition->x != 0)
    {
        playerMove->x = -1;
    }
    else if (input == 'd' && playerPosition->x != columns - 1)
    {
        playerMove->x = 1;
    }
}

void moveCars(int* carPositions, int* carDirections, int roadCount, int columns, vector2d* playerPosition, int* PgameStatus)
{
    int i;
    for (i = 0; i < roadCount; i ++)
    {
        int row = i * 2 + 1;

        carPositions[i] = carPositions[i] + carDirections[i];

        if (carPositions[i] == 0)
        {
            carDirections[i] = RIGHT;
        }
        else if (carPositions[i] == columns - 1)
        {
            carDirections[i] = LEFT;
        }

        if (carPositions[i] == playerPosition->x && row == playerPosition->y)
        {
            *PgameStatus = LOSE;
        }
    }
}