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
void printBoard(int rows, int columns, Vector2d playerPosition,
                int* carPositions, int* carDirections)
{
        
    system("tput cup 0 0");

    printBorderRow(columns);

    
    printBorderRow(columns);

    printf("%c to move up\n", KEY_UP);
    printf("%c to move left\n", KEY_LEFT);
    printf("%c to move right\n", KEY_RIGHT);
    printf("%c to move down\n", KEY_DOWN);


}
