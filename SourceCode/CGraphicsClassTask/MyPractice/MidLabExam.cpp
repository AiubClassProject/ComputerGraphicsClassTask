#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

void MidLabExam(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Green Background
	glBegin(GL_QUADS);
	glColor3ub(25, 102, 51);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();

	// Right Room 
	glBegin(GL_QUADS);
	glColor3ub(176, 158, 129);
	glVertex2f(0.65, -0.7);
	glVertex2f(0.82, -0.6);
	glVertex2f(0.8, 0.1);
	glVertex2f(0.65, -0.1);
	glEnd();


	// Triangles
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.65, -0.1);
	glVertex2d(0.8, 0.1);
	glVertex2f(0.7, 0.5);
	glEnd();

	//Back Teen sheet
	glBegin(GL_QUADS);
	glColor3ub(102, 91, 86);
	glVertex2f(-0.2, 0.3);
	glVertex2f(0.65, -0.1);
	glVertex2f(0.7, 0.5);
	glVertex2f(-0.15, 0.9);
	glEnd();

	//Vantilator
	glBegin(GL_QUADS);
	glColor3ub(161, 156, 143);
	glVertex2f(0.0, 0.35);
	glVertex2f(0.2, 0.35);
	glVertex2f(0.2, 0.55);
	glVertex2f(0.0, 0.55);
	glEnd();

	//Vantilator Top
	glBegin(GL_QUADS);
	glColor3ub(161, 156, 143);
	glVertex2f(-0.03, 0.55);
	glVertex2f(0.23, 0.55);
	glVertex2f(0.23, 0.57);
	glVertex2f(-0.03, 0.57);
	glEnd();

	//Front Teen sheet
	glBegin(GL_QUADS);
	glColor3ub(176, 158, 129);
	glVertex2f(0.1, -0.1);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.45, 0.52);
	glVertex2f(-0.22, 0.31);
	glEnd();

	// Triangles
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(-0.4, 0.1);
	glVertex2d(0.1, -0.1);
	glVertex2f(-0.22, 0.31);
	glEnd();

	//Front Room
	glBegin(GL_QUADS);
	glColor3ub(176, 158, 129);
	glVertex2f(-0.4, -0.4);
	glVertex2f(0.1, -0.65);
	glVertex2f(0.1, -0.1);
	glVertex2f(-0.4, 0.1);
	glEnd();

	//Front Room Windo
	glBegin(GL_QUADS);
	glColor3ub(54, 50, 50);
	glVertex2f(-0.2, -0.2);
	glVertex2f(-0.1, -0.2);
	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.2, -0.1);
	glEnd();

	//Front Room Side Wail
	glBegin(GL_QUADS);
	glColor3ub(134, 118, 93);
	glVertex2f(0.1, -0.65);
	glVertex2f(0.4, -0.6);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.1, -0.1);
	glEnd();

	//Back Room Side Wail
	glBegin(GL_QUADS);
	glColor3ub(161, 156, 143);
	glVertex2f(0.4, -0.6);
	glVertex2f(0.65, -0.7);
	glVertex2f(0.65, -0.1);
	glVertex2f(0.4, 0.02);
	glEnd();

	//Line
	/*glBegin(GL_LINES);
	glColor3f(255, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(0.7, 0);*/

	//glEnd();


	// All Code Render or Display
	glFlush();
}


/*int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitWindowSize(800, 500);
glutCreateWindow("Mid Lab Exam");
//gluOrtho2D(-2, 2, -1, 1);
glutDisplayFunc(MidLabExam);
glutMainLoop();
return 0;
}*/