#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

/*
 Game is controlled with w a s d for directions *** configurable *** it also supports two modes either to pass through walls or not
*/

#define WIDTH 20 /*defines the map dimensions*/
#define HEIGHT 20

#define WALL_MODE 0 /*Mode == 1 to move through the walls if mode = 0 and the snake hits the wall game is over*/

#define UP_KEY 'w'
#define DOWN_KEY 's'
#define RIGHT_KEY 'd'
#define LEFT_KEY 'a'

typedef enum
{
    STOP =0,
    LEFT ,
    RIGHT,
    UP,
    DOWN

}eDir ;


void Setup (void); /*responsible for the initialization of the variables like the start location of head , fruit and so on*/

void Draw (void); 

void Input (void); /*checks for the direction by getting input from user Asynchrounsly(without stopping the program execution waiting for input)*/

void Logic (void);

//void Sleep (void); /*implemented in windows.h already */


#endif // SNAKE_H_INCLUDED
