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
    glColor4ub(box.color.R , box.color.G , box.color.B , box.color.A);
    glVertex2f(box.x , box.y);
    glVertex2f(box.x + box.width, box.y);
    glVertex2f(box.x + box.width, box.y + box.height);
    glVertex2f(box.x , box.y + box.height);
    glEnd();
    
    
}