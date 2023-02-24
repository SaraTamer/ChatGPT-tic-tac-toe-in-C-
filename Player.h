
#ifndef CHATGPT_PLAYER_H
#define CHATGPT_PLAYER_H


#include <iostream>
#include <string>

using namespace std;

class Player{
protected:
    string name; // Name of the player
    char symbol; // Symbol used by the player on the board
public:
    // Constructor
    Player() {
        name = "";
        symbol = ' ';
    }

    // Getter function for the symbol
    char getSymbol() {
        return symbol;
    }

    // Getter function for the name
    string getName() {
        return name;
    }
    // Pure virtual function to get the player's move
    virtual int getMove() = 0;
};
#endif //CHATGPT_PLAYER_H
