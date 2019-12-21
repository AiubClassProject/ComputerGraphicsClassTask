#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>
#include <GL/gl.h>
#include <iostream>
using namespace std;

# define PI  3.14159265358979323846
GLfloat win = 0.0f;


GLfloat FanSpeed= 0.0f;
void FanOn(int value)
{
	FanSpeed = -0.1;
}
void FanOff(int value)
{
	FanSpeed = 0.0;
}
void FanSpeedIncrease(int value)
{
	cout << "Calling Increase Fun";
	FanSpeed -= 0.1;
}

void FanSpeedDecrease(int value)
{
	FanSpeed += 0.1;
}


void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
		cout << "Call Fan Start";
		glutTimerFunc(100, FanOn, 0);
		break;
	case 'o':
		cout << "Call Fan Off";
		glutTimerFunc(100, FanOff, 0);
		break;
	}
	glutPostRedisplay();
}

void SpecialInputForFan(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		cout << "Call Fan Inc By Spa Fun";
		glutTimerFunc(100, FanSpeedIncrease, 0);
		break;
	case GLUT_KEY_DOWN:
		glutTimerFunc(100, FanSpeedDecrease, 0);
		break;
	}
	glutPostRedisplay();
}


void Fan()
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
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();

	int i_tree;

	//-------------Start Tree-1 circle-1 ----------
	GLfloat x = -0.55f; GLfloat y = -0.4f; GLfloat radius = .09f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	//================Start Windmill====================


	x = 0.5f;  y = -0.9f;  radius = .1f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();

	// Start Windmill-1
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.9);
	glVertex2f(0.48, -0.9);
	glVertex2f(0.48, -0.4);
	glVertex2f(0.5, -0.4);
	glEnd();

	glPushMatrix();
	glTranslatef(0.49f, -0.4f, 0);
	glRotatef(win, 0, 0, 1);
	glTranslatef(-0.49f, 0.4f, 0);
	//-------------Start Windmill-1 circle----------

	x = 0.49f;  y = -0.4f;  radius = .04f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	// Come Back real Position

	// Triangles-1
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.49, -0.38);
	glVertex2d(0.3, -0.42);
	glVertex2f(0.49, -0.43);
	glEnd();

	// Triangles-2
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.38);
	glVertex2d(0.65, -0.5);
	glVertex2f(0.5, -0.42);
	glEnd();

	// Triangles-3
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.38);
	glVertex2d(0.55, -0.2);
	glVertex2f(0.52, -0.38);
	glEnd();

	glLoadIdentity();
	glPopMatrix();
	win += FanSpeed;

	// End Windmill-1

	//-------------End Windmill-1 circle----------

	//================End Windmill====================




	// All Code Render or Display
	glFlush();
}

void idielAir()
{
	glutPostRedisplay();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(520, 320);
	glutCreateWindow("Fan");
	//gluOrtho2D(-2, 2, -1, 1);

	glutDisplayFunc(Fan);
	glutIdleFunc(idielAir);
	glutSpecialFunc(SpecialInputForFan);

	//Press Other Key
	glutKeyboardFunc(handleKeypress);

	glutMainLoop();
	return 0;
}



