//
//  Reduce.h
//  HAX
//
//  Created by Isaac Patka on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __HAX__Reduce__
#define __HAX__Reduce__

#include <iostream>

#include "Box.h"
#include "Player.h"

/*struct array_coordinate {
    int x;
    int y;
    bool claimed;
};*/

void Reduce(Box GameBoard[][4], int rows, int columns, int *count);


#endif /* defined(__HAX__Reduce__) */
