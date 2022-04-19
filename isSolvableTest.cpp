//8-Puzzle solvable check
//Collin Trehar and Levi Franklin
//Speed and Power Studios

#include <iostream>
#include <cmath>
#include <vector>
#include <puzzleBoard.h>

using namespace std;

// bool checkSolvable(vector<int> puzzle); // prototype 
bool checkSolvable(int *startingBoard);


int main (int argc, char *argv[]){ //command line input
    vector<int> puzzleInput(18); //vector containing the puzzle items
    bool solvable; //variable for results of checkSolvable

    for (int i = 1; i < 3; i++) // puts command line arguments into an array
    {
        puzzleInput[i] = atoi (argv[i]); // converts the char to int 
    }

    //I know this is hideous, but it looks pretty when printed out, if you can find a cleaner way to print it, please do.
    // cout << "Puzzle inputed is :\n" << "|" << startingBoard[0][0] << " " << puzzle[2] << " " << puzzle[3] << "|\n" << "|" << puzzle[4] << " " << puzzle[5] << " " << puzzle[6] << "|\n" << "|" << puzzle[7] << " " << puzzle[8] << " " << puzzle[9] << "|" << endl;

    solvable = checkSolvable(puzzleInput); // puts result of function into variable

    if (solvable) // if variable returns true
    {
        cout << "Puzzle is solvable!" << endl;
    }
    else // otherwise variable is not true
    {
        cout << "Puzzle is not solvable" << endl;
    }
return 0;
}

// //function to fill the board from the argv input
// void fillTheBoard(int puzzleInput[], int *startingBoard[], int row, int col){
//     int i = 0;
//     for(int x = 0; x < row; x++){
//         for (int y = 0; y < 3; y++){
//             startingBoard[y][x] = puzzleInput[i];
//             i++;
//         }
//     }
// }

// function to check if the problem can be solved
bool checkSolvable(vector<int> puzzle){
    bool solvable;
    int counter = 0;

    for(int i = 1; i <= 9; i++) // number to be checked
    {
        for (int j = i; j <= 9; j++) // number being checked against
        { 
            if(puzzle[i] > puzzle[j])
            {
                counter++;
            }
        }
    }
if(counter %2 == 0) // if the division results in no remainder it is even
{
    solvable = true;
}
else // it is odd
{
    solvable = false;
}
return solvable;
}

//board printing
// void print(int *startingBoard[], int row, int col){
//  for (int i = 0; i < row; i++){
//      for (int j =0; j < col; j++){
//          cout << startingBoard[i][j] << " ";
//      }
//      cout << endl;
//  }

// }