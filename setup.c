#include <stdio.h>
#include <stdlib.h>


#include "constants.h"
#include "setup.h"
#include "random.h"

/*  Checks the input arguments are valid
    If invalid returns false and prints the reason */

int validateInputs(int argc, char* argv[], FILE** gameFile) {
    int inputsAreValid = TRUE;

    if (argc != 2) {
        inputsAreValid = FALSE;
        printf("Incorrect number of arguments, should be 1, is %d\n", argc);
    }
    else {
        *gameFile = fopen(argv[1], "r");
        if (gameFile == NULL)
        {
            printf("File Path (%s) is invalid: ", argv[1]);
            perror("");
            inputsAreValid = FALSE;
        }
    }

    return inputsAreValid;
}

int initBoardState(BoardState* board, FILE* inputFile)
{
    int succesful = TRUE;

    int nRead = fscanf(inputFile, "%d %d", &board->rows, &board->columns);

    if (nRead != 2)
    {
        printf("Input file is invalid, line 1 has %d arguments, expected 2", nRead);
        succesful = FALSE;
    }

    else 
    {
    int i;
    int carNum = 0;
    int goalNum = 0;
    int playerNum = 0;

    board->roads = malloc(sizeof(int*) * board->rows);
    for (i = 0; i < board->rows; i ++)
    {
        int j;

        char* row = malloc(sizeof(char) * board->columns * 2);

        if (fgets(row, board->columns * 2, inputFile) == NULL)
        {
            printf("Error in line %d of input file", i + 2);
        }

        board->roads[i] = malloc(sizeof(int) * board->columns);

        for (j = 0; j < board->columns; j ++)
        {
            int newEntry = row[j * 2];
            Vector2d position;
            position.x = i;
            position.y = j;

            
            if (newEntry == FILE_EMPTY)
            {
                board->roads[i][j] = FALSE;
            }
            else if (newEntry == FILE_ROAD)
            {
                board->roads[i][j] = TRUE;
            }
            else if (newEntry == FILE_CAR)
            {
                Vector2d direction = {1, 0};
                Car newCar;
                newCar.position = position;
                newCar.direction = direction;

                board->roads[i][j] = TRUE;

                carNum ++;

                board->car = newCar;
            }
            else if (newEntry == FILE_PLAYER)
            {
                char symbol = PLAYER;
                Object newPlayer;
                newPlayer.position = position;
                newPlayer.symbol = symbol;
                
                board->roads[i][j] = FALSE;

                playerNum ++;

                board->player = newPlayer;
            }
            else if (newEntry == FILE_GOAL)
            {
                char symbol = GOAL;
                Object newGoal;
                newGoal.position = position;
                newGoal.symbol = symbol;
                
                board->roads[i][j] = FALSE;

                goalNum ++;

                board->goal = newGoal;
            }
            
        }

    }

    if (carNum != 1)
    {
        printf("Incorrect number of cars (%d), should be 1", carNum);
        succesful = FALSE;
    }
    if (playerNum != 1)
    {
        printf("Incorrect number of players (%d), should be 1", carNum);
        succesful = FALSE;
    }
    if (goalNum != 1)
    {
        printf("Incorrect number of goals (%d), should be 1", carNum);
        succesful = FALSE;
    }

    }

    return succesful;
}