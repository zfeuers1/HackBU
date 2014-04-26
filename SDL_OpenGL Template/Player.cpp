//
//  Player.cpp
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Player.h"

int jump = 50;

void Player::moveDown(){
    if (position != 4) {
        y = y + jump;
        position++;
    }
}

void Player::moveUp(){
    if (position != 0) {
        y = y - jump;
        position--;
    }
}

Player::Player(){
    
}