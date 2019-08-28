#include "help.h"

void restorePerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();
	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection()
{
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, w, h, 0);
	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x,float y,float z,void *font,char *string)
{
	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void helptext()
{
	void *font = GLUT_BITMAP_HELVETICA_18;
	
	if(help_visible){
	char s[50];

	sprintf(s, "%d /10 Collected", GetCoin(-1,-1));

	setOrthographicProjection();
	
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);

	glColor4f(0.0f, 0.0f, 0.0f,1.0f);
	renderBitmapString(5,30,0,font,s);
	renderBitmapString(5,54,0,font,(char *)"Hide help: F1");
	renderBitmapString(5,78,0,font,(char *)"2nd cam: F2 (up/down)");
	renderBitmapString(5,102,0,font,(char *)"Reflection off/on: F3");
	renderBitmapString(5,126,0,font,(char *)"Moving: W A S D");
	if (gateopened==TRUE)
	{
		renderBitmapString(5,150,0,font,(char *)"The hole is opened!");
	}
	
	if (completed==TRUE)
	{
		renderBitmapString(5,174,0,font,(char *)"Level Completed!");
	}
	else if(killed)
	{
		renderBitmapString(5,174,0,font,(char *)"You are dead!");
	}

	glColor4f(1.0f, 1.0f, 1.0f,0.8f);
    glBegin(GL_QUADS);
        glVertex3f(0.0f, 200.0f, 0.0f);
        glVertex3f( 220.0f, 200.0f, 0.0f);
        glVertex3f( 220.0f,0.0f, 0.0f);
        glVertex3f(0.0f,0.0f, 0.0f);
    glEnd();

	glEnable(GL_LIGHTING);
	glPopMatrix();

	restorePerspectiveProjection();
	}
}