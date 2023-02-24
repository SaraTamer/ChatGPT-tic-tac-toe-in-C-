
#ifndef CHATGPT_XOPLAYER_H
#define CHATGPT_XOPLAYER_H

#include "Player.h"
#include <iostream>

using namespace std;
class XOPlayer : public Player {
public:
    XOPlayer(string n, char s) {
        name = n;
        symbol = s;
    }
    int getMove() override {
        int x;
        cout << name << ", enter your move position: ";
        cin >> x;
        return x;
    }
};

#endif //CHATGPT_XOPLAYER_H
