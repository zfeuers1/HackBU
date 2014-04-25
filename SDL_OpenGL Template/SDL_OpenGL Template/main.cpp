//
//  main.cpp
//  SDL_OpenGL Template
//
//  Created by Zach Lite on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL_image/SDL_image.h>

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>


using namespace std;

void Initialize_Memory_Attributes();
void Setup_Window_And_Rendering(int screenWidth, int screenHeight);








int main(int argc, char * argv[])//** argv
{

    //game is 600 by 500 starting at (100,75)

    
    int screenWidth = 1000;
	int screenHeight = 650;
    
    //initialize SDL hardware
	SDL_Init(SDL_INIT_EVERYTHING);
    Initialize_Memory_Attributes();
	Setup_Window_And_Rendering(screenWidth, screenHeight);
    
    
    

 
    
    
    
    cout << "SDL is Running\n";
    cout << "OpenGL is Running\n";


    bool runProgram = true;
	bool left, right;
    
	left = false;
	right = false;
    
	SDL_Event event;
    
	while (runProgram) //Begin main program loop
	{
		//Events are tied to key presses, mouse movements, etc
		while ( SDL_PollEvent(&event) )
		{
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                cout << "HEy";
            }
		    if (event.type == SDL_QUIT)
			{
                runProgram = false;
			}
            
		    if ( (event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_ESCAPE))//release a key
			{
                runProgram = false;
			}
        }
        
        
        //Logic Goes Here
        
        
      
        
        //Render to the screen
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();//start phase
		glOrtho(0,screenWidth,screenHeight,0,-1,1);//set the matrix
        /////////////////////////////////////////////
        
        //things to render goes here
        
        glBegin(GL_QUADS);
        glColor4ub(23, 44, 43, 255);
        glVertex2f(100, 100);
        glVertex2f(200, 100);
        glVertex2f(200, 200);
        glVertex2f(100, 200);

        glEnd();
        
        
        
        ///////////////////////////////////////////
		glPopMatrix();//end
		SDL_GL_SwapBuffers();//re-draws
        
    }//end while
    
    
    SDL_Quit();
    
    return 0;
}//end main


    void Initialize_Memory_Attributes()
    {
        //Set OpenGL memory usage
        SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
        SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
        
        SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
        
    }
    
    void Setup_Window_And_Rendering(int screenWidth, int screenHeight)
    {
        
        SDL_WM_SetCaption ("Game", NULL); //window caption
        
        SDL_SetVideoMode(screenWidth,screenHeight,32,SDL_OPENGL); //window size, rendering settings


        
        //draw something every frame
        glClearColor(1,1,1,1); // color used to clear screen every frame
        
        
        glViewport(0,0,screenWidth,screenHeight); //viewing area
        
        glShadeModel(GL_SMOOTH);//shader model
        
        glMatrixMode(GL_PROJECTION);//2D rendering
        glLoadIdentity();//"save" it
        
        glDisable(GL_DEPTH_TEST);//disable depth checking for 2D rendering
        
        
    }
