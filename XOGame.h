
#ifndef CHATGPT_XOGAME_H
#define CHATGPT_XOGAME_H

#include "Game.h"
#include "XOBoard.h"
#include "XOPlayer.h"

#include <iostream>
#include <string>

using namespace std;

class XOGame : public Game {
public:
    void run() override {
        XOBoard board;
        board.setDimension(3);

        XOPlayer player1("Player 1", 'X');
        XOPlayer player2("Player 2", 'O');

        // Print the initial board
        std::cout << "Initial Board:\n";
        board.displayBoard();

        // Game loop
        while (true) {
            // Player 1 move
            int move = player1.getMove();
            while (!board.updateBoard(move, player1.getSymbol())) {
                std::cout << "Invalid move. Please try again.\n";
                move = player1.getMove();
            }
            std::cout << player1.getName() << " moves " << move << ":\n";
            board.displayBoard();

            // Check if player 1 wins
            if (board.isWinner(player1.getSymbol())) {
                std::cout << player1.getName() << " wins!\n";
                break;
            }
            // Check if it's a draw
            if (board.isDraw()) {
                std::cout << "It's a draw!\n";
                break;
            }

            // Player 2 move
            move = player2.getMove();
            while (!board.updateBoard(move, player2.getSymbol())) {
                std::cout << "Invalid move. Please try again.\n";
                move = player2.getMove();
            }
            std::cout << player2.getName() << " moves " << move << ":\n";
            board.displayBoard();

            // Check if player 2 wins
            if (board.isWinner(player2.getSymbol())) {
                std::cout << player2.getName() << " wins!\n";
                break;
            }
            // Check if it's a draw
            if (board.isDraw()) {
                std::cout << "It's a draw!\n";
                break;
            }
        }
    }
};
#endif //CHATGPT_XOGAME_H
