#include <stdio.h>

#include "printBoard.h"
#include "moves.h"
#include "terminal.h"
#include "constants.h"


/*  Attempts to get a new move, checks if it's valid
    If  valid, sets the referenced player move to the new move
    If invalid doesn't change the plater move */
static void getMove(int rows, int columns, Vector2d* playerMove, Vector2d* playerPosition)
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
               int columns, Vector2d* playerPosition, int* PgameStatus )
{
   
}

int makeMove(int rows, int columns, int roadCount, Vector2d* pPlayerPosition, int* carPositions, int* carDirections)
{
    int gameStatus = PLAYING;
    Vector2d playerMove = {0, 0};

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