#include <stdio.h>
#include <stdlib.h>

#include "constants.h"



void printCar(Car toPrint)
{
    if (toPrint.direction.x == 1 && toPrint.direction.y == 0)
    {
        printf(RIGHT_CAR);
    }
    else if (toPrint.direction.x == -1 && toPrint.direction.y == 0)
    {
        printf(LEFT_CAR);
    }
    else if (toPrint.direction.x == 0 && toPrint.direction.y == 1)
    {
        printf(DOWN_CAR);
    }
    else if (toPrint.direction.x == 0 && toPrint.direction.y == -1)
    {
        printf(UP_CAR);
    }
    
}

void freeBoardState(BoardState* toFree)
{
    int currentRow;
    
    for (currentRow = 0; currentRow < toFree->rows; currentRow ++)
    {
        free(toFree->roads[currentRow]);
    }
    free(toFree->roads);
}
