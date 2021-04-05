//
// Created by 82762 on 2021/4/4.
//

#ifndef G_2048_PLAYER_H
#define G_2048_PLAYER_H

#include <string>
#include "Game.h"

using namespace std;

class Player {
private:
    string name;
public:
    int score;

    Player(string name);

    Player();

    ~Player();


    const string &getName();
};


#endif //G_2048_PLAYER_H
