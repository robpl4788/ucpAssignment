#include <stdio.h>
#include "printBoard.h"
#include "constants.h"

static void printBorderRow(int columns)
{
    int i;
    for (i = 0; i < columns + 2; i ++)
    {
        printf("*");
    }
    printf("\n");
}

static void printRoad(int columns, int carPosition, int carDirection, int playerPosition)
{
    int i;
    printf("*");
    for (i = 0; i < columns; i ++)
    {
        if (i == carPosition)
        {
            if (carDirection == LEFT)
            {
                printf("<");
            }
            else
            {
                printf(">");
            }
        }
        else if (i == playerPosition)
        {
            printf("P");
        }
        else 
        {
        printf(".");
        }
    }
    printf("*\n");

}

static void printSafeRow(int columns, int playerPosition, int goal)
{
    int i;
    printf("*");
    for (i = 0; i < columns; i ++)
    {
        if (i == playerPosition)
        {
            printf("P");
        }
        else if (i == columns - 1 && goal == TRUE)
        {
            printf("G");
        }
        else 
        {
        printf(" ");
        }
    }
    printf("*\n");

}

void printBoard(int rows, int columns, int playerPosition[2], int* carPositions, int* carDirections)
{
    int i;
    int finalPlayerX = playerPosition[1] == rows - 1 ? playerPosition[0] : -1; 

    printBorderRow(columns);

    for (i = 0; i < rows - 1; i ++)
    {
        int playerX = playerPosition[1] == i ? playerPosition[0] : -1; 
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

    printf("w to move up\n");
    printf("a to move left\n");
    printf("s to move down\n");
    printf("d to move right\n");
}
