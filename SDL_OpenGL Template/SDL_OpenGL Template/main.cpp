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


#define PLAYER1 0
#define PLAYER2 1


using namespace std;

void Initialize_Memory_Attributes();
void Setup_Window_And_Rendering(int screenWidth, int screenHeight);
void BackGround();


int main(int argc, char * argv[])//** argv
{
   
    int x = 0;
    int y = 0;

    //game is 600 by 500 starting at (100,75)


    Box firstBox(100,100);
    Player player1(PLAYER1);
    Player player2(PLAYER2);

    Box grid[4][4];
    
    for (int i =0; i<4; i++) {
        for (int j=0; j<4; j++) {
            grid[i][j].set(100 + x, 100 + y);
            grid[i][j].Random();
            grid[i][j].setArrayPositions(i, j);
            y = y + 55;
        }
        x = x + 55;
        y = 0;
    }
    

    
    int screenWidth = 1000;
	int screenHeight = 650;
    
    //initialize SDL hardware
	SDL_Init(SDL_INIT_EVERYTHING);
    Initialize_Memory_Attributes();
	Setup_Window_And_Rendering(screenWidth, screenHeight);
    
    

    cout << "SDL is Running\n";
    cout << "OpenGL is Running\n";




    bool runProgram = true;


    
    
    player_input input;
    player_input last_input;
    
    
   
    
    
	while (runProgram) //Begin main program loop
	{
        
		get_keyboard_input(&input);
        
        
        //TODO Enumerate for each case
        
        if (input.quit)
        {
            runProgram = false;

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
            Fire(player1, grid);
        
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
        
        last_input = input;
        
        
        //END EVENT HANDLING
        
        
        
    
        
        
        
        
        //Logic Goes Here
        
        
        
        
        
        //Render to the screen
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();//start phase
		glOrtho(0,screenWidth,screenHeight,0,-1,1);//set the matrix
        /////////////////////////////////////////////
        
        
        BackGround();
       
        
        
        //things to render goes here
        
        for (int i = 0; i <4; i++) {
            for(int j=0; j<4;j++){
                 RenderBox(grid[i][j]);
            }
        }
       

        RenderPlayer(player1);


        RenderPlayer(player2);
        ///////////////////////////////////////////
		glPopMatrix();//end
		SDL_GL_SwapBuffers();//re-draws
        
    }//end while
    
    
    SDL_Quit();
    cout << "SDL quit\n";
    cout << "OpenGL quit\n";

    
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
        
        glEnable(GL_TEXTURE_2D);
       
    }

void BackGround(){
    GLuint TextureID = 0;
    
    SDL_Surface* Surface = IMG_Load("/Users/Zack/Documents/Programming/HackBU/SDL_OpenGL Template/background.png");
    
    glGenTextures(1, &TextureID);
    glBindTexture(GL_TEXTURE_2D, TextureID);
    
    int Mode = GL_RGB;
    
    if(Surface->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, 1000, 650, 0, Mode, GL_UNSIGNED_BYTE, Surface->pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    glBindTexture(GL_TEXTURE_2D, TextureID);
    
    // For Ortho mode, of course
    int X = 0;
    int Y = 0;
    int Width = 1000;
    int Height = 650;
    
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    //glColor4b(255, 255, 255, 0);
    glColor4f(1,1,1,1);
    glTexCoord2f(0, 0); glVertex3f(X, Y, 0);
    glTexCoord2f(1, 0); glVertex3f(X + Width, Y, 0);
    glTexCoord2f(1, 1); glVertex3f(X + Width, Y + Height, 0);
    glTexCoord2f(0, 1); glVertex3f(X, Y + Height, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}
