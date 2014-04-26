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

#define WIDTH 30
#define HEIGHT 30

using namespace std;


Box::Box(int xCord, int yCord){

    x = xCord;
    y = yCord;
    width = WIDTH;
    height = HEIGHT;
    claimed = false;
    
    original_x = xCord;
    original_y = yCord;

    original_height = WIDTH;
    original_width = HEIGHT;

}
Box::Box(){}

void Box::set(int xCord, int yCord){
 
    original_x = xCord;
    original_y = yCord;
    
    x = xCord;
    y = yCord;
    width = WIDTH;
    height = HEIGHT;
    
    original_height = WIDTH;
    original_width = HEIGHT;
    
    
    
}

void Box::setArrayPositions(int i, int j)
{

    array_position_x = i;
    array_position_y = j;
    
    
}

void Box::Random(){

    int random;
    
    random = arc4random() % 3;
    
    if (random == 1)
    {
        color = "color1";
    }
    
    else if(random == 0)
    {
        color = "color2";
    }else{
        color = "color3";
    }
    
    
    
    
    
}


void Box::Drop(Box &aboveBox){
    
    color = aboveBox.color;
    
    
    //transition above color to SW

}

void Box::DropTop(){
    this->Random();


}



