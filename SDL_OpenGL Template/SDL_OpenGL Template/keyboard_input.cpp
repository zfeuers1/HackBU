//
//  input.c
//  SDL_OpenGL Template
//
//  Created by Isaac Patka on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "keyboard_input.h"

using namespace std;

void get_keyboard_input(player_input *input)
{
    
    
    //initialize SDL hardware
	SDL_Init(SDL_INIT_EVERYTHING);
    
    //cout << "SDL is Running\n";
    
  
    bool keystate = false;
    bool last_keystate = false;
    
    bool lastDown = false;
    bool down = false;
    
    SDL_Event event;

    input->quit = false;
        
    
    
    if ( SDL_PollEvent(&event) )
    {
        

        

        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_a))
            input->p1_left = true;
        else
            input->p1_left = false;
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_d))
            input->p1_right = true;
        else
            input->p1_right= false;
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_w))
            input->p1_up = true;
        else
            input->p1_up = false;
        
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_s))
        {
            input->p1_down = true;
        }
        
        else
            input->p1_down = false;

        
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LSHIFT))
            input->p1_fire = true;
        else
            input->p1_fire = false;
        
        
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT))
            input->p2_left = true;
        else
            input->p2_left = false;
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT))
            input->p2_right = true;
        else
            input->p2_right= false;
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP))
            input->p2_up = true;
        else
            input->p2_up = false;
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN))
            input->p2_down = true;
        else
            input->p2_down = false;
        
        if ( (event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RSHIFT))
            input->p2_fire = true;
        else
            input->p2_fire = false;
        
        if (((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE)) || event.type == SDL_QUIT)
        {
        
    
            input->quit = true;

        }
 

    }
    
    
}