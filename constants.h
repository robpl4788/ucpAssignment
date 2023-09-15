#ifndef CONSTANTS_H
#define CONSTANTS_H

#define FALSE 0
#define TRUE (!FALSE)

#define WIN 1
#define LOSE -1
#define PLAYING 0

#define LEFT -1
#define RIGHT 1

#define WALL "*"
#define EMPTY " "
#define ROAD "."
#define PLAYER "P"
#define GOAL "G"

#define LEFT_CAR "<"
#define RIGHT_CAR ">"

#define KEY_UP 'w'
#define KEY_LEFT 'a'
#define KEY_DOWN 's'
#define KEY_RIGHT 'd'

typedef struct  
{
    int x;
    int y;
} vector2d;

#endif