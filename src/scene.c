#include "scene.h"

void drawingthescene()
{
	for(i = 0; i < 22; i++)
	{
		for(j=0; j < 22; j++)
		{	
			if(b[i][j]==1)
			{
				glPushMatrix();
				glTranslatef((i-1)*2,1.0,(j-1)*2);
				drawBorder();
				glPopMatrix();
			}

			if(i<20 && j<20)
			{
			if(a[i][j]==1)
			{
				glPushMatrix();
				glTranslatef(j*2,1.0,i*2);
				drawWall();
				glPopMatrix();
			}
			}
		}
	}		
	
	animatePlayer(i,j);
	
	for(i = 0; i < 20; i++)
	{
		for(j=0; j < 20; j++)
		{		
			if(a[i][j]==3)
			{
				animateCoin(i,j);
			}	
		}
	}
}

void drawingtheFloor()
{
	for(i = 0; i < 22; i++)
	{
		for(j=0; j < 22; j++)
		{	
			if(b[i][j]==0)
			{
				glPushMatrix();
				glTranslatef((j-1)*2,1.0,(i-1)*2);
				drawFloor();
				glPopMatrix();
			}	
		}
	}
}

void drawingtheTraps()
{
	for(i = 0; i < 20; i++)
	{
		for(j=0; j < 20; j++)
		{	
			if(a[i][j]==4)
			{	
				animateTrap(i,j);
			}	
		}
	}	
}

void initLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
		
	float ambient_light[] = {0.2, 0.2, 0.2, 1.0};
    float diffuse_light[] = {0.8, 0.8, 0.8, 1.0};
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = {20, 20, 10, 1};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void darkness()
{
    glEnable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    float position[] = {20, 20, 10, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
}