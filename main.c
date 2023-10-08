#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "printBoard.h"
#include "moves.h"
#include "constants.h"
#include "setup.h"
#include "linkedList.h"



int main(int argc, char* argv[]) {
    /* Validate Inputs */

    FILE* gameFile;
    BoardState board;

    /* Confirm inputs are valid and Initialise Map */

    if (validateInputs(argc, argv, &gameFile) && initBoardState(&board, gameFile)) {


    int gameStatus = PLAYING;
    LinkedList pastBoards = {NULL};

  
    /* Loop until win or lose */
        /* Print board */
        /* Get input */
        /* Update board and check win/loss */
    /*system("clear");*/


    while (gameStatus == PLAYING) 
    {
        Vector2d playerMove = {0, 0};
        int undo = FALSE;

        printBoard(board);

        while (playerMove.x == 0 && playerMove.y == 0 && !undo)
        {
            getMove(board.rows, board.columns, &undo, &playerMove, &board.player);
        }
        if (undo){
            fflush(stdout);
            if (pastBoards.head != NULL) {
                board = *((BoardState*) (pastBoards.head->data));
                popFront(&pastBoards, &free);
            }

        } else {
            BoardState* initial = malloc(sizeof(BoardState));
            *initial = board;
            pushFront(&pastBoards, initial);

            gameStatus = makeMove(&board, playerMove);
        }
        printf("%d", pastBoards.head == NULL);

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

    }

    return 0;
}