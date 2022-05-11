#ifndef H_MOVE
#define H_MOVE


#include <iostream>
#include "puzzleBoard.h"
#include <deque>
#include <unordered_map>
#include <cstring>
#include <vector>

using namespace std;

void moveBlank(int i, int j, deque <puzzleBoard>& boardQueue);
void moveRight(int i, int j, deque <puzzleBoard>& boardQueue);
void moveLeft(int i, int j, deque <puzzleBoard>& boardQueue);
void moveUp(int i, int j, deque <puzzleBoard>& boardQueue);
void moveDown(int i, int j, deque <puzzleBoard>& boardQueue);
bool isValidMove(int i, bool &isValid);

unordered_map <string, puzzleBoard> visited;        // unordered map for key pair of visited boards

void findBlank( deque <puzzleBoard>& boardQueue)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            if (boardQueue.front().board[i][j] == 0)
            {
                moveBlank(i, j, boardQueue);
            }
        }
    }
}

void moveBlank( int i, int j, deque <puzzleBoard>& boardQueue)
{
    moveRight(i, j, boardQueue);
    moveLeft(i, j, boardQueue);
    moveUp(i, j, boardQueue);
    moveDown(i, j, boardQueue);
}

void moveRight( int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    isValidMove(i + 1, isValid);                                     // is the move valid
    if (isValid)                                            
    {
        puzzleBoard newBoard = boardQueue.front();                   //make a new board with the following moves
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
        newBoard.key = "";
        newBoard.key = newBoard.fillKey(newBoard, newBoard.key);     // create a key for the board
        auto it = visited.find(newBoard.key);                        // have we seen this board before?
        if (it == visited.end())                                     // no
        {
        visited.insert(make_pair(newBoard.key, newBoard));           // add board to key/pair list
        newBoard.traceBack = boardQueue.front().traceBack;           // add the history of moves
        newBoard.traceBack.push_back(newBoard.key);                  // add this move to the list of moves
        boardQueue.push_back(newBoard);                              // add the board to the queue
        }
    }
}

//use above technique to move left
void moveLeft( int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    isValidMove(i-1, isValid);
    int tempBoard[3][3];
    if (isValid)
    {
        puzzleBoard newBoard = boardQueue.front();
        temp = newBoard.board[i - 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i - 1][j] = 0;
        newBoard.key = "";
        newBoard.key = newBoard.fillKey(newBoard, newBoard.key);
        auto it = visited.find(newBoard.key);
        if (it == visited.end())
        {
        visited.insert(make_pair(newBoard.key, newBoard));
        newBoard.traceBack = boardQueue.front().traceBack;
        newBoard.traceBack.push_back(newBoard.key);
        boardQueue.push_back(newBoard);
        }
    };
}

//use above technique to move up
void moveUp( int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    isValidMove(j-1, isValid);
    int tempBoard[3][3];
    if (isValid)
    {
        puzzleBoard newBoard = boardQueue.front();
        temp = newBoard.board[i][j - 1];
        newBoard.board[i][j] = temp;
        newBoard.board[i][j - 1] = 0;
        newBoard.key = "";
        newBoard.key = newBoard.fillKey(newBoard, newBoard.key);
        auto it = visited.find(newBoard.key);
        if (it == visited.end())
        {
        visited.insert(make_pair(newBoard.key, newBoard));
        newBoard.traceBack = boardQueue.front().traceBack;
        newBoard.traceBack.push_back(newBoard.key);
        boardQueue.push_back(newBoard);
        }
    };
}

//use above technique to move down
void moveDown( int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    isValidMove(j+1, isValid);
    int tempBoard[3][3];
    if (isValid)
    {
        puzzleBoard newBoard = boardQueue.front();
        temp = newBoard.board[i][j + 1];
        newBoard.board[i][j] = temp;
        newBoard.board[i][j + 1] = 0;
        newBoard.key = "";
        newBoard.key = newBoard.fillKey(newBoard, newBoard.key);
        auto it = visited.find(newBoard.key);
        if (it == visited.end())
        {
        visited.insert(make_pair(newBoard.key, newBoard));
        newBoard.traceBack = boardQueue.front().traceBack;
        newBoard.traceBack.push_back(newBoard.key);
        boardQueue.push_back(newBoard);
        }
    };
}
//checks to see if move is out of bounds 
bool isValidMove(int i, bool &isValid)
{
    if (i >= 0 && i <= 2)
    {
       isValid = true;
    }
    else
    {
        isValid = false;
    }
    return isValid;
}

#endif
