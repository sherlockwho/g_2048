//
// Created by 82762 on 2021/4/4.
//

#include "Player.h"

Player::Player(string name) {
    this->name = name;
}

Player::~Player() = default;

Player::Player() = default;


const string &Player::getName() {
    return name;
}

