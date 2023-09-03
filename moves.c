#include <stdio.h>

#include "moves.h"
#include "terminal.h"
#include "constants.h"

void getMove(int rows, int columns, int playerMove[2], int playerPosition[2])
{
    char input;
    
    disableBuffer();
    scanf(" %c", &input);
    enableBuffer();

    if (input == 'w' && playerPosition[1] != 0)
    {
        playerMove[1] = -1;
    }
    else if (input == 's' && playerPosition[1] != rows)
    {
        playerMove[1] = 1;
    }
    else if (input == 'a' && playerPosition[0] != 0)
    {
        playerMove[0] = -1;
    }
    else if (input == 'd' && playerPosition[0] != columns)
    {
        playerMove[0] = 1;
    }
}

void moveCars(int* carPositions, int* carDirections, int roadCount, int columns, int playerPosition[2], int* PgameStatus)
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

        if (carPositions[i] == playerPosition[0] && row == playerPosition[1])
        {
            *PgameStatus = LOSE;
        }
    }
}