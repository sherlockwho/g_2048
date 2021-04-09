//
// Created by 82762 on 2021/4/4.
//

#include "Player.h"

Player::Player(string name) {
    score = 0;
    this->name = name;
}

Player::~Player() = default;

Player::Player() = default;


const string &Player::getName() {
    return name;
}

const int Player::getScore() {
    return this->score;
}

void Player::addScore(int newScore) {
    score += newScore;
}

