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
    int board[3][3];

    // //Default constructor
    // puzzleBoard(){
    //     for (int x = 0; x < 9; x++){
    //         for (int y = 0; y < 9; y++){
    //         board[x][y] = 0;
    //         }
    //     }
    // }

    // assign argv items to the 2d array
    static void fillTheBoard(int *list1)
    {
        int i = 0;
        int board[3][3];
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                cout << list1[i] << " " << endl;
                board[x][y] = list1[i++];
            }
        }
    }

    // print the board
    static void printTheBoard()
    {
        int board[3][3];
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }
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

    //find the blank tile
    int findBlank(){
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 3; y++){
                if (board[x][y] == 0)
                return board[x][y];
            }
        }
    }

}; // end class

// function to fill the board from the argv input
//  void fillTheBoard(int puzzleInput[], int *startingBoard[], int row, int col){
//      int i = 0;
//      for(int x = 0; x < row; x++){
//          for (int y = 0; y < col; y++){
//              startingBoard[y][x] = puzzleInput[i];
//              i++;
//          }
//      }
//  }

// board printing
//  void puzzleBoard::printTheBoard(int *startingBoard[], int row, int col){
//   for (int i = 0; i < row; i++){
//       for (int j =0; j < col; j++){
//           cout << startingBoard[i][j] << " ";
//       }
//       cout << endl;
//   }

// }

#endif