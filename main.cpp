#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
#include "variables.h"

#define GL_GLEXT_PROTOTYPES
#define PI 3.141592654
#define SHARPNESS_FACTOR 500



int main(int argc, char* argv[])
{
    // Initialize GLUT Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1080, 1080);
	glutInitWindowPosition(100,100);
	glutCreateWindow("WindMill");
	glEnable(GL_DEPTH_TEST);

	// Iterating Functions
	glutDisplayFunc(drawWindMill);
	glutIdleFunc(rotate);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(rotateWind);
	glutMouseFunc(mouseWheel);
	glutMainLoop();
}
