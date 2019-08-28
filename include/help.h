#ifndef HELP_H
#define HELP_H

#include "scene.h"

#include <GL/glut.h>

void restorePerspectiveProjection();
void setOrthographicProjection();
void renderBitmapString(float x,float y,float z,void *font,char *string);
void helptext();

#endif /* HELP_H */