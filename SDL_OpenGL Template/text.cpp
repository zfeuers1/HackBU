#include "SDL_ttf.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL.h"

#include <iostream>
#include <sstream>
#include <iomanip> // for setprecision()


#include <GLUT/GLUT.h>
#include <string>
#include <cstring>

using namespace std;


void RenderString(float x, float y, const char *message)
{
    //need glut openGL and string
    
    //glColor4f(100, 100, 100, 255);
    
    glColor3ub(0xB0, 0xB0, 0xB0);
        
    //glRasterPos2f(x, y);
    
    glRasterPos3f(x, y, 0);
    
    glTranslatef(0, 50, 0);
    glRotatef(180, 0, 0, 0);
    
    glScalef(.350, .350, 0);
    
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    
    
for (int i = 0, length = strlen(message); i < length; i++)
    {
        //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)message[i]);
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)message[i]);
    }
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE);
    
    
}


void printHealth(float health, int pos_x, int pos_y)
{
	//in your main while loop

        string message;
    
		stringstream stream;
        
        stream << health;
        
        message = "Health: ";
        
        message = message + stream.str();
                
        const char *Message = message.c_str();

		 RenderString(pos_x, pos_y, Message);

}


