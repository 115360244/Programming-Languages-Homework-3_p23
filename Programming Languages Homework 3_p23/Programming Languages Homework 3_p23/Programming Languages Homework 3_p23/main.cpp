#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Status { CONTINUE, WON, LOST };

int rollDice();

int main()
{
    int sum;
    int myPoint;

    Status gameStatus;

    srand(time(NULL));

    sum = rollDice();

    switch (sum)
    {
    case 7:
    case 11:
        gameStatus = WON;
        break;

    case 2:
    case 3:
    case 12:
        gameStatus = LOST;
        break;

    default:
        gameStatus = CONTINUE;
        myPoint = sum;
        cout << "Point is " << myPoint << endl;
        break;
    }

    while (gameStatus == CONTINUE)
    {
        sum = rollDice();

        if (sum == myPoint)
        {
            gameStatus = WON;
        }
        else
        {
            if (sum == 7)
            {
                gameStatus = LOST;
            }
        }
    }

    if (gameStatus == WON)
    {
        cout << "Player wins!" << endl;
    }
    else
    {
        cout << "Player loses!" << endl;
    }

    system("pause");
    return 0;
}

int rollDice()
{
    int die1;
    int die2;
    int workSum;

    die1 = 1 + (rand() % 6);
    die2 = 1 + (rand() % 6);

    workSum = die1 + die2;

    cout << "Player rolled " << die1 << " + "
        << die2 << " = " << workSum << endl;

    return workSum;
}