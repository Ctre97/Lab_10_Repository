//solvable Checker
//Collin Trehar and Levi Franklin
//Speed and Power Studios

#include <iostream>

using namespace std;

bool checkSolvable(int puzzle[]){
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
if(counter %2 == 0)
{
    solvable = true;
}
else
{
    solvable = false;
}
return solvable;
}