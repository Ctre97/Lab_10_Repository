// 8-Puzzle solvable check
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#include <iostream>
#include <cmath>
#include <deque>
#include "puzzleBoard.h"
#include "move.h"
#include <vector>

using namespace std;

bool checkSolvable(puzzleBoard board); // prototype
// will be implemented instead when we get the class object working correctly

int main(int argc, char *argv[])
{
    bool solvable;                     // variable for results of checkSolvable
    deque<puzzleBoard> boardQueue;     // queue for holding open boards
    deque<puzzleBoard *> winningQueue; // board for holding winning moves
    puzzleBoard initialBoard;
    puzzleBoard goalBoard;
    int count = 0;

    char *ptr = argv[1]; // fills initial board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            initialBoard.board[i][j] = (*ptr++ - '0');
        }
    }

    ptr = argv[2]; // fills goal
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            goalBoard.board[i][j] = (*ptr++ - '0');
        }
    }

    initialBoard.printTheBoard(initialBoard);
    initialBoard.key = initialBoard.fillKey(initialBoard, initialBoard.key);
    goalBoard.key = goalBoard.fillKey(goalBoard, goalBoard.key);
    boardQueue.push_front(initialBoard);
    goalBoard.printGoalBoard(goalBoard);
    solvable = checkSolvable(goalBoard);

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

    do
    {
        findBlank(boardQueue);
        boardQueue.pop_front();
        count++;
    }

    while (boardQueue.front().key != goalBoard.key);
    cout<< "goal Board found! the count is: " << count << endl;

    // loopForJuan:
    //      if (boardQueue.front().key != goalBoard.key)
    //      {
    //         findBlank(boardQueue);
    //         boardQueue.pop_front();
    //         count++;
    //         goto loopForJuan;
    //     };
    //     cout << "Goal Board Found!, the count is " << count << endl;

    do
    {
        cout << boardQueue.front().traceBack.back() << endl;
        boardQueue.front().traceBack.pop_back();
    } while (boardQueue.front().traceBack.front() != 0);
    
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