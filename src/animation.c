#include "animation.h"

void animateCoin(int i, int j)
{
	static float coiny=1;
	static float coinmove=5;
	
	glPushMatrix();
	glTranslatef(j*2,1,i*2);
	glRotatef(coiny*coinmove,1,1,1);
	drawCoin();
	glPopMatrix();

	coiny=coiny+coinmove*globalelapesdtime;
}

void animatePlayer()
{
	static float playery=1;
	static float pmove=1;
	static float rotate=1;
	static float rotatemove=20;
	
	glPushMatrix();
	glTranslatef(player1.x,playery,player1.z);
	glRotatef(rotate,0,1,0);
	drawPlayer();
	glPopMatrix();
	
	if(playery >=1.5)
		pmove=-1*pmove;
	
	if (playery<=0.2)
		pmove=-1*pmove;
	
	if(!killed)
	{
		rotate = rotate+rotatemove*globalelapesdtime;
		playery=playery+pmove*globalelapesdtime;
	}
}

float animateTrap(int i, int j)
{
	static float trapy=1;
	static float trapymove=0.5;;

	glPushMatrix();
	glTranslatef(j*2,trapy,i*2);
	drawTrap();
	glPopMatrix();

	if(trapy >=1)
		trapymove=-0.1;
	
	if (trapy<=-2)
		trapymove=0.1;
	
	trapy=trapy+trapymove*globalelapesdtime;
	
	return trapy;
}

void DeathAnimation()
{
	static float anim=1;

	if(anim>2)
	{
		lightsoff=TRUE;
		if(anim>2.5)
		{
			player1.x = player1.xstart;
			player1.z = player1.zstart;
			player1.y = player1.ystart;
			player1.deltaMovePx = 0;
			player1.deltaMovePz = 0;
			killed=FALSE;
			anim=1;
			lightsoff=FALSE;
		}
	}
	anim=anim+0.8*globalelapesdtime;
}