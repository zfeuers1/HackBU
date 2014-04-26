//
//  Box.cpp
//  SDL_OpenGL Template
//
//  Created by Zachary Feuerstein on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Box.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


Box::Box(int xCord, int yCord){

    x = xCord;
    y = yCord;
    width = 50;
    height = 50;
    claimed = false;

}
Box::Box(){}

void Box::set(int xCord, int yCord){
 
    
    x = xCord;
    y = yCord;
    width = 50;
    height = 50;
    
    
    
}

void Box::setArrayPositions(int i, int j)
{

    array_position_x = i;
    array_position_y = j;
    
    
}

void Box::Random(){

    int random;
    
    random = arc4random() % 2;
    
    if (random == 1)
    {
        color = "color1";
    }
    
    else
    {
        color = "color2";
    }
    
    
    
}


void Box::Drop(Box &aboveBox){
    
    color = aboveBox.color;
    
}



