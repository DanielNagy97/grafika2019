#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "scene.h"

#include <GL/glut.h>

void changeSize(GLsizei width, GLsizei height);
void pressSpecialKey(int key, int xx, int yy);
void releaseSpecialKey(int key, int xx, int yy);
void pressKeyPlayer(unsigned char key, int x, int y);
void releaseKeyPlayer(unsigned char key, int x, int y);
void mouseHandler(int button, int state, int x, int y);
void motionHandler(int x, int y);
void set_callbacks();

#endif /* CALLBACKS_H */