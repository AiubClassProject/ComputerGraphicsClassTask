#include "stdafx.h"
#include <GL/glut.h>
#include<cstdio>
#include <GL/gl.h>
#include <cmath>

# define PI  3.14159265358979323846
GLfloat XPosition = 0.0f;
GLfloat YPosition = 0.0f;
GLfloat XSpeed = 0.1f;
GLfloat YSpeed = 0.05f;

void update(int value) {
	if (XPosition >1.0)
	{
		XPosition = -1.0f;
		YPosition = 0;
	}
		

	XPosition += XSpeed;
	YPosition += YSpeed;


	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}


void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void MovingAnimationDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();



	glPushMatrix();
	glTranslatef(XPosition, YPosition, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.2f, 0.2f);
	glVertex2f(-0.2f, 0.2f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.2f, 0.2f);
	glEnd();

	glPopMatrix();





	glFlush();
}



/*int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Translation Animation");
	glutDisplayFunc(MovingAnimationDisplay);
	init();
	glutTimerFunc(100, update, 0);
	glutMainLoop();
	return 0;
}*/
