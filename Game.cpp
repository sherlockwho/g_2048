//
// Created by 82762 on 2021/4/4.
//

#include <iostream>
#include <cmath>
#include "Game.h"
#include <string>

using namespace std;

Game::~Game() = default;

/**
 * 构造函数
 */
Game::Game() {
    end = false;
    for (int i = 0; i < ROW; i++) {
        map[i] = new int[COL];
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            map[i][j] = 0;
        }
    }
}

/**
 * 测试
 */
void Game::g_test() {
    endValue = 64;
    run_2048();
}

/**
 * 正式游戏
 */
void Game::g_game() {
    endValue = 2048;
    run_2048();
}

/**
 * 游戏大厅
 */
void Game::run_2048() {
    cout << "--------欢迎来到2048！--------" << endl;
    cout << "请选择游戏模式：" << endl;
    cout << "1. 单人模式" << endl;
    cout << "2. 双人模式" << endl;
    cout << "q. 退出游戏" << endl;
    cout << "请键入对应选项的序号： ";
    char opt = cin.get();
    switch (opt) {
        case '1':
            g_single();
            break;
        case '2':
            g_double();
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
}

/**
 * 单人模式
 */
void Game::g_single() {
    cout << "你的名字： " << endl;
    string name;
    getline(cin, name);
    auto player = new Player(name);
    play(player, nullptr);
    delete player;
}

/**
 * 双人模式
 */
void Game::g_double() {
    string name;
    mode = "double";
    cout << "玩家一： " << endl;
    getline(cin, name);
    auto *player1 = new Player(name);
    cout << "玩家二： " << endl;
    getline(cin, name);
    auto *player2 = new Player(name);
    play(player1, player2);
    delete player1;
    delete player2;
}

/**
 * 游戏开始
 * @param player1
 * @param player2
 */
void Game::play(Player *player1, Player *player2) {
    if (mode == "double") {
        while (!end) {
            cout << "下轮操作者为：" << player1->getName() << endl;
            move(player1);
            cout << player1->getName() << "当前得分为：" << player1->score;
            cout << "下轮操作者为：" << player2->getName() << endl;
            move(player2);
            cout << player2->getName() << "当前得分为：" << player2->score;
        }
        cout << " 游戏结束  ";
        if (player1->score != player2->score) {
            cout << ((player1->score > player2->score) ? player1->score : player2->score);
            cout << "获胜!" << endl;
        } else {
            cout << "平局!" << endl;
        }
    } else {
        while (!end) {
            move(player1);
            cout << player1->getName() << "当前得分为：" << player1->score;
        }
        cout << " 游戏结束  最后得分：" << player1->score << endl;
    }
}

/**
 * 玩家操作
 * @param player
 */
void Game::move(Player *player) {
    if (print()) {
        return;
    }//无法移动，游戏结束
    cout << R"("w": move up "z": move down "a": move left "d": move right )" << endl;
    LOOP:
    switch (cin.get()) {
        case 'w':
            if (!moveUp(player)) {
                goto INVALID;
            }
            break;
        case 's':
            if (!moveDown(player)) {
                goto INVALID;
            }
            break;
        case 'a':
            if (!moveLeft(player)) {
                goto INVALID;
            }
            break;
        case 'd':
            if (!moveRight(player)) {
                goto INVALID;
            }
            break;
        default:
        INVALID:
            cout << "无效指令，请重新输入: " << endl;
            goto LOOP;
    }
}

/**
 * 上移操作
 * @param player
 * @return 是否移动过，若没有，为无效操作，返回否
 */
bool Game::moveUp(Player *player) {
    int moved = 0; //是否移动
    for (int i = 0; i < COL; i++) {
        for (int j = 1; j < ROW; j++) {
            if (map[j][i] != 0 && map[j - 1][i] == 0) {
                map[j - 1][i] = map[j][i];
                map[j][i] = 0;
                moved++;
                if (j > 1) {
                    j -= 2;
                }
            }
        }
        for (int j = 1; j < ROW; j++) {
            if (map[j][i] == map[j - 1][i] && map[j - 1][i] != 0) {
                blank += 1;
                map[j - 1][i] += map[j][i];
                map[j][i] = 0;
                player->score += map[j - 1][i];
                end = map[j - 1][i] >= endValue;
                moved++;
            }
        }
        for (int j = 1; j < ROW; j++) {
            if (map[j][i] != 0 && map[j - 1][i] == 0) {
                map[j - 1][i] = map[j][i];
                map[j][i] = 0;
                moved++;
                if (j > 1) {
                    j -= 2;
                }
            }
        }
    }
    if (moved > 0) {
        add();
        return true;
    }
    return false;
}

bool Game::moveDown(Player *player) {
    int moved = 0;
    for (int i = 0; i < COL; i++) {
        for (int j = ROW - 2; j >= 0; j--) {
            if (map[j][i] != 0 && map[j + 1][i] == 0) {
                map[j + 1][i] = map[j][i];
                map[j][i] = 0;
                moved++;
                if (j < ROW - 2) {
                    j += 2;
                }
            }
        }
        for (int j = ROW - 2; j >= 0; j--) {
            if (map[j][i] == map[j + 1][i] && map[j + 1][i] != 0) {
                blank += 1;
                map[j + 1][i] += map[j][i];
                map[j][i] = 0;
                player->score += map[j + 1][i];
                end = map[j + 1][i] >= endValue;
                moved++;
            }
        }
        for (int j = ROW - 2; j >= 0; j--) {
            if (map[j][i] != 0 && map[j + 1][i] == 0) {
                map[j + 1][i] = map[j][i];
                map[j][i] = 0;
                moved++;
                if (j < ROW - 2) {
                    j += 2;
                }
            }
        }
    }
    return false;
}

bool Game::moveLeft(Player *player) {
    int moved = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 1; j < COL; j++) {
            if (map[i][j] != 0 && map[i][j - 1] == 0) {
                map[i][j - 1] = map[i][j];
                map[i][j] = 0;
                moved++;
                if (j > 1) {
                    j -= 2;
                }
            }
        }
        for (int j = 1; j < COL; j++) {
            if (map[i][j] == map[i][j - 1] && map[i][j - 1] != 0) {
                blank += 1;
                map[i][j - 1] += map[i][j];
                map[i][j] = 0;
                player->score += map[i][j - 1];
                end = map[i][j - 1] >= endValue;
                moved++;
            }
        }
        for (int j = 1; j < COL; j++) {
            if (map[i][j] != 0 && map[i][j - 1] == 0) {
                map[i][j - 1] = map[i][j];
                map[i][j] = 0;
                moved++;
                if (j > 1) {
                    j -= 2;
                }
            }
        }
    }
    return false;
}

