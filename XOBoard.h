
#ifndef CHATGPT_XOBOARD_H
#define CHATGPT_XOBOARD_H


#include "Game.h"
#include "Board.h"


#include <iostream>
#include <string>

using namespace std;


class XOBoard : public Board {
public:
    // Constructor
    XOBoard() {
        setDimension(3);
    }

    // Implementation of updateBoard() function
    bool updateBoard(int x, char symbol) {
        // Check if x is a valid move
        if (x < 1 || x > dimension * dimension) {
            return false;
        }
        // Get row and column from x
        int row = (x - 1) / dimension;
        int col = (x - 1) % dimension;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = symbol;
            countMoves++;
            return true;
        }
        return false;
    }
    // Implementation of isWinner() function
    bool isWinner(char symbol) {
        // Check rows
        for (int row = 0; row < dimension; row++) {
            bool rowWin = true;
            for (int col = 0; col < dimension; col++) {
                if (board[row][col] != symbol) {
                    rowWin = false;
                    break;
                }
            }
            if (rowWin) {
                return true;
            }
        }

        // Check columns
        for (int col = 0; col < dimension; col++) {
            bool colWin = true;
            for (int row = 0; row < dimension; row++) {
                if (board[row][col] != symbol) {
                    colWin = false;
                    break;
                }
            }
            if (colWin) {
                return true;
            }
        }

        // Check diagonals
        bool diag1Win = true;
        bool diag2Win = true;
        for (int i = 0; i < dimension; i++) {
            if (board[i][i] != symbol) {
                diag1Win = false;
            }
            if (board[i][dimension - i - 1] != symbol) {
                diag2Win = false;
            }
        }
        if (diag1Win || diag2Win) {
            return true;
        }

        // No winner
        return false;
    }

};
#endif //CHATGPT_XOBOARD_H
