//
//  PowerBar.cpp
//  HAX
//
//  Created by Zach Lite on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "PowerBar.h"


#define WIDTH 25
#define HEIGHT 450


PowerBar::PowerBar(unsigned char PlayerNumber)
{
 
    
  
    Player = PlayerNumber;
    total_health = HEIGHT;
    health_remaining = total_health; //percent

    this->setFrame();
    
}


PowerBar::PowerBar(){}


void PowerBar::setFrame()
{
    width = WIDTH;
    height = health_remaining;
    
    if (Player == 0)
    {
        x = 0;
        color = "color1";
    }
    else
    {
        x = 579;
        color = "color2";
    }
    
    y = 25 + (total_health - health_remaining);

}

void PowerBar::DecreaseHealth()
{
    if (!this->isEmpty())
    {
        health_remaining -= HEIGHT/10.0;
        
        this->setFrame();
    }
    
   
    
}

bool PowerBar::isEmpty()
{
    if (health_remaining > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

