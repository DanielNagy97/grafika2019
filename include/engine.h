#ifndef ENGINE_H
#define ENGINE_H

#include "animation.h"

#include <GL/glut.h>

void maploader(char* map);
void borderloader(char* border);
void loadNewLevel();
void WalkedinTrap(int i,int j);
void openGate();
int GetCoin(int i,int j);
void LevelCompleted(int i,int j);
void computePosPlayer(float dMovePx, float dMovePz, double time);
void idle();

#endif /* ENGINE_H */