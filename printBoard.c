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


/*  Prints a road row
    Player position is horizontal position in this row
    If player is not in this row player position should be -1 */
static void printRoad(int columns, int carPosition, int carDirection, int playerPosition)
{
    int i;
    printf(WALL);
    for (i = 0; i < columns; i ++)
    {
        if (i == carPosition)
        {
            if (carDirection == LEFT)
            {
                printf(LEFT_CAR);
            }
            else
            {
                printf(RIGHT_CAR);
            }
        }
        else if (i == playerPosition)
        {
            printf(PLAYER);
        }
        else 
        {
        printf(ROAD);
        }
    }
    printf(WALL);
    printf("\n");

}

/*  Prints a row that is not a road
    playerPosition is the horizontal position on this row
    If player is not in this row playerPosition should be -1 */
static void printSafeRow(int columns, int playerPosition, int goal)
{
    int i;
    printf(WALL);
    for (i = 0; i < columns; i ++)
    {
        if (i == playerPosition)
        {
            printf(PLAYER);
        }
        else if (i == columns - 1 && goal == TRUE)
        {
            printf(GOAL);
        }
        else 
        {
        printf(EMPTY);
        }
    }
    printf(WALL);
    printf("\n");

}


/*  erase the old board and prints an updated one */
void printBoard(int rows, int columns, vector2d playerPosition,
                int* carPositions, int* carDirections)
{
    
    int i;
    int finalPlayerX = playerPosition.y == rows - 1 ? playerPosition.x : -1; 
    
    system("tput cup 0 0");

    printBorderRow(columns);

    for (i = 0; i < rows - 1; i ++)
    {
        int playerX = playerPosition.y == i ? playerPosition.x : -1; 
        if (i % 2 == 0)
        {
            printSafeRow(columns, playerX, FALSE);
        }
        else 
        {
            int roadNum = (i - 1) / 2;
            printRoad(columns, carPositions[roadNum], carDirections[roadNum], playerX);
        }
    }


    printSafeRow(columns, finalPlayerX, TRUE);

    printBorderRow(columns);

    printf("%c to move up\n", KEY_UP);
    printf("%c to move left\n", KEY_LEFT);
    printf("%c to move right\n", KEY_RIGHT);
    printf("%c to move down\n", KEY_DOWN);


}
