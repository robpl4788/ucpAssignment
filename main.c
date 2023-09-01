#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int validateInputs(int* pRows, int* pCols, int* pArgc, char* argv[])
{
    int inputsAreValid = TRUE;

    if (*pArgc != 3) {
        inputsAreValid = FALSE;
        printf("Incorrect number of arguments\n");
    }
    else {
        *pRows = atoi(argv[1]);
        *pCols = atoi(argv[2]);
        if (*pRows < 3 || *pRows % 2 == 0)
        {
            printf("Row number is invalid");
            inputsAreValid = FALSE;
        }
        if (*pCols < 5)
        {
            printf("Column number is invalid");
            inputsAreValid = FALSE;
        }
    }

    return inputsAreValid;
}

int main(int argc, char* argv[]){
    /* Check Inputs */
    int rows, columns;
    
    printf("%d\n", validateInputs(&rows, &columns, &argc, argv));
    printf("%d, %d\n", rows, columns);


    /* Initialise Map */

    /* Loop until win or lose */
        /* Get input */
        /* Update board and check win/loss */
        /* Print updated board */

    /* Handle Win */

    /* Handle Lose*/

    return 0;
}