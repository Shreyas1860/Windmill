
#define GL_GLEXT_PROTOTYPES
#define PI 3.141592654
#define SHARPNESS_FACTOR 500




double world_y = 0;	//Used for rotation of world coordinates about y-axis
double wing_z = 90;	//Angle by which wings rotate about z-axis
double wind_y = 0;	//Angle of rotation of direction of wind along y-axis
double r_step = 5.0;	//Angle by which wind_y is incremented/decremented
double scale = 1.0;	//Used for zooming in and out
double world_y_trans = 0;	//Used for translation along y-axis
double wing_speed = 0.0;	//Rotational speed of wings
double wind_acc_factor = .8; 	//Used in viscosity equation as coefficient of wind acceleration
double turbine_factor = 0.005;	//Used in viscosity equation as coefficient of wing speed
double progoffset = 0.0;	//Offset of arrow
double progstep = 0.000;	//Value by which progoffset is incremented/decremented
double progstep_acc = .0005;	//Rate of change of progstep
double torqueFact = 0.00002;	//Used for calculation of power

#include "shapes.h"
#include "user.h"

void resetIdentity()
{
	glLoadIdentity();
	glTranslatef(0.0,world_y_trans,0.0);
	glScalef(scale,scale,scale);	//Scaling used for zooming in and out
}


void drawWindMill()
{
	GLUquadricObj *quadObj = gluNewQuadric();
	char* st = new char[100];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	resetIdentity();
	glRotatef(world_y+90, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	Shaft(.03,.02,.75);

	resetIdentity();
	glRotatef(world_y, 0.0, 1.0, 0.0);
	glTranslatef(0,-0.03,-.07);
	gluCylinder(quadObj, .03, .03, .05, 100, 100);

	resetIdentity();
	glRotatef(world_y, 0.0, 1.0, 0.0);
	glTranslatef(0,-0.03,-.07);
	Cone(.03,.0,.6,.6);


	//Fans
	TriangularWing(0.055,0.05,0.4,0.025,30);
	TriangularWing(0.055,0.05,0.4,0.025,150);
	TriangularWing(0.055,0.05,0.4,0.025,270);

	//Ground
	resetIdentity();
	glRotatef(-10, 1.0, 0.0, 0.0);
	glRotatef(world_y+45, 0.0, 1.0, 0.0);
	for(int i=0;i<1000;++i)
	{
		glBegin (GL_LINES);
			glColor3f  (0,.1+.3*i/1000.0,0);
			glVertex3f  (-.5+i/1000.0,-.75, .5);
			glColor3f  (0,.7+.3*i/1000.0,0);
			glVertex3f  (-.5+i/1000.0,-.75, -.5);
		glEnd();
	}


	glFlush();
	glutSwapBuffers();
}

