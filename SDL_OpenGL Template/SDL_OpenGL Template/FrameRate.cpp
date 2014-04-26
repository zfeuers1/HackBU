//
//  FrameRate.cpp
//  HAX
//
//  Created by Zach Lite on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "FrameRate.h"


FRAME_RATE getFrameRateStruct()
{
    FRAME_RATE frame_rate;
    return frame_rate;
}


void LimitFrameRate(const int FPS, Uint32 start_time)
{
    if (1000/FPS>SDL_GetTicks()-start_time)
    {
        SDL_Delay(1000/FPS - (SDL_GetTicks()-start_time));
    }
}

void GetFrameRate(float *frameCount, Uint32 *CurrentTime, Uint32 *PreviousTime, float *fps)
{


    
    *frameCount = *frameCount + 1;
    
    *CurrentTime = SDL_GetTicks();
    
    Uint32 timeInterval = *CurrentTime - *PreviousTime;
    
//   
//    if ((1000/max_fps > timeInterval) && should_cap)
//    {
//        SDL_Delay(1000/max_fps - (timeInterval));
//        printf("delay");
//    }
    if (timeInterval > 15)
    {
        
        *fps = *frameCount / (timeInterval * 1000.0f);
        *PreviousTime = *CurrentTime;
        *frameCount = 0;
        
        
    }
    
    
    

    

    //cout << "Frame Rate = " << *fps <<endl;
    
}