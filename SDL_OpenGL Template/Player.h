//
//  Player.h
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __SDL_OpenGL_Template__Player__
#define __SDL_OpenGL_Template__Player__

#include <iostream>
#include "Box.h"

using namespace std;

class Player{

public:
    int x;
    int y;
    bool player;//either one or zero based on which player
    color color;
    int height;
    int width;
    int position;
    int array_position = 0;
    
    void moveDown();
    void moveUp();
    Player(bool whichPlayer);
};


#endif /* defined(__SDL_OpenGL_Template__Player__) */
