//
//  Render.cpp
//  SDL_OpenGL Template
//
//  Created by Zach Lite on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Render.h"

#define offset_x 101
#define offset_y 75
#define Extra 28


void RenderPowerBar(PowerBar &powerbar)
{
    unsigned char r,g,b,a;
    
    //printf("%f\n", powerbar.health_remaining / 50);
    
    if (powerbar.color == "color1")
    {
        r = 0 + (unsigned char)((powerbar.total_health - powerbar.health_remaining)/2);
        g = 255 - (unsigned char)((powerbar.total_health - powerbar.health_remaining)/2);
        b = 0;
        a = 65;
        
    }
    else if (powerbar.color == "color2")
    {
        r = 0 + (unsigned char)((powerbar.total_health - powerbar.health_remaining)/2);
        g = 255 - (unsigned char)((powerbar.total_health - powerbar.health_remaining)/2);
        b = 0;
        a = 65;
    }

    
    glBegin(GL_QUADS);
    glColor4ub(r,g,b,a);
    glVertex2f(powerbar.x + offset_x , powerbar.y + offset_y+Extra);
    glVertex2f(powerbar.x + powerbar.width + offset_x , powerbar.y + offset_y +Extra);
    glVertex2f(powerbar.x + powerbar.width+ offset_x, powerbar.y + powerbar.height + offset_y+Extra);
    glVertex2f(powerbar.x + offset_x, powerbar.y + powerbar.height + offset_y+Extra);
    glEnd();
}


void RenderBox(Box &box)
{
    unsigned char r,g,b,a;
    
    

    
    
    
    if (box.color == "color1")
    {
        r = 10;
        g = 240;
        b = 200;
        a = 65;
      
    }
    else if (box.color == "color2")
    {
        r = 210;
        g = 240;
        b = 10;
        a = 65;
    }else if(box.color =="color3"){
        r = 255;
        g = 255;
        b = 255;
        a = 125;
    }
    
    glBegin(GL_QUADS);
    glColor4ub(r,g,b,a);
    glVertex2f(box.x + offset_x, box.y + offset_y);
    glVertex2f(box.x + box.width + offset_x, box.y + offset_y);
    glVertex2f(box.x + box.width+ offset_x, box.y + box.height + offset_y);
    glVertex2f(box.x + offset_x, box.y + box.height + offset_y);
    glEnd();
    
}

void RenderPlayer(Player &player){

    glBegin(GL_QUADS);
    glColor4ub(player.color.R , player.color.G , player.color.B , player.color.A);
    glVertex2f(player.x + offset_x, player.y + offset_y);
    glVertex2f(player.x + player.width + offset_x, player.y + offset_y);
    glVertex2f(player.x + player.width + offset_x, player.y + player.height + offset_y);
    glVertex2f(player.x + offset_x, player.y + player.height + offset_y);
    glEnd();
    
}