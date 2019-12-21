#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

//const float DEG2RAD = 3.14159 / 180;

void displayTranslate(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);



	// Triangles 1
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);

	glVertex2f(0.5, 0.0);
	glVertex2d(0.25, 0.5);

	glVertex2d(0.25, 0.5);
	glVertex2f(0.0, 0.0);
	glEnd();

	// Object Position Change 
	glTranslatef(0.2, 0.1, 0);

	
	//Line
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);
	
	// Triangles 2
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);

	glVertex2f(0.5, 0.0);
	glVertex2d(0.25, 0.5);

	glVertex2d(0.25, 0.5);
	glVertex2f(0.0, 0.0);
	glEnd();

	// Come Back real Position
	glLoadIdentity();

	//Original Line
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	// X
	glVertex2f(0, 0);
	glVertex2f(-0.3, 0.3);
	glEnd();

	// Big Line 
	glTranslatef(0.1, 0.0, 0);
	glScalef(2, 2, 0);
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	// X
	glVertex2f(0, 0);
	glVertex2f(-0.3, 0.3);
	glEnd();


	// Small Line 
	// Come Back real Position
	glLoadIdentity();
	glScalef(0.5, 0.5, 0);
	glTranslatef(-0.1, 0, 0);
	
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	// X
	glVertex2f(0, 0);
	glVertex2f(-0.3, 0.3);

	glEnd();


	// All Code Render or Display
	glFlush();
}


/*int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lab-2 Task 1");
	glutDisplayFunc(displayTranslate);
	glutIdleFunc(idiel);
	glutMainLoop();
	return 0;
}*/