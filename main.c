#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "printBoard.h"
#include "moves.h"
#include "constants.h"
#include "setup.h"
#include "linkedList.h"



int main(int argc, char* argv[]) {

    FILE* gameFile = NULL;
    BoardState board;

    /* Confirm inputs are valid and Initialise Map, if either fails game is not run */

    if (validateInputs(argc, argv, &gameFile) && initBoardState(&board, gameFile)) {


    int gameStatus = PLAYING;
    LinkedList pastBoards = {NULL};
    
    /*system("clear");*/


    /* Loop until not playing */

    while (gameStatus == PLAYING) 
    {
        gameStatus = takeTurn(&board, &pastBoards);
    }

    printBoard(board);

    /* Handle Win and Lose */
    if (gameStatus == WIN) {
        printf("You Win\n");
    } else if (gameStatus == LOSE) {
        printf("You Lose\n");
    }


    /* End Game */

    freeBoardState(&board);

    freeList(&pastBoards, &free);

    if (gameFile != NULL)
    {
        fclose(gameFile);
    }
    }

    return 0;
}