#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

//const float DEG2RAD = 3.14159 / 180;

void displayMeLab2Task1(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	//Line
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	// X
	glVertex2f(1, 0);
	glVertex2f(-1, 0);

	// Y
	glVertex2f(0, 1);
	glVertex2f(0, -1);

	//Square
	glVertex2f(0.2, 0.2);
	glVertex2f(0.7, 0.2);

	glVertex2f(0.7, 0.2);
	glVertex2f(0.7, 0.5);

	glVertex2f(0.7, 0.5);
	glVertex2f(0.2, 0.5);

	glVertex2f(0.2, 0.5);
	glVertex2f(0.2, 0.2);

	// Triangles 1
	glVertex2f(-0.6, 0.2);
	glVertex2f(-0.2, 0.5);

	glVertex2f(-0.2, 0.5);
	glVertex2f(-0.7, 0.5);

	glVertex2f(-0.7, 0.5);
	glVertex2f(-0.6, 0.2);

	// Triangles 2
	glVertex2f(0.2, -0.7);
	glVertex2f(0.7, -0.7);

	glVertex2f(0.7, -0.7);
	glVertex2d(0.45, -0.2);

	glVertex2d(0.45, -0.2);
	glVertex2f(0.2, -0.7);

	//Polygon
	glVertex2f(-0.6, -0.7);
	glVertex2f(-0.3, -0.7);

	glVertex2f(-0.3, -0.7);
	glVertex2f(-0.2, -0.6);

	glVertex2f(-0.2, -0.6);
	glVertex2f(-0.2, -0.3);

	glVertex2f(-0.2, -0.3);
	glVertex2f(-0.3, -0.2);

	glVertex2f(-0.3, -0.2);
	glVertex2f(-0.6, -0.2);

	glVertex2f(-0.6, -0.2);
	glVertex2f(-0.7, -0.3);

	glVertex2f(-0.7, -0.3);
	glVertex2f(-0.7, -0.6);

	glVertex2f(-0.7, -0.6);
	glVertex2f(-0.6, -0.7);

	glEnd();

	// All Code Render or Display
	glFlush();
}


/*int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lab-2 Task 1");
	glutDisplayFunc(displayMeLab2Task1);
	glutMainLoop();
	return 0;
}*/