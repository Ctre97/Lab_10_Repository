//8-Puzzle solvable check
//Collin Trehar and Levi Franklin
//Speed and Power Studios

//isValidMove() function is in creation at the bottom of this file. It will be a function
//for the movePiece class that has not been implemented yet. Thus it is just hanging out here. 


#include <iostream>
#include <cmath>
// #include <vector>
#include "puzzleBoard.h" //class object is not fully functioning yet

using namespace std;

bool checkSolvable(int puzzleInput); // prototype

//will be implemented instead when we get the class object working correctly

int main (int argc, char *argv[]){ //command line input
    int puzzleInput[18]; 
    bool solvable; //variable for results of checkSolvable

    for (int i = 0; i < 19; i++) // puts command line arguments into an array
    {
        puzzleInput[i] = atoi (argv[i]); // converts the char to int 
    }

  
    puzzleBoard firstBoard;

    puzzleBoard goalBoard;
    
    firstBoard.fillTheBoard(puzzleInput);
    firstBoard.printTheBoard();

    goalBoard.createGoalBoard(puzzleInput);
    goalBoard.printGoalBoard();

    firstBoard.findBlank();

    //solvable = checkSolvable(*puzzleInput); // checking for solvable with the initial 1d array. Will be changed out when class is up and running. 

    if (solvable) // if variable returns true
    {
        cout << "Puzzle is solvable!" << endl;
    }
    else // otherwise variable is not true
    {
        cout << "Puzzle is not solvable :(" << endl;
    }

}

// function to check if the problem can be solved. Can be done from original argv input
bool checkSolvable(int puzzleInput[]){
    bool solvable;
    int counter = 0;

    for(int i = 1; i <= 9; i++) // number to be checked
    {
        for (int j = i; j <= 9; j++) // number being checked against
        { 
            if(puzzleInput[i] > puzzleInput[j])
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


// isValidMove(); cannot be fully implemented yet as we do not have a move to pass it yet.
//movemment function will be created this week. Function may be changed when move() is implemented
//but this is the basic principals. We will assume the move is not valid. We will then pass in the
// new 2d array coordinates using [i] and [j]. If those coordinates fit withing what is allowed
// we will assume the move is valid. The movement function will only allow either i or j to be
// incremented or decremented to avoid diagonal moves which are invalid. 

// bool isValidMove(const puzzleBoard &board){
//     bool isValid = false;
//     int i = 0;
//     int j = 0;
//     int tempBoard[i][j];
 
//  if( i >= 0 && i <= 4){
//      isValid = true;
//  }

//  return isValid;

// }