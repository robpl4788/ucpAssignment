#include <stdio.h>
#include <stdlib.h>

#include "constants.h"


Vector2d rotateCW(Vector2d toRotate)
{
    Vector2d result;
    result.x = -toRotate.y;
    result.y = toRotate.x;

    return result;
}

Vector2d rotateCCW(Vector2d toRotate)
{
    Vector2d result;
    result.x = toRotate.y;
    result.y =-toRotate.x;

    return result;
}

Vector2d reverse(Vector2d toReverse)
{
    Vector2d result;

    result.x = -1 * toReverse.x;
    result.y = -1 * toReverse.y;

    return result;
}

Vector2d sum(Vector2d a, Vector2d b)
{
    Vector2d result;
    
    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

int Vector2dIsEqual(Vector2d a, Vector2d b)
{
    int result = TRUE;
    if (a.x != b.x) {
        result = FALSE;
    }
    
    if (a.y != b.y) {
        result = FALSE;
    }

    return result;
}


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
