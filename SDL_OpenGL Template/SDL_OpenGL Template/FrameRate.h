//
//  FrameRate.h
//  HAX
//
//  Created by Zach Lite on 4/26/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __HAX__FrameRate__
#define __HAX__FrameRate__

#include <iostream>
#include <SDL/SDL.h>

struct FRAME_RATE
{
    float frameCount;
    float fps;
    Uint32 PreviousTime;//SDL_GetTicks();
    Uint32 CurrentTime;
};

FRAME_RATE getFrameRateStruct();

void GetFrameRate(float *frameCount, Uint32 *CurrentTime, Uint32 *PreviousTime, float *fps);

void LimitFrameRate(const int FPS, Uint32 start_time);


#endif /* defined(__HAX__FrameRate__) */
