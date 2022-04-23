//8-Puzzle solvable check
//Collin Trehar and Levi Franklin
//Speed and Power Studios

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

    for (int i = 0; i < argc; i++) // puts command line arguments into an array
    {
        puzzleInput[i] = atoi (argv[i]); // converts the char to int 
    }

    //I know this is hideous, but it looks pretty when printed out, if you can find a cleaner way to print it, please do.
    //will have a better printing function built into the class, but it isn't there yet.
    // cout << "Puzzle inputed is :\n" << "|" << puzzleInput[1] << " " << puzzleInput[2] << " " << puzzleInput[3] << "|\n" << "|" << puzzleInput[4] << " " << puzzleInput[5] << " " << puzzleInput[6] << "|\n" << "|" << puzzleInput[7] << " " << puzzleInput[8] << " " << puzzleInput[9] << "|" << endl;
    puzzleBoard firstBoard;
    
    firstBoard.fillTheBoard(puzzleInput);
    firstBoard.printTheBoard();

    cout << "The Blank is at" << firstBoard.findBlank(firstBoard) << endl;

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
