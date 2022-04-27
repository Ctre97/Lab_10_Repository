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

    // default constructor
    puzzleBoard();

    //copy constructor 
    puzzleBoard(const puzzleBoard &obj) {
    int newBoard[3][3] = {0, 0};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
               newBoard[i][j] = board[i][j];
                
            }
        }
    };

    // // assign argv items to the 2d array
    static void fillTheBoard(int *list1)
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

    // doesn't work yet.
    // seems to override the original filled board. Goal board
    // may need to be an inherited class of puzzleBoard. idk

    static void createGoalBoard(int *list){
        int t = 10;
        int goalBoard[3][3] = {0, 0};
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                //cout << "Initial input: " << list1[t] << " " << endl;
                goalBoard[x][y] = list[t];
                t++;
            }
        }
    };

    // print the board
    static void printTheBoard() // print off the current board
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

    // doesn't work yet.
    // seems to override the original filled board. Goal board
    // may need to be an inherited class of puzzleBoard. idk
    static void printGoalBoard() // to print off our goal board
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

    // overload == for comparing boards
    bool operator==(const puzzleBoard &other)
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
    bool operator!=(const puzzleBoard &other)
    {
        return !(*this == other);
    }

    // //find the blank tile
    // needs to be reconfigued to return the address of the cell holding
    // the zero, but I havent figured that out yet.
    // thus it just does a nice print out for now
    void findBlank()
    {
        int tempBoard[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (tempBoard[i][j] == 0)
                {

                    cout << "The blank is at: " << i << "," << j << endl;
                }
        }
    };

}; // end class

#endif