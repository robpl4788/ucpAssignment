#ifndef SETUP_H
#define SETUP_H

int validateInputs(int argc, char* argv[], FILE** gameFile);
int initBoardState(BoardState* board, FILE* inputFile);

#endif