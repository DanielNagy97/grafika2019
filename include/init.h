#ifndef INIT_H
#define INIT_H

#include "drawing.h"

#include <GL/glut.h>

void initModels();
void initBools();
void init_camera(camera1* camera);
void init();
void init_player(Player* player);

#endif /* INIT_H */