bool Game::moveRight(Player *player) {
    int moved = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = COL - 2; j >= 0; j--) {
            if (map[i][j] != 0 && map[i][j + 1] == 0) {
                map[i][j + 1] = map[i][j];
                map[i][j] = 0;
                moved++;
                if (j < ROW - 2) {
                    j += 2;
                }
            }
        }
        for (int j = ROW - 2; j >= 0; j--) {
            if (map[i][j] == map[i][j + 1] && map[i][j + 1] != 0) {
                blank += 1;
                map[i][j + 1] += map[i][j];
                map[i][j] = 0;
                player->score += map[i][j + 1];
                end = map[i][j + 1] >= endValue;
                moved++;
            }
        }
        for (int j = COL - 2; j >= 0; j--) {
            if (map[i][j] != 0 && map[i][j + 1] == 0) {
                map[i][j + 1] = map[i][j];
                map[i][j] = 0;
                moved++;
                if (j < ROW - 2) {
                    j += 2;
                }
            }
        }
    }
    return false;
}

void Game::add() {
    srand((unsigned) time(nullptr)); //初始化随机数发生器
    int ran = ((rand() % blank--) + 1);
    for (int i = 0; i < ran; i++) {
        if (map[i / ROW][i % COL] != 0) {
            ran++;
        }
    }
    map[(ran - 1) / ROW][(ran - 1) % COL] = 2;
}

/**
 * 打印游戏主界面
 * @return 返回是否可以继续移动，若为否，游戏结束
 */
bool Game::print() {
    int i = 0, j = 0;
    while (i++ < ROW) //行循环
    {
        while (j++ < COL) //列循环打印边框
        {
            cout << "+-----";
        }
        cout << "+" << endl;
        j = 0;
        while (j++ < COL) //列循环打印数字
        {
            cout << "|";
            map[i - 1][j - 1] == 0 ? cout << "     " : cout << printNum(i, j);
        }
        cout << "|" << endl;
        j = 0;
    }
    while (j++ < COL) {
        cout << "+-----";
    } //打印最后一个边框
    cout << "+" << endl;

    if (isFull()) {
        end = true;
        return true;
    }
    return false;
}

const string Game::printNum(int i, int j) {
    int digit = log10(map[i - 1][j - 1]) + 1;
    string s;
    switch (digit) {
        case 1:
            s = "  " + to_string(map[i - 1][j - 1]) + "  ";
            break;
        case 2:
            s = "  " + to_string(map[i - 1][j - 1]) + " ";
            break;
        case 3:
            s = " " + to_string(map[i - 1][j - 1]) + " ";
            break;
        case 4:
            s = to_string(map[i - 1][j - 1]) + " ";
            break;
        default:
            break;
    }
    return s;
}

bool Game::isFull() {
    bool isFull = false;
    //还有空白格时不需判断
    if (blank != 0) {
        return isFull;
    }
    //格子已经满了，判断是否有相邻的相同数字
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL - 1; j++) {
            if (map[i][j] == map[i][j + 1]) {
                return isFull;
            }
            if (map[j][i] == map[j + 1][i]) {
                return isFull;
            }
        }
    }
    //没有移动空间，游戏结束
    isFull = true;
    return isFull;
}
