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
    int moveCount = 0;

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
    solvable = checkSolvable(initialBoard);

    if (solvable) // if variable returns true
    {
        cout << "Puzzle is solvable!" << endl;
    }
    else // otherwise variable is not true
    {
        cout << "Puzzle is not solvable :( please try again." << endl;
        return 1;
    }

    do
    {
        findBlank(boardQueue);
        boardQueue.pop_front();
        count++;
    }

    while (boardQueue.front().key != goalBoard.key);
    cout << "goal Board found! the count is: " << count << endl;

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
        cout << "  -----------" << endl;
        cout << " | " << boardQueue.front().traceBack.front()[0] << " | " << boardQueue.front().traceBack.front()[1] << " | " << boardQueue.front().traceBack.front()[2] << " | " << endl;
        cout << " | "
             << "---------"
             << " | " << endl;
        cout << " | " << boardQueue.front().traceBack.front()[3] << " | " << boardQueue.front().traceBack.front()[4] << " | " << boardQueue.front().traceBack.front()[5] << " | " << endl;
        cout << " | "
             << "---------"
             << " | " << endl;
        cout << " | " << boardQueue.front().traceBack.front()[6] << " | " << boardQueue.front().traceBack.front()[7] << " | " << boardQueue.front().traceBack.front()[8] << " | " << endl;
        cout << "  -----------" << endl;
        moveCount++;
        boardQueue.front().traceBack.pop_front();
    } while (boardQueue.front().traceBack.size() != 0);

    // This is is original, if you think it looks cleaner, feel free to re-implement it, I know the other code is ridiculous, but in line formatting is lyfe
    // do
    // {
    //     cout << boardQueue.front().traceBack.front()[1] << boardQueue.front().traceBack.front()[2] << boardQueue.front().traceBack.front()[3] << endl;
    //     moveCount++;
    //     boardQueue.front().traceBack.pop_front();
    // } while (boardQueue.front().traceBack.size() != 0);
    cout << "Total Moves: " << moveCount << endl;

    return 0;
}

// function to check if the problem can be solved. Can be done from original argv input
bool checkSolvable(puzzleBoard board)
{
    bool solvable;
    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++) // n
            {
                for (int l = 0; l < 3; l++) // number being checked against
                {
                    if (board.board[i][j] && board.board[k][l] && board.board[i][j] > board.board[k][l])
                    {
                        counter++;
                        cout << counter << endl;
                    }
                    // cout << i << " : " << j << " : " << k << " : " << l << endl;
                }
            }
        }
    }
    if (counter % 2 == 0) // if the division results in no remainder it is even
    {
        solvable = true;
    }
    else if (counter % 2 != 0) // it is odd
    {
        solvable = false;
    }
    return solvable;
}