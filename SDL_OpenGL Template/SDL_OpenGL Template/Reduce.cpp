//
//  Reduce.cpp
//  HAX
//
//  Created by Isaac Patka on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Reduce.h"

using namespace std;

void Reduce(Box GameBoard[][4], int rows, int columns, int *count)
{
    string color;
    
    for (int i = columns-1; i >= 0; i--)
    {
        for (int j = rows-1; j >= 0; j--)
        {
            if (GameBoard[i][j].claimed == true)
            {
                
                //(GameBoard[i][j] = GameBoard[i][j-1]);
                GameBoard[i][j].color = "colortest";
            }
                
                
         }
                
    }
    /*int i = 0;
    for (int j = rows-1; j == 0; j--)
    {
        if (GameBoard[i][j].claimed == true)
        {
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
            GameBoard[i][j].claimed = false;
            GameBoard[i][j].color = color;
            
        }
        
        
    }*/
}