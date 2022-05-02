// Board
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#ifndef H_puzzleBoard
#define H_puzzleBoard

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class puzzleBoard
{
public:
    static int board[3][3];

public:
// the board
static int board[3][3];
    // assign argv items to the 2d array for the starting state
    static void fillTheBoard(int *list1);
    // assing argv items to the 2d array for the goal state
    static void createGoalBoard(int *list);
    // print the board
    static void printTheBoard();
    // pring goal board
    static void printGoalBoard();
    // overload == for comparing boards
    bool operator==(const puzzleBoard &other);
    // overload of != for comparing
    bool operator!=(const puzzleBoard &other);
    // overload = to be a memberwise copy
    void operator=(const puzzleBoard &other);
    // finds the blank space
    void findBlank() const;

}; // end class

// fill starting state of board
void puzzleBoard::fillTheBoard(int *list1)
{
    int t = 1;
    int board[3][3] = {0, 0};
    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y)
        {
            // cout << "Initial input: " << list1[t] << " " << endl;
            board[x][y] = list1[t];
            t++;
        }
    }
};

// //fills the goal state of the board
void puzzleBoard::createGoalBoard(int *list)
{
    int t = 10;
    int goalBoard[3][3] = {0, 0};
    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y)
        {
            // cout << "Initial input: " << list1[t] << " " << endl;
            goalBoard[x][y] = list[t];
            t++;
        }
    }
};

// pring board
void puzzleBoard::printTheBoard() // print off the current board
{
    int board[3][3];
    cout << "The board state is : " << endl;
    cout << "_______" << endl; // to create a box around the puzzle
    for (int i = 0; i < 3; i++)
    {
        cout << "|"; // box around the puzzle
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "|"; // prints data and then space divider
        }
        cout << endl;
    }
    cout << "-------" << endl; // bottom of the box around the puzzle
};

// prints the goal state
void puzzleBoard::printGoalBoard() // to print off our goal board
{
    int goalBoard[3][3];
    cout << "The Goal Board is : " << endl;
    cout << "_______" << endl; // to create a box around the puzzle
    for (int i = 0; i < 3; i++)
    {
        cout << "|"; // box around the puzzle
        for (int j = 0; j < 3; j++)
        {
            cout << goalBoard[i][j] << "|"; // prints data and then space divider
        }
        cout << endl;
    }
    cout << "-------" << endl; // bottom of the box around the puzzle
};

// find blank space
void puzzleBoard::findBlank() const
{
    int tempBoard[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tempBoard[i][j] == 0)
                cout << "The blank is at: " << i << "," << j << endl;
        }
    }
};

// overload == for comparing boards
bool puzzleBoard::operator==(const puzzleBoard &other)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->board[i][j] != other.board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// overload of != for comparing
bool puzzleBoard::operator!=(const puzzleBoard &other)
{
    return !(*this == other);
}

// overload of = to memberwise copy
void puzzleBoard::operator=(const puzzleBoard &other)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->board[i][j] = other.board[i][j];
        }
    }
}
#endif