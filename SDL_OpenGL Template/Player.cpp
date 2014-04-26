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
    if (position != 3) {
        y = y + jump;
        position++;
        array_position ++;
    }
}

void Player::moveUp(){
    if (position != 0) {
        y = y - jump;
        position--;
        array_position --;
    }
}

Player::Player(bool whichPlayer){
    if (whichPlayer == 0) {
        x = 100;
        color.R = 245;
        color.G = 244;
        color.B = 11;
        color.A = 255;
    }else{
        x = 500;
        color.R = 110;
        color.G = 144;
        color.B = 101;
        color.A = 255;
    }
    
    y = 100;
    position = 0;
    height = 20;
    width = 20;
}
