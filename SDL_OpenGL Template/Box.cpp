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

}
Box::Box(){}

void Box::set(int xCord, int yCord){
 
    
    x = xCord;
    y = yCord;
    width = 50;
    height = 50;
    
    
    
}

void Box::Random(){

    int random;
    
    random = arc4random() % 2;
    
    cout << "Random = " << random  << endl;
    if (random == 1) {
        color.R = 10;
        color.G = 240;
        color.B = 200;
        color.A= 255;
    }else{
        color.R = 210;
        color.G = 240;
        color.B = 10;
        color.A= 255;
    }
}




