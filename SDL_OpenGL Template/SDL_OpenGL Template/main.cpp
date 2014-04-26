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


#include "Box.h"
#include "Player.h"
#include "Render.h"
#include "Fire.h"

#include "keyboard_input.h"

#include "FrameRate.h"

#define SCREENWIDTH 1000
#define SCREENHEIGHT 650

#define ROWS 8
#define COLUMNS 8


using namespace std;

void Initialize_Memory_Attributes();
void Setup_Window_And_Rendering(int screenWidth, int screenHeight);
void Render_Background_Image(GLuint textureID);
GLuint Initialize_Background_Image();



void Initialize_Gameboard();


int main(int argc, char * argv[])//** argv
{
    
    int x_pos = 0;
    int y_pos = 0;
    int distance_between = 40;


    bool PLAYER1 = 0;
    bool PLAYER2 = 1;

 //game is 600 by 500 starting at (100,75)


    PowerBar power_bar1(PLAYER1);
    PowerBar power_bar2(PLAYER2);
    
    
    Player player1(PLAYER1);
    Player player2(PLAYER2);
   
    

    Box grid[8][8];
    
    for (int i =0; i<8; i++) {
        for (int j=0; j<8; j++) {
            grid[i][j].set(145 + x_pos, 100 + y_pos);
            grid[i][j].Random();
            grid[i][j].setArrayPositions(i, j);
            y_pos = y_pos + distance_between;
        }
        x_pos = x_pos + distance_between;
        y_pos = 0;
    }
    

    
 
    
    //initialize SDL hardware
	SDL_Init(SDL_INIT_EVERYTHING);
    Initialize_Memory_Attributes();
	Setup_Window_And_Rendering(SCREENWIDTH, SCREENHEIGHT);
    GLuint texture;
    texture =Initialize_Background_Image();
    

    UInt32 start_time;
    const int max_FPS = 60;

    

    cout << "SDL is Running\n";
    cout << "OpenGL is Running\n";


    
    
    bool runProgram = true;
    bool menu = true;
    
    player_input input;
    player_input last_input;
    
    bool player1_made_path = false;
    bool player2_made_path = false;
    

    while (menu) {
        
        start_time = SDL_GetTicks();
        
		get_keyboard_input(&input);
        
        if (input.start)
        {
            menu = false;
            
        }
        if (input.quit)
        {
            menu = false;
            runProgram = false;
            
        }
        
        
        
        
        
        //Render to the screen
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();//start phase
		glOrtho(0,SCREENWIDTH,SCREENHEIGHT,0,-1,1);//set the matrix
        /////////////////////////////////////////////
        
        Render_Background_Image(texture);

        RenderBearcat();
        
        
        
        ///////////////////////////////////////////
		glPopMatrix();//end
		SDL_GL_SwapBuffers();//re-drawsf
        
        LimitFrameRate(max_FPS, start_time);
        
    }
    

    bool should_animate = false;

    
	while (runProgram) //Begin main program loop
	{
        start_time = SDL_GetTicks();
        
		get_keyboard_input(&input);
        
        
        //TODO Enumerate for each case
        
        if (input.quit)
        {
            runProgram = false;

        }
        
        if (power_bar1.isEmpty())
        {
            runProgram  = false;
        }
    
        if (power_bar2.isEmpty())
        {
            runProgram =  false; 
        }
        
        
        
        //Player 1 Handling
        
        if(input.p1_down && !last_input.p1_down)
        {
            player1.moveDown();
        }
        if(input.p1_up && !last_input.p1_up)
        {
            player1.moveUp();
   
        }
        if(input.p1_fire && !last_input.p1_fire)
        {
            player1_made_path = Fire(player1, grid);
            
            //should_animate = true;
        
        }
        else
        {
            player1_made_path = false;
            should_animate = false;
        }
        
        
        //Player 2 Handling
        
        if(input.p2_down && !last_input.p2_down)
        {
            player2.moveDown();
        }
        if(input.p2_up && !last_input.p2_up)
        {
            player2.moveUp();
            
        }
        
        if(input.p2_fire && !last_input.p2_fire)
        {
            player2_made_path = Fire(player2, grid);
            //should_animate = true;
        }
        else
        {
            player2_made_path = false;
            should_animate = false;
        }
        
        
        
        if (player1_made_path)
        {
            power_bar2.DecreaseHealth();
        }
        if (player2_made_path)
        {
            power_bar1.DecreaseHealth();
        }
        
        
        
        
        last_input = input;
        
        
        //END EVENT HANDLING
        
        
        
     
        
        //Logic Goes Here

        
        
        
      
        
        //Render to the screen
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();//start phase
		glOrtho(0,SCREENWIDTH,SCREENHEIGHT,0,-1,1);//set the matrix
        /////////////////////////////////////////////
        
        Render_Background_Image(texture);

        
        //things to render goes here
        
        for (int i = 0; i <8; i++) {
            for(int j=0; j<8;j++){
                
                RenderBox(grid[i][j]);

                
            }
        }
       

        RenderPlayer(player1);
        RenderPlayer(player2);
        
        RenderPowerBar(power_bar1);
        RenderPowerBar(power_bar2);
        

        
        ///////////////////////////////////////////
		glPopMatrix();//end
		SDL_GL_SwapBuffers();//re-drawsf
        
        LimitFrameRate(max_FPS, start_time);
        
        
    }//end while
    
    
    
    SDL_Quit();
    cout << "SDL quit\n";
    cout << "OpenGL quit\n";

    
    return 0;
}//end main


