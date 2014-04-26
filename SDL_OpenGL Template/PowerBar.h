//
//  PowerBar.h
//  HAX
//
//  Created by Zach Lite on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __HAX__PowerBar__
#define __HAX__PowerBar__

#include <iostream>
using namespace std;

class PowerBar{
    
public:
    int x;
    int y;
    string color;
    int width;
    int height;
    float health_remaining;
    float total_health;
    unsigned char Player;

    
    
    PowerBar(unsigned char PlayerNumber);
    PowerBar();
    
    void setFrame();
    void DecreaseHealth();
    bool isEmpty();
 
private:
    void setColor();
    
};

#endif /* defined(__HAX__PowerBar__) */
