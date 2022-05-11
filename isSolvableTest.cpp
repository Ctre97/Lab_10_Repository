// 8-Puzzle solvable check
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#include <iostream>
#include <deque>
#include "puzzleBoard.h"
#include "move.h"

using namespace std;

bool checkSolvable(puzzleBoard initialBoard, puzzleBoard goalBoard); // prototype

int main(int argc, char *argv[])
{
    bool solvable;                     // variable for results of checkSolvable
    deque<puzzleBoard> boardQueue;     // queue for holding open boards
    puzzleBoard initialBoard;
    puzzleBoard goalBoard;
    int count = 0;
    int moveCount = 0;
    cout << "Speed and Power Studios Presents: 8-Puzzle Solver by Levi Franklin and Collin Trehar" << endl;

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
    solvable = checkSolvable(initialBoard, goalBoard);

    if (solvable) // if variable returns true
    {
        cout << "Puzzle is solvable!" << endl;
    }
    else // otherwise variable is not true
    {
        cout << "Puzzle is not solvable :( please try again." << endl;
        return 1;
    }

    // find the solution
    do
    {
        findBlank(boardQueue);
        boardQueue.pop_front();
        count++;
    }

    while (boardQueue.front().key != goalBoard.key);
    cout << "Goal Board found! the number of searched boards is: " << count << endl;

    //output the moves to get to the solution
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

    cout << "Total Moves: " << moveCount << endl;
    cout << "Speed and Power Studios thanks you for your time" << endl;
    return 0;
}

// function to check if the problem can be solved. Can be done from original argv input
bool checkSolvable(puzzleBoard initialBoard, puzzleBoard goalBoard)
{
    bool solvable;
    int counter1 = 0;
    int counter2 = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < 9-1; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if ((initialBoard.key[i]-'0') && (initialBoard.key[j]-'0') && (initialBoard.key[i]-'0') > (initialBoard.key[j]-'0'))
            {counter1++;}
        }
    }
    cout << counter1 << endl;

    for (int i = 0; i < 9-1; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if ((goalBoard.key[i]-'0') && (goalBoard.key[j]-'0') && (goalBoard.key[i]-'0') > (goalBoard.key[j]-'0'))
            {counter2++;}
        }
    }
    cout << counter2 << endl;
    
    
    
    
    if ((counter1 % 2 == 0 && counter2 % 2 == 0) || (counter1 %2 != 0 && counter2 %2 != 0)) // if the inversions on both boards are both even or both odd, board is solvable
    {
        solvable = true;
    }
    else
    {
        solvable = false;
    }
    return solvable;
}
