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
#define Extra 5



void RenderAnimation(NSView *view)
{
    glBegin(GL_QUADS);
    glColor4ub(235,120,33,255);
    glVertex2f(view.frame.origin.x + offset_x , view.frame.origin.y + offset_y+Extra);
    glVertex2f(view.frame.origin.x + view.frame.size.width + offset_x , view.frame.origin.y + offset_y +Extra);
    glVertex2f(view.frame.origin.x + view.frame.size.width + offset_x, view.frame.origin.y + view.frame.size.height + offset_y+Extra);
    glVertex2f(view.frame.origin.x + offset_x, view.frame.origin.y + view.frame.size.height + offset_y+Extra);
    glEnd();
}


void RenderPowerBar(PowerBar &powerbar)
{
    unsigned char r,g,b,a;
    

    
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
        a = 85;
      
    }
    else if (box.color == "color2")
    {
        r = 210;
        g = 240;
        b = 10;
        a = 85;
    }
    else if(box.color =="color3"){
        r = 195;
        g = 10;
        b = 185;
        a = 55;
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


void RenderBearcat(){

    
    
    
    int r = 40;
    int g = 230;
    int b = 40;
    int a = 90;
    
    int x = 50;
    int y = 100;
    int height = 80;
    int width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();

    x = 100;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    
    x = 170;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + 80,  y + height + offset_y);
    glVertex2f(x + 70, y + height + offset_y);
    glEnd();
    
    
    x = 170;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + 140,  y + height + offset_y);
    glVertex2f(x + 130, y + height + offset_y);
    glEnd();
    
    
    x = 235;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    x = 245;
    y = 100;
    height = 10;
    width = 50;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    x = 245;
    y = 170;
    height = 10;
    width = 50;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    x = 325;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    x = 335;
    y = 140;
    height = 30;
    width = 8;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + offset_x, y + offset_y + 14);
    glVertex2f(x + width + offset_x + 40, y + height + offset_y - 70);
    glVertex2f(x + offset_x + 32, y + height + offset_y - 70);
    glEnd();


    
    x = 346;
    y = 141;
    height = 20;
    width = 6;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + offset_x + 8, y + offset_y -8);
    glVertex2f(x + width + offset_x + 36, y + height + offset_y + 18);
    glVertex2f(x + offset_x + 28, y + height + offset_y + 18);
    glEnd();
    
    
    x = 455;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    
    x = 410;
    y = 100;
    height = 10;
    width = 45;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    
    x = 410;
    y = 135;
    height = 10;
    width = 45;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    
    x = 410;
    y = 170;
    height = 10;
    width = 45;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    
    x = 500;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    x = 550;
    y = 100;
    height = 80;
    width = 10;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
    x = 510;
    y = 170;
    height = 10;
    width = 40;
    
    glBegin(GL_QUADS);
    glColor4ub(r, g , b , a);
    glVertex2f(x + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + offset_y);
    glVertex2f(x + width + offset_x, y + height + offset_y);
    glVertex2f(x + offset_x, y + height + offset_y);
    glEnd();
    
}


