#ifndef H_move
#define H_move

#include <iostream>
#include "puzzleBoard.h"

using namespace std;

void moveBlank(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue);
void moveRight(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue);
void moveLeft(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue);
void moveUp(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue);
void moveDown(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue);
bool isValidMove(int i, bool isValid);

void findBlank(puzzleBoard board, deque <puzzleBoard>& boardQueue)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board.board[i][j] == 0)
            {
                moveBlank(board, i, j, boardQueue);
            }
    }
}

void moveBlank(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue)
{
    moveRight(board, i, j, boardQueue);
    moveLeft(board, i, j, boardQueue);
    moveUp(board, i, j, boardQueue);
    moveDown(board, i, j, boardQueue);
}

void moveRight(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    board.board[i + 1][j]; // moves 0 right
    isValidMove(i, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
        boardQueue.push_back(newBoard);
    };
}

void moveLeft(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    board.board[i - 1][j]; // moves 0 left
    isValidMove(i, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
        boardQueue.push_back(newBoard);
    };
}

void moveUp(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    board.board[i][j - 1]; // moves 0 up
    isValidMove(j, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
        boardQueue.push_back(newBoard);
    };
}

void moveDown(puzzleBoard board, int i, int j, deque <puzzleBoard>& boardQueue)
{
    bool isValid = false;
    int temp = 0;
    board.board[i][j + 1]; // moves 0 down
    isValidMove(j, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
        boardQueue.push_back(newBoard);
    };
}

bool isValidMove(int i, bool isValid)
{
    bool checkValid = false;

    if (i >= 0 && i < 2)
    {
        checkValid = true;
    }

    return checkValid;
}

#endif