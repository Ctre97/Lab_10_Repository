// 8-Puzzle hashTable
// Collin Trehar and Levi Franklin
// Speed and Power Studios

#ifndef H_hashTable
#define H_hashTable

#include <iostream>
#include <unordered_map>
#include "puzzleBoard.h"
#include <cstring>

using namespace std;

class hashTable
{
public:
    string operator==(const puzzleBoard &board)
    {
        string hash = " ";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hash += board.board[i][j];
            }
            hash.assign(board.key);
        }
        return hash;
    }
};
#endif