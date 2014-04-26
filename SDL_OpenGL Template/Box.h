//
//  Box.h
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __SDL_OpenGL_Template__Box__
#define __SDL_OpenGL_Template__Box__

#include <iostream>
#import "Foundation/Foundation.h"

using namespace std;

struct color{
    char R;
    char G;
    char B;
    char A;
};

class Box{
    
public:
    int x;
    int y;
    string color;
    int width;
    int height;
    int array_position_x;
    int array_position_y;
    bool claimed;
    
    
    Box(int xCord, int yCord);
    Box();
    void set(int xCord, int yCord);
    void Random();
    void setArrayPositions(int i, int j);

};

#endif /* defined(__SDL_OpenGL_Template__Box__) */
