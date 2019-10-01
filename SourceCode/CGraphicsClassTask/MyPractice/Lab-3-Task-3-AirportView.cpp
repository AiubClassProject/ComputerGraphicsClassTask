#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>


# define PI  3.14159265358979323846
void AirportView(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Green Ground
	glBegin(GL_QUADS);
	glColor3ub(100, 116, 72);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0);
	glVertex2f(-1, 0);
	glEnd();

	// Road
	glBegin(GL_QUADS);
	glColor3ub(213, 214, 215);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 0.3);
	glVertex2f(-1,0.3);
	glEnd();

	// Plain
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(-0.5, 0.2);
	glVertex2f(0.7, 0.5);
	glVertex2f(0.68, 0.8);
	glVertex2f(-0.52, 0.5);
	glEnd();

	// Triangles
	/*glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.7, 0.5);
	glVertex2d(0.9, 0.58);
	glVertex2f(0.68, 0.7);
	glEnd();*/

	//sun
	int i;

	GLfloat x = -0.8f; GLfloat y = 0.8f; GLfloat radius = .13f;
	int triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
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


/*int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(520, 320);
	glutCreateWindow("Lab-3 Task 3 Airport View");
	//gluOrtho2D(-2, 2, -1, 1);
	glutDisplayFunc(AirportView);
	glutMainLoop();
	return 0;
}*/