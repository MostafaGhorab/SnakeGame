#include <iostream>
using namespace std;
#include "snake.h"
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAX_TAIL_LEN 100
bool gameOver = 0;
unsigned int x,y ; /*x and y are coordinates of head*/
unsigned int fruitX , fruitY; /*coordinates of fruit*/
unsigned int score ;
eDir dir ;
unsigned int tailCount ;
unsigned int tailX[MAX_TAIL_LEN]; /*keep track of dimensions of all the tail*/
unsigned int tailY[MAX_TAIL_LEN];
void Setup (void)
{
    gameOver = 0;
    x = WIDTH/2; /*initialize the starting point of the snake*/
    y = HEIGHT/2;

    fruitX = rand() % WIDTH +1; /*generates a random number between 1 and width 20*/
    fruitY = rand() % HEIGHT +1;

    dir = STOP ; /*initialize the direction of the snake*/

    score = 0;
    tailCount = 0;


}

/*
######################
#                    #
####################

*/
void Draw (void)
{
 unsigned int  flag = 0;
unsigned int i , j ,k;


system ("cls");  /*clears the screen*/

cout <<"Score:"<<score<<endl;
cout<<"press x to exit"<<endl;

for (i=0;i<WIDTH+2;i++)
    cout<< "#" ;

cout <<endl;

for (j=1;j<HEIGHT+1;j++)
    {
        for (i=0;i<WIDTH+2;i++)
        {
        if(i ==0 )
            cout<< "#" ;
        else if ( i == WIDTH+1)
            cout<< "#" <<endl ;
        else
        {
            if ((i==x) && (j==y))
                cout<<"O";
            else if ((i==fruitX) && (j==fruitY))
            {
                cout<<"F";
            }
            else
            {
                    for (k=0;k<tailCount;k++)
                     {
                         if( (tailX[k]==i) && (tailY[k]==j) )
                         {
                            cout<<"o";
                            flag = 1;

                         }

                     }
                if (flag == 0)
                    cout<<" ";
                else
                    flag = 0;
            }




        }
        }
    }



for (i=0;i<WIDTH+2;i++)
    cout<< "#" ;
cout <<endl;

}

void Input (void)
{
    if (_kbhit()) /*This func makes getting an input asycnh to code so code doesnt stops at getch like interrupt for example */
    {
        switch (_getch())
        {
        case UP_KEY :
            {
                dir = UP;
                break ;
            }

        case DOWN_KEY :
            {
                dir = DOWN;
                break ;

            }

        case  RIGHT_KEY :
            {
                dir = RIGHT;
                break ;
            }
        case LEFT_KEY :
            {
                dir = LEFT;
                break ;
            }
        case 'x' :
            {
                gameOver = 1;
                cout<<"EXIT"<<endl;
                break ;
            }

        default :{}


        }
    }



}


void Logic (void)
{
    unsigned int i,k;

    for (i=tailCount;i>0;i--) /*Update tail locations*/
    {

     tailX [i] = tailX [i-1];
     tailY [i] = tailY [i-1];

    }
      tailX[0] = x; /*keep track of the tail behind the head*/
      tailY[0] = y;

    switch (dir)
    {

    case UP:
    {
        y--;
        break;
    }

     case DOWN:
    {
        y++;
        break;
    }

    case RIGHT:
    {
        x++;
        break;
    }
    case LEFT:
    {
        x--;
        break;
    }

    default : {}

    }

    if (WALL_MODE == 0) /*Snake is not allowed to move through the wall*/
    {

        if ( (x>WIDTH) || (y>HEIGHT) || x==0 || y==0 )
        {
            gameOver = 1;
            cout << "GAME OVER"<<endl ;
        }

    }
    else
    {
        if  (x>WIDTH) x = 1;
        else if (y>HEIGHT) y = 1;
        else if (x==0) x = WIDTH ;
        else if (y==0) y = HEIGHT ;



    }

    if ((x==fruitX) && (y==fruitY)) /*eating a fruit*/
    {
        score+= 1;
        fruitX = rand() % WIDTH +1 ; /*generates a random number between 1 and width 20*/
        fruitY = rand() % HEIGHT +1;
        tailCount ++ ;
        if (tailCount == (MAX_TAIL_LEN-1)) /*in case he reached 100 of score*/
        {
            gameOver =1;
            cout<<"YOU WON"<<endl;
        }
    }

     for (k=0;k<tailCount;k++) /*Game over if the head touch any part of the tail*/
        {
            if( (tailX[k]==x) && (tailY[k]==y) )
            {
                gameOver = 1;
                cout<<"GAME OVER"<<endl;

            }
        }

}

//void Sleep (void)
//{
//
//
//}
