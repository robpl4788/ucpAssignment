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


/* Sets a designated position to be empty in a board*/
static void newEmpty(int i, int j, BoardState* board)
{
    board->roads[i][j] = FALSE;
}

/* Sets a designated position to be a road in a board*/
static void newRoad(int i, int j, BoardState* board)
{
    board->roads[i][j] = TRUE;
}

/* Sets a designated position to be a car in a board, increments the count of cars*/
static void newCar(int i, int j, BoardState* board, int* carNum)
{
    Vector2d position;
    Vector2d direction = {1, 0};
    Car newCar;

    position.x = i;
    position.y = j;

    newCar.position = position;
    newCar.direction = direction;

    board->roads[i][j] = TRUE;

    *carNum += 1;

    board->car = newCar;
}


/* Sets a designated position to be a player in a board, increments the count of players*/
static void newPlayer(int i, int j, BoardState* board, int* playerNum)
{
    board->roads[i][j] = FALSE;

    *playerNum += 1;

    board->player.x = i;
    board->player.y = j;
}


/* Sets a designated position to be a goal in a board, increments the count of goals*/
static void newGoal(int i, int j, BoardState* board, int* goalNum)
{
    board->roads[i][j] = FALSE;

    *goalNum += 1;

    board->goal.x = i;
    board->goal.y = j;
}


/* Sets a designated position to be what is stated by entry */
static void newEntry(char entry, int i, int j, BoardState* board, int* carNum, int* playerNum, int* goalNum)
{
    if (entry == FILE_EMPTY)
    {
        newEmpty(i, j, board);
    }
    else if (entry == FILE_ROAD)
    {
        newRoad(i, j, board);
    }
    else if (entry == FILE_CAR)
    {            
        newCar(i, j, board, carNum);
    }
    else if (entry == FILE_PLAYER)
    {
        newPlayer(i, j, board, playerNum);
    }
    else if (entry == FILE_GOAL)
    {                
        newGoal(i, j, board, goalNum);
    }
}


/* Confirms that there was only one car, player and goal initialised */
static int confirmNumbers(int carNum, int playerNum, int goalNum)
{
    int succesful = TRUE;

    if (carNum != 1)
    {
        printf("Incorrect number of cars (%d), should be 1\n", carNum);
        succesful = FALSE;
    }
    if (playerNum != 1)
    {
        printf("Incorrect number of players (%d), should be 1\n", playerNum);
        succesful = FALSE;
    }
    if (goalNum != 1)
    {
        printf("Incorrect number of goals (%d), should be 1\n", goalNum);
        succesful = FALSE;
    }

    return succesful;
}


/* Reads through input file and initialises the board state */
int initBoardState(BoardState* board, FILE* inputFile)
{
    int succesful = TRUE;

    int nRead = fscanf(inputFile, "%d %d\n", &board->rows, &board->columns);

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

        char* row = malloc(sizeof(char) * board->columns * 2 + 1);

        if (fgets(row, board->columns * 2 + 1, inputFile) == NULL)
        {
            printf("Error in line %d of input file", i + 2);
        }

        board->roads[i] = malloc(sizeof(int) * board->columns);

        for (j = 0; j < board->columns; j ++)
        {
            int entry = atoi(&row[j * 2]);

            newEntry(entry, i, j, board, &carNum, &playerNum, &goalNum);
            
        }
        free(row);
    }

    succesful = confirmNumbers(carNum, playerNum, goalNum);
    }

    return succesful;
}