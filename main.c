#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "random.h"
#include "constants.h"
#include "printBoard.h"
#include "moves.h"

int validateInputs(int* pRows, int* pCols, int* pArgc, char* argv[]) {
    int inputsAreValid = TRUE;

    if (*pArgc != 3) {
        inputsAreValid = FALSE;
        printf("Incorrect number of arguments\n");
    }
    else {
        *pRows = atoi(argv[1]);
        *pCols = atoi(argv[2]);
        if (*pRows < 3)
        {
            printf("Row number ( %d ) is invalid, must be greater than 3\n", *pRows);
            inputsAreValid = FALSE;
        }
        if (*pRows % 2 == 0)
        {
            printf("Row number ( %d ) is invalid, must be even\n", *pRows);
            inputsAreValid = FALSE;
        }
        if (*pCols < 5)
        {
            printf("Column number ( %d ) is invalid, must be greater than 5\n", *pCols);
            inputsAreValid = FALSE;
        }
    }

    return inputsAreValid;
}

int main(int argc, char* argv[]) {
    /* Validate Inputs */

    int rows, columns;

    if (validateInputs(&rows, &columns, &argc, argv) == TRUE) {

    /* Initialise Map */

    int playerPosition[] = {0, 0};

    int playerMove[] = {0, 0};

    int roadCount = rows / 2;

    int gameStatus = PLAYING;

    int* carPositions = malloc(sizeof(int) * roadCount);
    int* carDirections = malloc(sizeof(int) * roadCount);
    int i;

    initRandom();

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
            carDirections[i] = randomUCP(0, 1) * 2 - 1;
        }
    }

    /* Test Car Generation 
    for (i = 0; i < roadCount; i ++)
    {
        printf("%d ", carPositions[i]);
    }
    printf("\n");
    for (i = 0; i < roadCount; i ++)
    {
        printf("%d ", carDirections[i]);
    }*/


    /* Loop until win or lose */
        /* Print board */
        /* Get input */
        /* Update board and check win/loss */
    system("clear");
    while (gameStatus == PLAYING) 
    {
        playerMove[0] = 0;
        playerMove[1] = 0;

        printBoard(rows, columns, playerPosition, carPositions, carDirections);

        while (playerMove[0] == 0 && playerMove[1] == 0)
        {
            getMove(rows, columns, playerMove, playerPosition);
        }

        playerPosition[0] = playerPosition[0] + playerMove[0];
        playerPosition[1] = playerPosition[1] + playerMove[1];
        
        moveCars(carPositions, carDirections, roadCount, columns, playerPosition, &gameStatus);

        if (playerPosition[0] == columns - 1 && playerPosition[1] == rows - 1)
        {
            gameStatus = WIN;
        }
    
        system("tput cup 0 0");

    }

    printBoard(rows, columns, playerPosition, carPositions, carDirections);

    /* Handle Win */
    if (gameStatus == WIN) {
        printf("You Win\n");
    } else if (gameStatus == LOSE) {
        printf("You Lose\n");
    }

    /* Handle Lose*/

    /* End Game */

    free(carPositions);
    free(carDirections);

    }

    return 0;
}