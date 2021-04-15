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
    int endValue;
    string mode;
    int ROW;
    int COL;
    int blank;
    int **map;
    int cheat;
    string cheater;
    string command;

    void run_2048();

    void g_single();

    void g_double();

    void g_initMap();

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

    void g_level();

    char triggered(Player *player);

    bool canMoveUp();

    bool canMoveDown();

    bool canMoveRight();

    bool canMoveLeft();
};

#endif //G_2048_GAME_H
