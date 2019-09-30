#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

//const float DEG2RAD = 3.14159 / 180;

void displayMeLab2Task2(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	//Square
	glBegin(GL_QUADS);
	glColor3ub(255, 3, 11);
	glVertex2f(-0.8, 0.8);
	glVertex2f(0.9, 0.8);
	glVertex2f(0.9, 0.9);
	glVertex2f(-0.8, 0.9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 127, 0);
	glVertex2f(-0.8, 0.7);
	glVertex2f(0.9, 0.7);
	glVertex2f(0.9, 0.8);
	glVertex2f(-0.8, 0.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(254, 255, 4);
	glVertex2f(-0.8, 0.6);
	glVertex2f(0.9, 0.6);
	glVertex2f(0.9, 0.7);
	glVertex2f(-0.8, 0.7);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(6, 131, 5);
	glVertex2f(-0.8, 0.5);
	glVertex2f(0.9, 0.5);
	glVertex2f(0.9, 0.6);
	glVertex2f(-0.8, 0.6);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(10, 3, 255);
	glVertex2f(-0.8, 0.4);
	glVertex2f(0.9, 0.4);
	glVertex2f(0.9, 0.5);
	glVertex2f(-0.8, 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(127, 1, 224);
	glVertex2f(-0.8, 0.3);
	glVertex2f(0.9, 0.3);
	glVertex2f(0.9, 0.4);
	glVertex2f(-0.8, 0.4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(68, 162, 67);
	glVertex2f(-0.8, -0.9);
	glVertex2f(-0.7, -0.9);
	glVertex2f(-0.7, 0.3);
	glVertex2f(-0.8, 0.3);
	glEnd();
	char string[] = { 'M','h' };
	

	// All Code Render or Display
	glFlush();
}


/*
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lab-2 Task 2");
	glutDisplayFunc(displayMeLab2Task2);
	glutMainLoop();
	return 0;
}*/