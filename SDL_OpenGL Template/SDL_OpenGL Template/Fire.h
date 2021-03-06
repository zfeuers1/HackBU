//
//  Fire.h
//  HAX
//
//  Created by Zach Lite on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __HAX__Fire__
#define __HAX__Fire__

#include <iostream>
#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>
#include <SDL/SDL.h>

#include "Box.h"
#include "Player.h"
#include "Render.h"

struct array_coordinate {
    int x;
    int y;
    bool claimed;
};

bool Fire(Player &player, Box GameBoard[][8]);






#endif /* defined(__HAX__Fire__) */
