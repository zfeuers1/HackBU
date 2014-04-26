//
//  Player.cpp
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Player.h"

int jump = 82;

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
        x = 120;
        color.R = 245;
        color.G = 244;
        color.B = 11;
        color.A = 255;
        player = 0;
    }else{
        x = 450;
        color.R = 110;
        color.G = 144;
        color.B = 101;
        color.A = 255;
        player = 1;
    }
    
    y = 115;
    position = 0;
    height = 20;
    width = 20;
}
