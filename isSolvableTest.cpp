// 8-Puzzle solvable check
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#include <iostream>
#include <cmath>
#include <deque>
#include "puzzleBoard.h"
#include "move.h"

using namespace std;

bool checkSolvable(puzzleBoard board); // prototype

// will be implemented instead when we get the class object working correctly

int main(int argc, char *argv[])
{ // command line input
    // int puzzleInput[18];
    // int solveInput[9];
    bool solvable; // variable for results of checkSolvable
    deque<puzzleBoard> boardQueue;

    // for (int i = 0; i < 19; i++) // puts command line arguments into an array
    // {
    //     puzzleInput[i] = atoi (argv[i]); // converts the char to int
    // }

    // for (int i = 0; i < 9; i++)
    // {
    //     solveInput[i] = atoi (argv[i]);
    // }

    puzzleBoard initialBoard;
    puzzleBoard goalBoard;

    char *ptr = argv[1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            initialBoard.board[i][j] = (*ptr++ - '0');
        }
    }

    ptr = argv[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            goalBoard.board[i][j] = (*ptr++ - '0');
        }
    }

    initialBoard.printTheBoard(initialBoard);
    boardQueue.push_front(initialBoard);
    goalBoard.printGoalBoard(goalBoard);
    // solvable = checkSolvable(goalBoard);

    checkSolvable(goalBoard);
    solvable = checkSolvable(initialBoard);

    if (solvable) // if variable returns true
    {
        cout << "Puzzle is solvable!" << endl;
    }
    else // otherwise variable is not true
    {
        cout << "Puzzle is not solvable :(" << endl;
    }

    findBlank(boardQueue.front(), boardQueue);

    return 0;
}

// function to check if the problem can be solved. Can be done from original argv input
bool checkSolvable(puzzleBoard board)
{
    bool solvable;
    int counter = 0;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            for (int k = 0; k <= 2; k++) // number to be checked
            {
                for (int l = 0; l <= 2; l++) // number being checked against
                {
                    if (board.board[i][j] > board.board[k][l])
                    {
                        counter++;
                    }
                }
            }
        }
    }
            if (counter % 2 == 0) // if the division results in no remainder it is even
            {
                solvable = true;
            }
            else // it is odd
            {
                solvable = false;
            }
            return solvable;
        }