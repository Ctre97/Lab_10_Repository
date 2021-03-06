// Board
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#ifndef H_puzzleBoard
#define H_puzzleBoard

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

class puzzleBoard
{
public:
// the board
    int board[3][3];

    // print the board
    static void printTheBoard(puzzleBoard board);
    // pring goal board
    static void printGoalBoard(puzzleBoard board);
    // overload == for comparing boards
    bool operator==(const puzzleBoard &other);
    // overload of != for comparing
    bool operator!=(const puzzleBoard &other);
    // overload = to be a memberwise copy
    void operator=(const puzzleBoard &other);
    // finds the blank space
    string fillKey(const puzzleBoard board, string key);
    //key for the unordered map
    string key = "" ;
    //queue of the board that came before
    deque <string> traceBack;

}; // end class


// pring board
void puzzleBoard::printTheBoard(puzzleBoard board) // print off the current board
{
    cout << "The board state is : " << endl;
    cout << "_______" << endl; // to create a box around the puzzle
    for (int i = 0; i < 3; i++)
    {
        cout << "|"; // box around the puzzle
        for (int j = 0; j < 3; j++)
        {
            cout << board.board[i][j] << "|"; // prints data and then space divider
        }
        cout << endl;
    }
    cout << "-------" << endl; // bottom of the box around the puzzle
};

// prints the goal state
void puzzleBoard::printGoalBoard(puzzleBoard board) // to print off our goal board
{
    cout << "The Goal Board is : " << endl;
    cout << "_______" << endl; // to create a box around the puzzle
    for (int i = 0; i < 3; i++)
    {
        cout << "|"; // box around the puzzle
        for (int j = 0; j < 3; j++)
        {
            cout << board.board[i][j] << "|"; // prints data and then space divider
        }
        cout << endl;
    }
    cout << "-------" << endl; // bottom of the box around the puzzle
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
bool puzzleBoard::operator!=(const puzzleBoard &other)
{
    if(this->key == other.key){
        return false;
    }
    else{
        return true;
    }
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
// creats a string that is the key from the board state
string puzzleBoard::fillKey(const puzzleBoard board, string key)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char buffer [10];
                key += itoa(board.board[i][j], buffer, 10);
            }
        }
        return key;
    }
#endif
