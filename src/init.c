#include "init.h"

void initModels()
{
	load_model(&player,"models/ufo/ufo.obj");	
	texture_id[0] = load_texture("models/ufo/ufo.png"); 

	load_model(&wall,"models/wall/wall.obj");	
	texture_id[1] = load_texture("models/wall/wall.png"); 

	load_model(&trap,"models/trap/trap.obj");
	texture_id[2] = load_texture("models/trap/trap.png"); 
	
	load_model(&coin,"models/sandclock/sndclck.obj");
	texture_id[3] = load_texture("models/sandclock/sndclck.png");
		
	load_model(&pyramid,"models/border/border.obj");
    texture_id[4] = load_texture("models/border/sand.png");
	
	texture_id[5] = load_texture("models/floor/floor.png");
	
	tex_sky_id[0] = load_texture("models/sky/up.png");
	tex_sky_id[1] = load_texture("models/sky/down.png");
	tex_sky_id[2] = load_texture("models/sky/front.png");
	tex_sky_id[3] = load_texture("models/sky/back.png");
	tex_sky_id[4] = load_texture("models/sky/left.png");
	tex_sky_id[5] = load_texture("models/sky/right.png");
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

void initBools()
{
	help_visible = TRUE;
	completed = FALSE;
	lookaround_on = FALSE;
	gateopened=FALSE;
	reflection_on=TRUE;
	killed=FALSE;
	lightsoff=FALSE;
}

void init_camera(camera1* camera)
{
    camera->lx = 0.0f;
    camera->lz = -1.0f;
    camera->x = 9.0f;
    camera->y = 12.0f;
    camera->z = 50.0f;
	camera->rotateX = 540;
	camera->rotateY = 36;
	camera->camMovePz = 0;
}

void init_player(Player* player)
{
	player->x = 0;
	player->y = 1.0;
	player->z = 38;
	player->xstart = 0;
	player->ystart = 1.0;
	player->zstart = 38;
	player->deltaMovePx = 0;
	player->deltaMovePz = 0;
	player->fraction = 10.0f;
}

void init()
{
	init_camera(&cam1);
	
	init_player(&player1);
	
	initBools();
	
	maploader("maps/map1.txt");
	borderloader("maps/20x20.txt");
	
	initModels();

    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

	glDisable(GL_CULL_FACE);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

	glEnable(GL_DEPTH_TEST);	
}