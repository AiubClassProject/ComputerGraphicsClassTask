#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>
#include <time.h>
#include <sys/timeb.h>
#include <gl/gl.h>
#include <iostream>

using namespace std;

# define M_PI  3.14159265358979323846

const float clockR = 80.0f,
clockVol = 100.0f,

angle1min = M_PI / 30.0f,

minStart = 0.9f,
minEnd = 1.0f,

stepStart = 0.8f,
stepEnd = 1.0f;

float angleHour = 0,
angleMin = 0,
angleSec = 0;



void newLine(float rStart, float rEnd, float angle) {

	float c = cos(angle), s = sin(angle);

	glVertex2f(clockR*rStart*c, clockR*rStart*s);
	glVertex2f(clockR*rEnd*c, clockR*rEnd*s);

}

struct Point {
	GLint x;
	GLint y;
};

void draw_circle(Point pC, GLfloat radius) {
	GLfloat step = 1 / radius;
	GLfloat x, y;

	for (GLfloat theta = 0; theta <= 360; theta += step) {
		x = pC.x + (radius * cos(theta));

		y = pC.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
}

Point pC = { 0, 0 };
GLint radius = 85;

void RenderScene(void) {

	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);

	int i;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(2.0f);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	glBegin(GL_LINES);

	draw_circle(pC, radius);

	for (i = 0; i<60; i++) {
		if (i % 5) { // normal minute
			if (i % 5 == 1)
				glColor3f(0.0f, 0.0f, 0.0f);
			newLine(minStart, minEnd, i*angle1min);
		}
		else {
			glColor3f(1.0f, 0.0f, 0.0f);
			newLine(stepStart, stepEnd, i*angle1min);
		}
	}
	glEnd();

	glLineWidth(3.0f);
	glBegin(GL_LINES);
	newLine(0.0f, 0.5f, -angleHour + M_PI / 2);
	newLine(0.0f, 0.8f, -angleMin + M_PI / 2);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	newLine(0.0f, 0.8f, -angleSec + M_PI / 2);
	glEnd();

	glutSwapBuffers();
}

void SetupRC(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(GLsizei w, GLsizei h) {
	GLfloat aspectRatio;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-clockVol, clockVol, -clockVol / aspectRatio, clockVol / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-clockVol * aspectRatio, clockVol * aspectRatio, -clockVol, clockVol, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void TimerFunction(int value) {
	struct timeb tb;
	time_t tim = time(0);
	struct tm* t;
	t = localtime(&tim);
	ftime(&tb);

	angleSec = (float)(t->tm_sec + (float)tb.millitm / 1000.0f) / 30.0f * M_PI;
	angleMin = (float)(t->tm_min) / 30.0f * M_PI + angleSec / 60.0f;
	angleHour = (float)(t->tm_hour > 12 ? t->tm_hour - 12 : t->tm_hour) / 6.0f * M_PI +
		angleMin / 12.0f;

	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}


/*int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(420, 420);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Analog Animated Clock");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);

	SetupRC();

	glutMainLoop();

	return 0;
}*/

