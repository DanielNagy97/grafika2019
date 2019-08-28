#include "callbacks.h"

#define VIEWPORT_RATIO (16.0 / 9.0)
#define VIEWPORT_ASPECT 50.0

void changeSize(GLsizei width, GLsizei height)
{
	w=width;
	h=height;
	
    int x, y, ww, hh;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        ww = (int)((double)height * VIEWPORT_RATIO);
        hh = height;
        x = (width - ww) / 2;
        y = 0;
    }
    else {
        ww = width;
        hh = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - hh) / 2;
    }

    glViewport(x, y, ww, hh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEWPORT_ASPECT, VIEWPORT_RATIO, 0.01, -1);
}

void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_F1 :
		if (help_visible) {
            help_visible = FALSE;
        }
        else {
            help_visible = TRUE;
        }
        break;
		case GLUT_KEY_F2 :
		if (lookaround_on) {
            lookaround_on = FALSE;
        }
        else {
            lookaround_on = TRUE;
        }
        break;
		
		case GLUT_KEY_F3 :
		if (reflection_on) {
            reflection_on = FALSE;
        }
        else {
            reflection_on = TRUE;
        }
        break;
		
		case GLUT_KEY_UP : cam1.camMovePz = -2; break;
		case GLUT_KEY_DOWN : cam1.camMovePz = 2; break;
	}
}

void releaseSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_UP : cam1.camMovePz = 0; break;
		case GLUT_KEY_DOWN : cam1.camMovePz = 0; break;	
	}
}

void pressKeyPlayer(unsigned char key, int x, int y)
{
		switch (key) {
		case 'w' : player1.deltaMovePz = -1.0f; break;
		case 's' : player1.deltaMovePz = 1.0f; break;
		case 'a' : player1.deltaMovePx = -1.0f; break;
		case 'd' : player1.deltaMovePx = 1.0f; break;
		}
}

void releaseKeyPlayer(unsigned char key, int x, int y)
{
		switch (key) {
		case 'w' : player1.deltaMovePz = -0.3; break;
		case 's' : player1.deltaMovePz = 0.3; break;
		case 'a' : player1.deltaMovePx = -0.3; break;
		case 'd' : player1.deltaMovePx = 0.3; break;
		}
}

void mouseHandler(int button, int state, int x, int y)
{
}

void motionHandler(int x, int y)
{
    cam1.rotateX = x;
    cam1.rotateY = y;

    glutPostRedisplay();
}

void set_callbacks()
{
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutSpecialFunc(pressSpecialKey);
	glutKeyboardFunc(pressKeyPlayer);

	glutIgnoreKeyRepeat(1);

	glutKeyboardUpFunc(releaseKeyPlayer);
	glutSpecialUpFunc(releaseSpecialKey);
	
	glutMouseFunc(mouseHandler);
    glutMotionFunc(motionHandler);
}