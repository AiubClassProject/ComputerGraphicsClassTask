#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>
#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>


# define PI  3.14159265358979323846
void Assignment2(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Green
	glBegin(GL_QUADS);
	glColor3ub(0, 155, 58);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();

	// yellow
	glBegin(GL_QUADS);
	glColor3ub(245, 223, 0);
	glVertex2f(-0.8, 0);
	glVertex2f(0, -0.8);
	glVertex2f(0.8, 0);
	glVertex2f(0, 0.8);
	glEnd();

	//Blue 
	int i;
	GLfloat x = 0.0f; GLfloat y = 0.0f; GLfloat radius = .4f;
	int triangleAmount = 20; //# of triangles used to draw circle				 
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 39, 118);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}

	glEnd();

	// All Code Render or Display
	glFlush();
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitWindowSize(520, 320);
glutCreateWindow("Lab-3 Task 3 Airport View");
//gluOrtho2D(-2, 2, -1, 1);
glutDisplayFunc(Assignment2);
glutMainLoop();
return 0;
}