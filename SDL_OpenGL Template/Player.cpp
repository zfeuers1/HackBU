//
//  Player.cpp
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Player.h"
#include "Box.h"

#define BoxHeight 30
#define positions 8

int jump = BoxHeight + 10;

void Player::moveDown(){
    if (position != positions - 1) {
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
        x = 55;
        color.R = 180;
        color.G = 10;
        color.B = 185;
        color.A = 55;
        player = 0;
    }else{
        x = 490;
        color.R = 110;
        color.G = 244;
        color.B = 255;
        color.A = 85;
        player = 1;
    }
    height = 25;
    width = 60;
    y = (BoxHeight / 2) + 98 - (height/2);
    position = 0;
    
}
