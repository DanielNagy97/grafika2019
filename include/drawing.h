#ifndef DRAWING_H
#define DRAWING_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <stdbool.h>
#include <obj/model.h>
#include <obj/load.h>
#include <obj/draw.h>

#include "texture.h"

#include <GL/glut.h>

typedef struct camera1
{
    float lx;
    float lz;
    float x;
	float y;
	float z;
	double rotateX;
	double rotateY;
	float camMovePz;
} camera1;
camera1 cam1;

typedef struct Player
{
    float x;
    float y;
    float z;
	float xstart;
    float ystart;
    float zstart;
	float deltaMovePx;
	float deltaMovePz;
	float fraction;

} Player;
Player player1;

struct Model player;
struct Model wall;
struct Model trap;
struct Model coin;
struct Model pyramid;

GLuint texture_id[6];
GLuint tex_sky_id[6];

int a[20][20];
int b[22][22];

int gatepos[2];

double globalelapesdtime;

int i,j;
int w,h;

bool help_visible;
bool completed;
bool lookaround_on;
bool gateopened;
bool reflection_on;
bool killed;
bool lightsoff;

void setMaterial(GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, int shininess);
void drawBorder();
void drawPlayer();
void drawCoin();
void drawWall();
void drawFloor(void);
void drawTrap(void);
void drawSky(void);

#endif /* DRAWING_H */