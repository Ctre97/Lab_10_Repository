// 8-Puzzle hashTable
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#include <iostream>
#include <unordered_map>
#include <puzzleBoard.h>
#include <cstring>


using namespace std;

class hashTable{
    public:
    //function for creating the hash key based on the puzzle contents
    string operator==(const puzzleBoard &other)const;

    private:
      unordered_map<string, puzzleBoard> hash;
};

// overloads the == operator to create a user defined hash function
// for the unordered_map stl container 
string operator==(const puzzleBoard &board, string hash){
    string hash = "";
    int tempBoard[3][3];
    for (int i =0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hash += tempBoard[i][j];
        }
    }
};


