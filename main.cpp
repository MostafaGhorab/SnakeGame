#include <iostream>
#include "snake.h"
using namespace std;
#include <Windows.h>

/*Sleep determines speed of snake the less the argument the faster the game*/

extern bool gameOver ;


int main()
{

    char x;
    cout<<"**********WELCOME TO SNAKE GAME**********\n\n\n";
while (1)
{

    cout<<"\n\n\n\n\n\n\n\nSelect Difficulty\n1-Easy\n2-Medium\n3-Hard\n4-PRO\n5-Exit\n" ; /*control speed of game*/
    cin>> x;
    switch (x)
    {
        case '1'  : x=90; break;
        case '2'  : x=80; break;
        case '3'  : x=40; break;
        case '4'  : x=20; break;
        case '5'  : cout <<"\nGOOD BYE\n"; return 0 ; /*exit */
        default : x=90; break;
    }

    Setup ();

while (gameOver == 0)
{
    Draw();
    Input();
    Logic();
    Sleep(x); /*Pauses the execution for some time taken as arguments in milliseconds*/
}

}


}
