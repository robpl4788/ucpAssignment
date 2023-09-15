#include <stdio.h>

#include "printBoard.h"
#include "moves.h"
#include "terminal.h"
#include "constants.h"


/*  Attempts to get a new move, checks if it's valid
    If  valid, sets the referenced player move to the new move
    If invalid doesn't change the plater move */
static void getMove(int rows, int columns, vector2d* playerMove, vector2d* playerPosition)
{
    char input;
    
    disableBuffer();
    scanf( " %c", &input );
    enableBuffer();

    if ( input == KEY_UP && playerPosition->y != 0 )
    {
        playerMove->y = -1;
    }
    else if ( input == KEY_DOWN && playerPosition->y != rows - 1 )
    {
        playerMove->y = 1;
    }
    else if ( input == KEY_LEFT && playerPosition->x != 0 )
    {
        playerMove->x = -1;
    }
    else if ( input == KEY_RIGHT && playerPosition->x != columns - 1 )
    {
        playerMove->x = 1;
    }
}


/*  Moves all the cars
    If the cars hit the player sets the referenced game state to lose */

static void moveCars( int* carPositions, int* carDirections, int roadCount,
               int columns, vector2d* playerPosition, int* PgameStatus )
{
    int i;
    for ( i = 0; i < roadCount; i ++ )
    {
        int row = i * 2 + 1;

        carPositions[i] = carPositions[i] + carDirections[i];

        if ( carPositions[i] == 0 )
        {
            carDirections[i] = RIGHT;
        }
        else if ( carPositions[i] == columns - 1 )
        {
            carDirections[i] = LEFT;
        }

        if ( carPositions[i] == playerPosition->x && row == playerPosition->y )
        {
            *PgameStatus = LOSE;
        }
    }
}

int makeMove(int rows, int columns, int roadCount, vector2d* pPlayerPosition, int* carPositions, int* carDirections)
{
    int gameStatus = PLAYING;
    vector2d playerMove = {0, 0};

    printBoard(rows, columns, *pPlayerPosition, carPositions, carDirections);

    while (playerMove.x == 0 && playerMove.y == 0)
    {
        getMove(rows, columns, &playerMove, pPlayerPosition);
    }

    pPlayerPosition->x += playerMove.x;
    pPlayerPosition->y += playerMove.y;
    
    moveCars(carPositions, carDirections, roadCount, columns, pPlayerPosition, &gameStatus);

    if (pPlayerPosition->x == columns - 1 && pPlayerPosition->y == rows - 1)
    {
        gameStatus = WIN;
    }

    return gameStatus;
}