//
// Created by 82762 on 2021/4/4.
//

#ifndef G_2048_GAME_H
#define G_2048_GAME_H

#include "Player.h"
#include <string>

using namespace std;
class Player;
class Game
{
private:
    bool end;
    int endValue{};
    string mode;
    const int ROW = 4;
    const int COL = 4;
    int blank;
    int **map;

    void run_2048();

    void g_single();

    void g_double();

public:
    void g_test();

    void g_game();

    Game();

    ~Game();

    void play(Player *player1, Player *player2);

    void move(Player *player);

    bool moveUp(Player *player);

    bool moveDown(Player *player);

    bool moveLeft(Player *player);

    bool moveRight(Player *player);

    void add();

    bool print();

    string printNum(int i, int j);

    bool isFull();
};

#endif //G_2048_GAME_H
