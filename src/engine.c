#include "engine.h"

void maploader(char* map)
{
	FILE *mapfile;
    mapfile = fopen(map, "r");

	for(j=0; j < 20; j++)
	{
		for(i=0; i < 20; i++)
		{	
			fscanf(mapfile, "%1d", &a[j][i]);
			
			if(a[j][i]==5)
			{
				gatepos[0]=i;
				gatepos[1]=j;
			}
		}
	}
	fclose(mapfile);
}

void borderloader(char* border)
{
	FILE *mapfile;
    mapfile = fopen(border, "r");

	for(j=0; j < 22; j++)
	{
		for(i=0; i < 22; i++)
		{	
			fscanf(mapfile, "%1d", &b[j][i]);
		}
	}
	fclose(mapfile);
}

void loadNewLevel()
{
	completed=FALSE;
	gateopened=FALSE;

	maploader("maps/map2.txt");
	borderloader("maps/20x20.txt");
	
	texture_id[1] = load_texture("models/wall/wall2.png"); 

	texture_id[5] = load_texture("models/floor/floor2.png");
	
	cam1.x=9.0f, cam1.z=50.0f, cam1.y=12.0f;
	player1.x=player1.xstart, player1.y=1.0, player1.z=player1.zstart;
}

void WalkedinTrap(int i,int j)
{	
	if(a[i][j]==4 && animateTrap(0,0)>-0.5)	//ha belép a csapdába álljon vissza a kezdő pozícióba
	{	
		killed=TRUE;
		DeathAnimation();
	}	
}

void openGate()
{
	gateopened=TRUE;
	a[gatepos[1]][gatepos[0]]=2;
	b[gatepos[1]+1][gatepos[0]+1]=2;
}

int GetCoin(int i,int j)
{
	static int coincounter=0;
	if(a[i][j]==3)//ha pénz, akkor átírja üresre
	{	
		a[i][j]=0;
		coincounter=coincounter+1;
		
		if (coincounter==10)
		{
			coincounter=0;
			openGate();		
		}
	}
	return coincounter;
}

void LevelCompleted(int i,int j)
{
	if(a[i][j]==2)	//ha belép a végső helyre
	{	
		completed=TRUE;
	}
}

void computePosPlayer(float dMovePx, float dMovePz, double time){

	int j=floor(player1.x+0.75f)/2; //helye a matrixban
	int i=floor(player1.z+0.75f)/2;
	
	static float angle = 0.5125f;
	
	GetCoin(i,j);
	LevelCompleted(i,j);
	WalkedinTrap(i,j);
	
	if(!killed)
	{
		
	if(fabs(dMovePx)<1.0 && fabs(dMovePx)>0)
	{
		player1.deltaMovePx=dMovePx-dMovePx*0.01;
	}		
	if(fabs(dMovePz)<1.0 && fabs(dMovePz)>0)
	{
		player1.deltaMovePz=dMovePz-dMovePz*0.01;
	}
	
	player1.x = player1.x+(dMovePx*player1.fraction)*time;

	if(player1.x+2-0.25>=40.0f || a[i][j+1]==1 && (player1.x+2-0.25f)>=((j+1)*2))
	{
		player1.x = player1.x-(fabs(dMovePx)*player1.fraction)*time;
	}
	else if(player1.x+0.25<=0.0f || a[i][j-1]==1 && (player1.x+0.25f)<=((j-1)*2)+2)
	{
		player1.x = player1.x+(fabs(dMovePx)*player1.fraction)*time;
	}
	
	player1.z = player1.z+(dMovePz*player1.fraction)*time;
	
	if(player1.z+2-0.25>=40.0f || a[i+1][j] == 1 && (player1.z+2-0.25f)>=((i+1)*2))
	{
		player1.z = player1.z-(fabs(dMovePz)*player1.fraction)*time;
	}
	else if(player1.z+0.25<=0.0f || a[i-1][j] == 1 && (player1.z+0.25f)<=((i-1)*2)+2)
	{
		player1.z = player1.z+(fabs(dMovePz)*player1.fraction)*time;
	}
	
	angle=((19.25f-cam1.x)/20);
	cam1.lx =sin(angle);
	}
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
	
    last_frame_time = current_time;
	
	globalelapesdtime=elapsed_time;

	computePosPlayer(player1.deltaMovePx, player1.deltaMovePz, elapsed_time);

    glutPostRedisplay();
}