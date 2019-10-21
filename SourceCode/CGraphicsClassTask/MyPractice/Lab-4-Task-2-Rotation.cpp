#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

//const float DEG2RAD = 3.14159 / 180;
GLfloat ir = 0.0f;

void displayRotation(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glRotatef(ir, 0, 0, 1);
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	

	/*// X
	glVertex2f(0.4, -0.4);
	glVertex2f(0.8, -0.4);*/
	// X
	glVertex2f(0, 0);
	glVertex2f(0.7, 0);



	glEnd();
	glPopMatrix();
	ir += 0.1;

	// All Code Render or Display
	glFlush();
}

void idiel()
{
	glutPostRedisplay();
}


/*int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lab-2 Task 1");
	glutDisplayFunc(displayRotation);
	glutIdleFunc(idiel);
	glutMainLoop();
	return 0;
}*/