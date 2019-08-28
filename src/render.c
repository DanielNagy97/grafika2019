#include "render.h"

void renderScene(void) {
	idle();
	
	glClearColor ( 0.0f, 0.0f, 0.0f, 1.0f ) ;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	
	if(lookaround_on)
	{
		lookaroundCamera();
	}
	else if (!lookaround_on && !completed)
	{
		setcamera();	
	}
	else if (!lookaround_on && completed)
	{
		animateCamera();
	}
	
	if(!reflection_on)
	{
	glPushMatrix();
	glTranslatef(20,0,20);
	glRotatef(90,0,1,0);
	drawSky();
	glPopMatrix();
	}

	if(reflection_on)
	{
	glDisable(GL_DEPTH_TEST);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

	/* Draw 1 into the stencil buffer. */
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//glStencilOpSeparate(GL_BACK, GL_KEEP, GL_KEEP, GL_REPLACE);
	//glStencilOpSeparate(GL_FRONT, GL_KEEP, GL_KEEP, GL_KEEP);
	glStencilFunc(GL_ALWAYS, 1, 0xffffffff);

	/* Now drawing the floor just tags the floor pixels
     as stencil value 1. */

	drawingtheFloor();

	/* Re-enable update of color and depth. */ 
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glEnable(GL_DEPTH_TEST);

	/* Now, only render where stencil is set to 1. */
	glStencilFunc(GL_EQUAL, 1, 0xffffffff);  /* draw if stencil ==1 */
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
    glScalef(1, -1, 1);  /* "reflect" across Y=0 plane. */
	
	if(!lightsoff)
	{
		initLighting();
	}
	else
	{
		darkness();
	}
	
	glPushMatrix();
	glTranslatef(20,0,20);
	glRotatef(90,0,1,0);
	drawSky();
	glPopMatrix();

	drawingthescene();

	glPopMatrix();

	glDisable(GL_STENCIL_TEST);
	}
	
	if(!lightsoff)
	{
		initLighting();
	}
	else
	{
		darkness();
	}

    drawingtheFloor();

	drawingthescene();
	
	drawingtheTraps();
	
	if(reflection_on)
	{
	glPushMatrix();
	glTranslatef(20,0,20);
	glRotatef(90,0,1,0);
	drawSky();
	glPopMatrix();
	}
	
	helptext();

	glutSwapBuffers();
}