
void Cone(double radius, double height, double c1, double c2,bool flag = true)
{
	int steps = 1000;
	for(int i=0;i<steps;++i)
	{
	double th = (360.0/steps)*i;
	glBegin(GL_LINES);
		if(flag)
			glColor3f  (0.69,0,0);
		else
		glColor3f(c1,0,0);
		glVertex3f(radius*cos(th),radius*sin(th),0);
		if(flag)
		glColor3f(c2,c2,c2);
		else
		glColor3f(c2,0,0);
		glVertex3f(0,0,height);
	glEnd ();
	}
}


void ThreeDtriangle(double base_length, double height, double y_span, double c1, double c2)
{

    c2 = 0.98;
    c1 = 0.92;
	//Down
	for(int i=0;i<=SHARPNESS_FACTOR;i++)
	{
		glBegin(GL_LINES);
			glColor3f(c1,c1,c1);	//Base Color
			glVertex3f(((double)i*base_length)/SHARPNESS_FACTOR-base_length/2,0.0,0.0);
			glColor3f(c2,c2,c2);
			glVertex3f(0.0,0.0,height);
		glEnd();
	}
	//Up
	for(int i=0;i<=SHARPNESS_FACTOR;i++)
	{
		glBegin(GL_LINES);
			glColor3f(c1,c1,c1);	//Base Color
			glVertex3f(((double)i*base_length)/SHARPNESS_FACTOR-base_length/2,y_span,0.0);
			glColor3f(c2,c2,c2);
			glVertex3f(0.0,y_span,height);
		glEnd();
	}
	//Left
	for(int i=0;i<=SHARPNESS_FACTOR;i++)
	{
		glBegin(GL_LINES);
			glColor3f(c2,c2,c2);
			glVertex3f(-1*base_length/2,(double)i*y_span/SHARPNESS_FACTOR,0.0);
			glColor3f(c2,c2,c2);
			glVertex3f(0.0,(double)i*y_span/SHARPNESS_FACTOR,height);
		glEnd();
	}
	//Right
	for(int i=0;i<=SHARPNESS_FACTOR;i++)
	{
		glBegin(GL_LINES);
			glColor3f(c2,c2,c2);
			glVertex3f(base_length/2,(double)i*y_span/SHARPNESS_FACTOR,0.0);
			glColor3f(c2,c2,c2);
			glVertex3f(0.0,(double)i*y_span/SHARPNESS_FACTOR,height);
		glEnd();
	}
	//Front Face
	for(int i=0;i<=SHARPNESS_FACTOR;i++)
	{
		glBegin(GL_LINES);
			glColor3f(c1,c1,c1);
			glVertex3f(-1.0*base_length/2,i*y_span/SHARPNESS_FACTOR,0.0);
			glColor3f(c1,c1,c1);
			glVertex3f(1.0*base_length/2,i*y_span/SHARPNESS_FACTOR,0.0);
		glEnd();
	}
}



void TriangularWing(double base_length, double small_height,double large_height, double y_span, double epoch)
{
	glLoadIdentity();
	glTranslatef(0.0,world_y_trans,0.0);
	glScalef(scale,scale,scale);
	glRotatef(world_y,0.0,1.0,0.0);
	glTranslatef(.0,-0.03,-0.065);
	glRotatef(-wing_z+epoch,0.0,0.0,1.0);
	glRotatef(60,1.0,0.0,0.0);
	glTranslatef(-1.4*small_height,0.0,0.0);
	glRotatef(90,0.0,1.0,0.0);
	ThreeDtriangle(base_length, small_height, y_span, 1.0, 0.6);

	glLoadIdentity();
	glTranslatef(0.0,world_y_trans,0.0);
	glScalef(scale,scale,scale);
	glRotatef(world_y,0.0,1.0,0.0);
	glTranslatef(.0,-0.03,-0.065);
	glRotatef(-wing_z+epoch,0.0,0.0,1.0);
	glRotatef(60,1.0,0.0,0.0);
	glTranslatef(-1.4*small_height,0.0,0.0);
	glRotatef(270,0.0,1.0,0.0);
	ThreeDtriangle(base_length, large_height, y_span, 1.0, 0.6);
}


void Shaft(double r_bottom, double r_top, double height)
{
	int steps = 1000;
	for(int i=0;i<steps;++i)
	{
		double th = (2*PI/steps)*i;
		glBegin (GL_LINES);
			double c = .7 + cos(th)*.2;
			glColor3f  (0.2 , 0, 1);
			glVertex3f  (r_top*cos(th),r_top*sin(th) , 0);
			glVertex3f  (r_bottom*cos(th),r_bottom*sin(th) , height);
		glEnd ();
	}
}

