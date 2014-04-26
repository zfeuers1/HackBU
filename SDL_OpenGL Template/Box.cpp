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

#define WIDTH 75
#define HEIGHT 75

using namespace std;


Box::Box(int xCord, int yCord){

    x = xCord;
    y = yCord;
    width = WIDTH;
    height = HEIGHT;
    claimed = false;


}
Box::Box(){}

void Box::set(int xCord, int yCord){
 
    
    x = xCord;
    y = yCord;
    width = WIDTH;
    height = HEIGHT;
    
    
    
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
    
    color = "color3";
    
}

void Box::DropTop(){
    //this->Random();
    color = "color3";

}



