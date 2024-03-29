#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

const float DEG2RAD = 3.14159 / 180;

void displayMeLab1(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Triangles
	/*glBegin(GL_TRIANGLES);
	glColor3f(255, 0, 0);
	glVertex2f(0.7, 0.0);
	glVertex2d(0.45, 0.45);
	glVertex2f(0.2, 0.0);
	glEnd();*/

	//Square
	/*glBegin(GL_QUADS);
	glColor3f(255, 0, 0);
	glVertex2f(-0.2, 0.0);
	glVertex2f(-0.2, 0.5);
	glVertex2f(-0.7, 0.5);
	glVertex2f(-0.7, 0.0);
	glEnd();*/


	//Square
	/*glBegin(GL_LINE_LOOP);
	float radius = 0.1;

	for (int i = 0; i<3; i++)
	{
		glColor3f(255, 0, 0);
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
	}

	glEnd();*/

	//Line
	/*glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	glVertex2f(-0.2, -0.5);
	glVertex2f(-0.7, -0.5);

	glVertex2f(-0.2, -0.5);
	glVertex2f(-0.7, -0.1);

	glVertex2f(-0.2, -0.1);
	glVertex2f(-0.7, -0.1);
	glEnd();*/


	//Point
	
	/*glBegin(GL_POINT);
	glColor3f(255, 0, 0);
	//glPointSize(0.9);
	glVertex2f(-0.2, -0.7);
	glEnd();*/

	glBegin(GL_POINTS);
	glColor3f(255, 0, 0);
	float pointXIncrease = 2.0 / 100;
	float pointX = -1;
	float pointY = 0.9;


	for (int i=0;i<100;i++)
	{
		if (i%2==0)
		{
			pointY = 0.7;
		}
		else
		{
			pointY = 0.9;
		}

		glVertex2f(pointX, pointY);
		pointX += pointXIncrease;
	}

	glEnd();



	//Polygon
	/*glBegin(GL_POLYGON);
	glColor3f(255, 0, 0);
	glVertex2f(0.7, -0.5);
	glVertex2d(0.45, -0.2);
	glVertex2f(0.2, -0.2);
	glVertex2f(0.1, -0.5);
	glVertex2f(0.4, -0.7);

	glEnd();*/



	// All Code Render or Display
	glFlush();
}


/*int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lab-1");
	glutDisplayFunc(displayMeLab1);
	glutMainLoop();
	return 0;
}*/