//Board
//Collin Trehar and Levi Franklin
//Speed and Power Studios

#ifndef H_puzzleBoard
#define H_puzzleBoard

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class puzzleBoard{
    public:
    //current state
     static int startingBoard[3][3];

    // //Default constructor
    // puzzleBoard();

    // //constructor
    // puzzleBoard(int startingBoard[],int row,int col);

    // //destructor 
    // ~puzzleBoard();


    //assign argv items
   static void fillTheBoard(int &puzzleInput){
    int i = 0;
    for(int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            startingBoard[y][x] = puzzleInput[&i];
            i++;
        }
    }
}

    //print the board
   static void printTheBoard(){

   for (int x = 0; x < 3; x++){
     for (int y =0; y < 3; y++){
         cout << startingBoard[x][y] << " ";
     }
     cout << endl;
 }

};
    
    private:
    int row = 3;
    int col = 3;
};

//function to fill the board from the argv input
// void fillTheBoard(int puzzleInput[], int *startingBoard[], int row, int col){
//     int i = 0;
//     for(int x = 0; x < row; x++){
//         for (int y = 0; y < col; y++){
//             startingBoard[y][x] = puzzleInput[i];
//             i++;
//         }
//     }
// }

//board printing
// void puzzleBoard::printTheBoard(int *startingBoard[], int row, int col){
//  for (int i = 0; i < row; i++){
//      for (int j =0; j < col; j++){
//          cout << startingBoard[i][j] << " ";
//      }
//      cout << endl;
//  }

// }

#endif