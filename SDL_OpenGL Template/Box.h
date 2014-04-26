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
    color color;
    int width;
    int height;
private:
    
};

#endif /* defined(__SDL_OpenGL_Template__Box__) */
