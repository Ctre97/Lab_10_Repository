//8-Puzzle solvable check
//Collin Trehar and Levi Franklin
//Speed and Power Studios

#include <iostream>
#include <cmath>

using namespace std;

bool checkSolvable(int a[]); // prototype 


int main (int argc, char *argv[]){ //command line input
    int puzzle[9]; // array of ints to store puzzle pieces
    bool solvable; //variable for results of checkSolvable

    for (int i = 1; i < argc; i++) // puts command line arguments into an array
    {
        puzzle [i] = atoi (argv[i]);
    }

    //I know this is hideous, but it looks pretty when printed out, if you can find a cleaner way to print it, please do.
    cout << "Puzzle inputed is :\n" << "|" << puzzle[1] << " " << puzzle[2] << " " << puzzle[3] << "|\n" << "|" << puzzle[4] << " " << puzzle[5] << " " << puzzle[6] << "|\n" << "|" << puzzle[7] << " " << puzzle[8] << " " << puzzle[9] << "|" << endl;

    solvable = checkSolvable(puzzle); // puts result of function into variable

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