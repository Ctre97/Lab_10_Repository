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

    // // assign argv items to the 2d array
    static void fillTheBoard(int *list1)
    {
        int t = 1;
        int board[3][3] = {0, 0};
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                //cout << "Initial input: " << list1[t] << " " << endl;
                board[x][y] = list1[t];
                t++;
            }
        }
    }

    //print the board
    static void printTheBoard()
    {
        int tempBoard[3][3];
        cout << "The board state is : " << endl;
        cout << "_______" << endl; // to create a box around the puzzle
        for (int i = 0; i < 3; i++)
        { 
            cout << "|"; // box around the puzzle
            for (int j = 0; j < 3; j++)
            {
                cout << tempBoard[i][j] << "|"; // prints data and then space divider
            }
            cout << endl;
        }
        cout << "-------" << endl; // bottom of the box around the puzzle
    };

    //overload == for comparing boards
    bool operator==(const puzzleBoard &other)
    {
        for (int i = 0; i < 9; i++)
        {
            if (this->board[i] != other.board[i])
            {
                return false;
            }
        }
        return true;
    }

    //overload of != for comparing
    bool operator!=(const puzzleBoard &other) {
        return !(*this == other);
    }

    // //find the blank tile
    void findBlank(){
        int tempBoard[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
            if (tempBoard[i][j] == 0){

                cout << "The blank is at: " << i << "," << j << endl;
            }
        }
    };

}; // end class




#endif