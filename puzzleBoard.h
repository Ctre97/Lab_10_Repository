//Board
//Collin Trehar and Levi Franklin
//Speed and Power Studios

#ifndef H_puzzleBoard
#define H_puzzleBoard

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class puzzleBoard{
    public:
    //current state board
    int startingBoard[3][3];

    //goal state board
    int goalBoard[3][3];

    //assign argv items
    void fillTheBoard(int &puzzleInput, int &startingBoard, int row, int col);

    //print the board
    void print(int &startingBoard) const;
    
    private:
    int row = 3;
    int col = 3;
};

//function to fill the board from the argv input
void fillTheBoard(int puzzleInput[], int *startingBoard[], int row, int col){
    int i = 0;
    for(int x = 0; x < row; x++){
        for (int y = 0; y < 3; y++){
            startingBoard[y][x] = puzzleInput[i];
            i++;
        }
    }
}

//board printing
void print(int *startingBoard[], int row, int col){
 for (int i = 0; i < row; i++){
     for (int j =0; j < col; j++){
         cout << startingBoard[i][j] << " ";
     }
     cout << endl;
 }

}

#endif