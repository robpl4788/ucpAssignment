#include <stdio.h>

#include "printBoard.h"
#include "moves.h"
#include "terminal.h"
#include "constants.h"


/*  Attempts to get a new move, checks if it's valid
    If  valid, sets the referenced player move to the new move
    If invalid doesn't change the plater move */
void getMove(int rows, int columns, int* undo, Vector2d* playerMove, Vector2d* playerPosition)
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
    } else if (input == KEY_UNDO) {
        *undo = TRUE;
    }
}


/*  Moves all the cars
    If the cars hit the player sets the referenced game state to lose */

static void moveCars(BoardState* board)
{
    Vector2d carPos = board->car.position;
    Vector2d carDir = board->car.direction;

    Vector2d left = rotateCCW(carDir);
    Vector2d right = rotateCW(carDir);
    Vector2d back = reverse(carDir);

    Vector2d carForward = sum(carPos, carDir);
    Vector2d carLeft = sum(carPos, left);
    Vector2d carRight = sum(carPos, right);
    Vector2d carBack = sum(carPos, back);
    

    if (board->roads[carForward.y][carForward.x])
    {
        board->car.position = carForward;
    } else if (board->roads[carLeft.y][carLeft.x])
    {
        board->car.position = carLeft;
        board->car.direction = left;
    } else if (board->roads[carRight.y][carRight.x])
    {
        board->car.position = carRight;
        board->car.direction = right;
    } else if (board->roads[carBack.y][carBack.x])
    {
        board->car.position = carBack;
        board->car.direction = back;
    } else {
        printf("Car is now 4wd and has escaped the road, good luck");
    }
}

int makeMove(BoardState* board, Vector2d move)
{
    int gameStatus = PLAYING;

    /*printBoard(rows, columns, *pPlayerPosition, carPositions, carDirections);
*/


    board->player.x += move.x;
    board->player.y += move.y;
    
    moveCars(board);

    if (board->player.x == board->goal.x && board->player.y == board->goal.y)
    {
        gameStatus = WIN;
    } else if (board->player.x == board->car.position.x && board->player.y == board->car.position.y)
    {
        gameStatus = LOSE;
    }
    

    return gameStatus;
}