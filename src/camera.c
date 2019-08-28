#include "camera.h"

void animateCamera()
{
	static float tiltycam=1;
	static float tiltxcam=0;
	static float ymoveanim=60;

	static float animangle =0.5125f;

	if(cam1.z>(gatepos[1]*2))
	{
		cam1.z=cam1.z-20*globalelapesdtime;
	}
	
	if(tiltycam<=2)
	{
		tiltycam=tiltycam+0.9*globalelapesdtime;
	}
	
	if(cam1.y>70)
	{
		ymoveanim=-ymoveanim*4;	
	}
	if(cam1.y<=0)
	{
		tiltycam=1;
		tiltxcam=0;
		ymoveanim=60;

		animangle =0.5125f;
		loadNewLevel();	
	}

	cam1.y=cam1.y+ymoveanim*globalelapesdtime;
		
	tiltxcam=tiltxcam+10*globalelapesdtime;
	
	gluLookAt(	cam1.x,	     cam1.y, 	                 cam1.z+1,
			  cam1.x+cam1.lx,      (cam1.y-1.5)/tiltycam,      cam1.z+1+cam1.lz,
			  0.0f,        1.0f,                 0.0f);			
}

void setcamera()
{
	cam1.z = player1.z+6;
	cam1.x = player1.x;
	
	gluLookAt(	cam1.x,	 cam1.y-0.5, 	cam1.z,
			cam1.x+cam1.lx,     cam1.y-2,    cam1.z+cam1.lz,
			0.0f,     1.0f,  0.0f);
}

void lookaroundCamera()
{
	static float zpos = -46;
	zpos=zpos+(zpos*cam1.camMovePz)*globalelapesdtime;

	if(zpos<-99)
	{
		cam1.camMovePz=0;
		zpos=zpos+(-zpos*2)*globalelapesdtime;
	}
	if(zpos>-5)
	{
		cam1.camMovePz=0;
		zpos=zpos+(zpos*2)*globalelapesdtime;
	}
	
	gluLookAt(	0,	 0, 	zpos,
			0,     0,    0,
			0.0f,     1.0f,  0.0f);
		
	if(cam1.rotateY<0)
		cam1.rotateY=0;
	
	if(cam1.rotateY>180)
		cam1.rotateY=180;
	
    glRotatef(-cam1.rotateY, 1.0, 0, 0);
    glRotatef(cam1.rotateX, 0, 1.0, 0);
	glTranslatef(-20,0,-20);
}