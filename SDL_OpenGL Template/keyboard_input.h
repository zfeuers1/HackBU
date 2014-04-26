//
//  keyboard_input.h
//  SDL_OpenGL Template
//
//  Created by Isaac Patka on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef SDL_OpenGL_Template_keyboard_input_h
#define SDL_OpenGL_Template_keyboard_input_h

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL_image/SDL_image.h>

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

using namespace std;

struct player_input{
    bool p1_left;
    bool p1_right;
    bool p1_up;
    bool p1_down;
    bool p1_fire;
    
    bool p2_left;
    bool p2_right;
    bool p2_up;
    bool p2_down;
    bool p2_fire;
    
    bool quit;
};

void get_keyboard_input(player_input *input);


#endif
