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
        color.R = 255;
        color.G = 104;
        color.B = 11;
        color.A = 65;
        player = 0;
    }else{
        x = 490;
        color.R = 110;
        color.G = 144;
        color.B = 255;
        color.A = 65;
        player = 1;
    }
    height = 25;
    width = 60;
    y = (BoxHeight / 2) + 98 - (height/2);
    position = 0;
    
}
