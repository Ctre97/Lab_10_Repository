#ifndef H_move
#define H_move

#include <iostream>
#include "puzzleBoard.h"

using namespace std;

void findBlank(const puzzleBoard *board[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (&board[i][j] == 0)
            {
                moveBlank(board, i, j);
            }
    }
}

void moveBlank(const puzzleBoard *board[], int i, int j)
{
    moveRight(board, i, j);
    moveLeft(board, i, j);
    moveUp(board, i, j);
    moveDown(board, i, j);
}

void moveRight(puzzleBoard board[][3], int i, int j)
{
    bool isValid = false;
    int temp = 0;
    board[i + 1][j]; // moves 0 right
    isValidMove(i, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
    };
}

void moveLeft(const puzzleBoard *board[], int i, int j)
{
    bool isValid = false;
    int temp = 0;
    board[i - 1][j]; // moves 0 left
    isValidMove(i, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
    };
}

void moveUp(const puzzleBoard *board[], int i, int j)
{
    bool isValid = false;
    int temp = 0;
    board[i][j - 1]; // moves 0 up
    isValidMove(j, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
    };
}

void moveDown(const puzzleBoard *board[], int i, int j)
{
    bool isValid = false;
    int temp = 0;
    board[i][j + 1]; // moves 0 down
    isValidMove(j, isValid);
    if (isValid)
    {
        puzzleBoard newBoard = board;
        temp = newBoard.board[i + 1][j];
        newBoard.board[i][j] = temp;
        newBoard.board[i + 1][j] = 0;
    };
}

bool isValidMove(int i, bool isValid)
{
    bool isValid = false;

    if (i >= 0 && i <= 4)
    {
        isValid = true;
    }

    return isValid;
}

#endif