/*
 

  ___       _ _      ____
 |_ _|_ __ (_) |_   / ___| __ _ _ __ ___   ___
  | || '_ \| | __| | |  _ / _` | '_ ` _ \ / _ \
  | || | | | | |_  | |_| | (_| | | | | | |  __/
 |___|_| |_|_|\__|  \____|\__,_|_| |_| |_|\___|
 
 
 
 */


void Initialize_Gameboard()
{
    
}


/*
 

  ____  ____  _        _____                    ____ _       ___       _ _
 / ___||  _ \| |      / / _ \ _ __   ___ _ __  / ___| |     |_ _|_ __ (_) |_
 \___ \| | | | |     / / | | | '_ \ / _ \ '_ \| |  _| |      | || '_ \| | __|
 _ __) | |_| | |___ / /| |_| | |_) |  __/ | | | |_| | |___   | || | | | | |_
 |____/|____/|_____/_/  \___/| .__/ \___|_| |_|\____|_____| |___|_| |_|_|\__|
                             |_|
 
 
 */



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
        
        SDL_WM_SetCaption ("Hax", NULL); //window caption
        
        SDL_SetVideoMode(screenWidth,screenHeight,32,SDL_OPENGL|SDL_ANYFORMAT); //window size, rendering settings
        
        


        //draw something every frame
        glClearColor(1,1,1,1); // color used to clear screen every frame
        
        
        glViewport(0,0,screenWidth,screenHeight); //viewing area
        
        glShadeModel(GL_SMOOTH);//shader model
        
        glMatrixMode(GL_PROJECTION);//2D rendering
        glLoadIdentity();//"save" it
        
        glDisable(GL_DEPTH_TEST);//disable depth checking for 2D rendering
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
       
    }

GLuint Initialize_Background_Image()
{
    GLuint TextureID = 0;
    

    SDL_Surface* Surface = IMG_Load("/Users/Zack/Documents/Programming/HackBU/SDL_OpenGL Template/background.png");

    
    glGenTextures(1, &TextureID);
    glBindTexture(GL_TEXTURE_2D, TextureID);
    
    int Mode = GL_RGBA;
    
    if(Surface->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, SCREENWIDTH, SCREENHEIGHT, 0, Mode, GL_UNSIGNED_BYTE, Surface->pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    glBindTexture(GL_TEXTURE_2D, TextureID);
    
    return TextureID;
}





void Render_Background_Image(GLuint textureID)
{
  
    
    // For Ortho mode, of course
 
    int X = 0;
    int Y = 0;
    int Width = 1000;
    int Height = 650;
    
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0); glVertex3f(X, Y, 0);
    glTexCoord2f(1, 0); glVertex3f(X + Width, Y, 0);
    glTexCoord2f(1, 1); glVertex3f(X + Width, Y + Height, 0);
    glTexCoord2f(0, 1); glVertex3f(X, Y + Height, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}





