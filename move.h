#ifndef H_move
#define H_move

#include <iostream>
#include "puzzleBoard.h"

using namespace std;

void moveBlank(puzzleBoard board, int i, int j);
void moveRight(puzzleBoard board, int i, int j);
void moveLeft(puzzleBoard board, int i, int j);
void moveUp(puzzleBoard board, int i, int j);
void moveDown(puzzleBoard board, int i, int j);
bool isValidMove(int i, bool isValid);

void findBlank(puzzleBoard board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board.board[i][j] == 0)
            {
                moveBlank(board, i, j);
            }
    }
}

void moveBlank(puzzleBoard board, int i, int j)
{
    moveRight(board, i, j);
    moveLeft(board, i, j);
    moveUp(board, i, j);
    moveDown(board, i, j);
}

void moveRight(puzzleBoard board, int i, int j)
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
        newBoard.printTheBoard;
    };
}

void moveLeft(puzzleBoard board, int i, int j)
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
    };
}

void moveUp(puzzleBoard board, int i, int j)
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
    };
}

void moveDown(puzzleBoard board, int i, int j)
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
    };
}

bool isValidMove(int i, bool isValid)
{
    bool checkValid = false;

    if (i >= 0 && i <= 4)
    {
        checkValid = true;
    }

    return checkValid;
}

#endif