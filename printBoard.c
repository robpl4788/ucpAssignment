#include <stdio.h>
#include <stdlib.h>

#include "printBoard.h"
#include "constants.h"

/*  Prints the top and bottom row */
static void printBorderRow(int columns)
{
    int i;
    for (i = 0; i < columns + 2; i ++)
    {
        printf(WALL);
    }
    printf("\n");
}


/*  erase the old board and prints an updated one */
void printBoard(BoardState board)
{
    int i;

    system("tput cup 0 0");

    printBorderRow(board.columns);

    for (i = 0; i < board.rows; i ++)
    {
        int j;
        printf(WALL);

        for (j = 0; j < board.columns; j ++)
        {
            if (board.player.x == i && board.player.y == j)
            {
                printf(PLAYER);
            } else if (board.goal.x == i && board.goal.y == j)
            {
                printf(GOAL);
            } else if (board.car.position.x == i && board.car.position.y == j)
            {
                printCar(board.car);
            } else if (board.roads[i][j])
            {
                printf(ROAD);
            } else {
                printf(EMPTY);
            }
            
        }


        printf(WALL);
        printf("\n");
    }

    
    printBorderRow(board.columns);

    printf("%c to move up\n", KEY_UP);
    printf("%c to move left\n", KEY_LEFT);
    printf("%c to move right\n", KEY_RIGHT);
    printf("%c to move down\n", KEY_DOWN);


}
