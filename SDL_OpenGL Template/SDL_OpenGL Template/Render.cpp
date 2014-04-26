//
//  Render.cpp
//  SDL_OpenGL Template
//
//  Created by Zach Lite on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Render.h"



void RenderBox(Box &box)
{
    unsigned char r,g,b,a;
    
    
    
    if (box.color == "color1")
    {
        r = 10;
        g = 240;
        b = 200;
        a = 125;
      
    }
    else if (box.color == "color2")
    {
        r = 210;
        g = 240;
        b = 10;
        a = 125;
    }
    
    glBegin(GL_QUADS);
    glColor4ub(r,g,b,a);
    glVertex2f(box.x , box.y);
    glVertex2f(box.x + box.width, box.y);
    glVertex2f(box.x + box.width, box.y + box.height);
    glVertex2f(box.x , box.y + box.height);
    glEnd();
    
}

void RenderPlayer(Player &player){

    glBegin(GL_QUADS);
    glColor4ub(player.color.R , player.color.G , player.color.B , player.color.A);
    glVertex2f(player.x , player.y);
    glVertex2f(player.x + player.width, player.y);
    glVertex2f(player.x + player.width, player.y + player.height);
    glVertex2f(player.x , player.y + player.height);
    glEnd();
    
}