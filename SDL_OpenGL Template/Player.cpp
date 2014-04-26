//
//  Player.cpp
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Player.h"
#include "Box.h"

#define BoxHeight 75
#define positions 4

int jump = BoxHeight + 5;

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
        x = 65;
        color.R = 255;
        color.G = 104;
        color.B = 11;
        color.A = 65;
        player = 0;
    }else{
        x = 500;
        color.R = 110;
        color.G = 144;
        color.B = 255;
        color.A = 65;
        player = 1;
    }
    height = 35;
    width = 35;
    y = (BoxHeight / 2) + 100 - (height/2);
    position = 0;
    
}
