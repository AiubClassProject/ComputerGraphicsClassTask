#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>
#include <GL/gl.h>



namespace AnimationControl
	{

GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.1f;

void updateAnimationControl(int value) {

	if (position < -1.0)
		position = 1.0f;

	position -= speed;


	glutPostRedisplay();


	glutTimerFunc(100, updateAnimationControl, 0);
}



void update2(int value) {
if(position > 1.0)
position = -1.0f;

position += speed;


glutPostRedisplay();


glutTimerFunc(100, update2, 0);
}

void handleMouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON)
	{
		speed += 0.1f;
	}
	if(button==GLUT_RIGHT_BUTTON)
	{
		speed -= 0.1f;
	}
	glutPostRedisplay();
}

void handleKeypress(unsigned char key,int x, int y)
{
	switch (key)
	{
	case 'a':
		glutTimerFunc(100, update2, 0);
		break;
	case 's':
		speed = 0.0f;
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	}
	glutPostRedisplay();
}



void initAnimationControl() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void SpecialInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		glutTimerFunc(100, updateAnimationControl, 0);
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	}
	glutPostRedisplay();
}


void displayAnimationControl() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();



	glPushMatrix();
	glTranslatef(0.0f, position, 0.0f);
	//glTranslatef(0.0f,position, 0.0f);
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
	glutCreateWindow("Basic Animation");
	glutDisplayFunc(displayAnimationControl);
	initAnimationControl();
	// Press Special Key
	glutSpecialFunc(SpecialInput);
	//Press Other Key
	glutKeyboardFunc(handleKeypress);
	//Press Mouse Button
	glutMouseFunc(handleMouse);
	glutMainLoop();
	return 0;
}*/
	}

