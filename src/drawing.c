#include "drawing.h"

GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
GLfloat traqaWhite[] = {1.0, 1.0, 1.0, 0.7};
GLfloat glass[] = {1.0, 1.0, 1.0, 0.5};

void setMaterial(GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, int shininess)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void drawBorder()
{
	setMaterial(qaWhite, qaWhite, qaWhite, 50);
	glBindTexture(GL_TEXTURE_2D, texture_id[4]);
	draw_model(&pyramid);
}

void drawPlayer()
{
	setMaterial(qaWhite, qaWhite, qaWhite, 10);
	glBindTexture(GL_TEXTURE_2D, texture_id[0]);
	glPushMatrix();
	glScalef(0.75,0.75,0.75);
	draw_model(&player);
	glPopMatrix();
}

void drawCoin()
{
	setMaterial(glass, glass, glass, 10);
	glBindTexture(GL_TEXTURE_2D, texture_id[3]);
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	draw_model(&coin);
	glPopMatrix();
}

void drawWall()
{
	setMaterial(qaWhite, qaWhite, qaWhite, 30);
	glBindTexture(GL_TEXTURE_2D, texture_id[1]);	
	draw_model(&wall);
}

void drawFloor(void)
{
	setMaterial(traqaWhite, traqaWhite, traqaWhite, 5);
	glBindTexture(GL_TEXTURE_2D, texture_id[5]);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0,0.0);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0,0.0);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glEnd();
}

void drawTrap(void)
{
	setMaterial(qaWhite, qaWhite, qaWhite, 5);
	glBindTexture(GL_TEXTURE_2D, texture_id[2]);
	glPushMatrix();
	glTranslatef(0,-1,0);
	draw_model(&trap);
	glPopMatrix();
}

void drawSky(void)
{
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
	setMaterial(qaWhite, qaWhite, qaWhite, 5);
	
	float size=100;
	
	//up
	glBindTexture(GL_TEXTURE_2D, tex_sky_id[0]);
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 1.0f, 0.0f);	 
		glTexCoord2f(0.0,0.0);
      glVertex3f( size, size, -size);
	  glTexCoord2f(0.0, 1.0);
      glVertex3f(-size, size, -size);
	  glTexCoord2f(1.0, 1.0);
      glVertex3f(-size, size,  size);
	  glTexCoord2f(1.0,0.0);
      glVertex3f( size, size,  size);
	glEnd();
	
    //bottom
	glBindTexture(GL_TEXTURE_2D, tex_sky_id[1]);
	glBegin(GL_QUADS);
		glNormal3f(0.0f, -1.0f, 0.0f);	
		glTexCoord2f(0.0,0.0);
      glVertex3f( size, -size,  size);
	  glTexCoord2f(0.0, 1.0);
      glVertex3f(-size, -size,  size);
	  glTexCoord2f(1.0, 1.0);
      glVertex3f(-size, -size, -size);
	  glTexCoord2f(1.0,0.0);
      glVertex3f( size, -size, -size);
	glEnd();

    //front
	glBindTexture(GL_TEXTURE_2D, tex_sky_id[3]);
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);	  
		glTexCoord2f(0.0,0.0);
      glVertex3f( size,  size, size);
	  glTexCoord2f(0.0, 1.0);
      glVertex3f(-size,  size, size);
	  glTexCoord2f(1.0, 1.0);
      glVertex3f(-size, -size, size);
	  glTexCoord2f(1.0,0.0);
      glVertex3f( size, -size, size);
	glEnd();
	
	//back
	glBindTexture(GL_TEXTURE_2D, tex_sky_id[2]);
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, -1.0f);			 
		glTexCoord2f(0.0,0.0);
      glVertex3f( size, -size, -size);
	  glTexCoord2f(0.0, 1.0);
      glVertex3f(-size, -size, -size);
	  glTexCoord2f(1.0, 1.0);
      glVertex3f(-size,  size, -size);
	  glTexCoord2f(1.0,0.0);
      glVertex3f( size,  size, -size);
	glEnd();

	//left
	glBindTexture(GL_TEXTURE_2D, tex_sky_id[5]);
	glBegin(GL_QUADS);
		glNormal3f(-1.0f, 0.0f, 0.0f);	  
		glTexCoord2f(0.0,0.0);
      glVertex3f(-size,  size,  size);
	  glTexCoord2f(0.0, 1.0);
      glVertex3f(-size,  size, -size);
	  glTexCoord2f(1.0, 1.0);
      glVertex3f(-size, -size, -size);
	  glTexCoord2f(1.0,0.0);
      glVertex3f(-size, -size,  size);
	glEnd();
 
    //right
	glBindTexture(GL_TEXTURE_2D, tex_sky_id[4]);
	glBegin(GL_QUADS);
		glNormal3f(1.0f, 0.0f, 0.0f);	
		glTexCoord2f(0.0,0.0);
      glVertex3f(size,  size, -size);
	  glTexCoord2f(0.0, 1.0);
      glVertex3f(size,  size,  size);
	  glTexCoord2f(1.0, 1.0);
      glVertex3f(size, -size,  size);
	  glTexCoord2f(1.0,0.0);
      glVertex3f(size, -size, -size);
	glEnd();  
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}