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
    
    
    glBegin(GL_QUADS);
    glColor4ub(box.color.R,box.color.G,box.color.B,box.color.A);
    glVertex2f(350,10);
    glVertex2f(200,10);
    glColor4ub(255,150,0,255);
    glVertex2f(200,60);
    glVertex2f(350,60);
    
    glEnd();
    
    
}