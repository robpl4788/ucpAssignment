#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "printBoard.h"
#include "moves.h"
#include "constants.h"
#include "setup.h"



int main(int argc, char* argv[]) {
    /* Validate Inputs */

    FILE* gameFile;
    BoardState board;

    /* Confirm inputs are valid and Initialise Map */

    if (validateInputs(argc, argv, &gameFile) && initBoardState(&board, gameFile)) {


    int gameStatus = PLAYING;
  
    /* Loop until win or lose */
        /* Print board */
        /* Get input */
        /* Update board and check win/loss */
    system("clear");

    printBoard(board);

/*
    while (gameStatus == PLAYING) 
    {
        gameStatus = makeMove( rows, columns, roadCount, &playerPosition, carPositions, carDirections);
    }

    printBoard(rows, columns, playerPosition, carPositions, carDirections);
*/
    /* Handle Win and Lose */
    if (gameStatus == WIN) {
        printf("You Win\n");
    } else if (gameStatus == LOSE) {
        printf("You Lose\n");
    }


    /* End Game */

    freeBoardState(&board);

    }

    return 0;
}