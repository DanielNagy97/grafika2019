#include "drawing.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(640,360);
	glutCreateWindow("Grafika beadando - Nagy Daniel Zoltan - jj181j");

	init();
	
	set_callbacks();

	glutMainLoop();

	return 1;
}