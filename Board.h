

#ifndef CHATGPT_BOARD_H
#define CHATGPT_BOARD_H

#include <iostream>
#include <string>
using namespace std;


class Board{

protected:
    int dimension; // Size of the board
    char** board; // 2D array representing the board
    int countMoves; // Number of moves played on the board
public:
    // Constructor
    Board() {
        dimension = 0;
        countMoves = 0;
    }
    // Setter function for dimension
    void setDimension(int dim) {
        dimension = dim;
        countMoves = 0;
        // Allocate memory for the 2D array
        board = new char* [dimension];
        for (int i = 0; i < dimension; i++) {
            board[i] = new char[dimension];
            for (int j = 0; j < dimension; j++) {
                // Fill the board with numbers from 1 to dim^2
                board[i][j] = '0' + i * dimension + j + 1;
            }
        }
    }
    // Function to display the board
    void displayBoard() {
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                // Display each element of the board with 3 spaces in between
                cout << board[i][j] << "   ";
            }
            cout << endl << endl;
        }
    }
    // Function to update the board with a move
    bool updateBoard(int x, char symbol) {
        // Check if x is in range
        if (x < 1 || x > dimension * dimension) {
            return false;
        }
        // Calculate the row and column of the move
        int row = (x - 1) / dimension;
        int col = (x - 1) % dimension;
        // Check if the move is valid
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            // Update the board and increment countMoves
            board[row][col] = symbol;
            countMoves++;
            return true;
        }
        else {
            return false;
        }
    }
    // Virtual function to check if there is a winner
    virtual bool isWinner(char symbol) = 0;

    // Function to check if it's a draw
    bool isDraw() {
        return (countMoves == dimension * dimension);
    }

    // Destructor to free the memory allocated for the board
    ~Board() {
        for (int i = 0; i < dimension; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

};
#endif //CHATGPT_BOARD_H
