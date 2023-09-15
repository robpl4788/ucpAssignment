#include <stdio.h>
#include <stdlib.h>


#include "constants.h"
#include "setup.h"
#include "random.h"

/*  Checks the input arguments are valid
    If invalid returns false and prints the reason */

int validateInputs(int* pRows, int* pCols, int* pArgc, char* argv[]) {
    int inputsAreValid = TRUE;

    if (*pArgc != 3) {
        inputsAreValid = FALSE;
        printf("Incorrect number of arguments, should be 2, is %d\n", *pArgc);
    }
    else {
        *pRows = atoi(argv[1]);
        *pCols = atoi(argv[2]);
        if (*pRows < 3)
        {
            printf("Row number ( %d ) is invalid, must be greater than 2\n", *pRows);
            inputsAreValid = FALSE;
        }
        if (*pRows % 2 == 0)
        {
            printf("Row number ( %d ) is invalid, must be odd\n", *pRows);
            inputsAreValid = FALSE;
        }
        if (*pCols < 5)
        {
            printf("Column number ( %d ) is invalid, must be greater than 4\n", *pCols);
            inputsAreValid = FALSE;
        }
    }

    return inputsAreValid;
}

void initialiseCars(int* carPositions, int* carDirections, int roadCount, int columns){
    int i;

    initRandom();

    /* Generate car positions and assign directions */

    for (i = 0; i < roadCount; i ++)
    {
        carPositions[i] = randomUCP(0, columns - 1);
        if (carPositions[i] == 0) 
        {
            carDirections[i] = RIGHT;
        }
        else if (carPositions[i] == columns - 1)
        {
            carDirections[i] = LEFT;
        }
        else
        {
            carDirections[i] = randomUCP(0, 1) == 0 ? LEFT : RIGHT;
        }
    }
}