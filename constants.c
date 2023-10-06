#include "constants.h"

Object* newObject(Vector2d position, char symbol)
{
    Object new = {position, symbol};
    return &new;
}

Car* newCar(Vector2d position, Vector2d direction)
{
    Car new = {position, direction};
    return &new;
}

BoardState* newBoard(Vector2d playerPosistion, Vector2d carPosition, Vector2d carDirection, Vector2d goalPosition)
{
    Object player = *newObject(playerPosistion, PLAYER);
    Car car = *newCar(carPosition, carDirection);
    Object goal = *newObject(goalPosition, GOAL);

    

}