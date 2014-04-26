//
//  PowerBar.cpp
//  HAX
//
//  Created by Zach Lite on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "PowerBar.h"

#define WIDTH 75
#define HEIGHT 500


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
        x = 30;
        color = "color1";
    }
    else
    {
        x = 500;
        color = "color2";
    }
    
    y = 0 + (total_health - health_remaining);

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

