#include <stdio.h>

#include "moves.h"
#include "terminal.h"

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