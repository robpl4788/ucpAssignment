#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "random.h"
#include "printBoard.h"
#include "moves.h"
#include "constants.h"
#include "setup.h"



int main(int argc, char* argv[]) {
    /* Validate Inputs */

    int rows, columns;

    if (validateInputs(&rows, &columns, &argc, argv)) {

    /* Initialise Map */

    vector2d playerPosition = {0, 0};


    int roadCount = rows / 2;

    int gameStatus = PLAYING;

    int* carPositions = malloc(sizeof(int) * roadCount);
    int* carDirections = malloc(sizeof(int) * roadCount);
  
    initialiseCars(carPositions, carDirections, roadCount, columns);

    /* Loop until win or lose */
        /* Print board */
        /* Get input */
        /* Update board and check win/loss */
    system("clear");
    while (gameStatus == PLAYING) 
    {
        gameStatus = makeMove( rows, columns, roadCount, &playerPosition, carPositions, carDirections);
    }

    printBoard(rows, columns, playerPosition, carPositions, carDirections);

    /* Handle Win and Lose */
    if (gameStatus == WIN) {
        printf("You Win\n");
    } else if (gameStatus == LOSE) {
        printf("You Lose\n");
    }


    /* End Game */

    free(carPositions);
    free(carDirections);

    }

    return 0;
}