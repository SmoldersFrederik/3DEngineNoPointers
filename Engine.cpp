/*
 * Engine.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Vector.h"
#include "Matrix.h"
#include "Plane.h"
#include "Camera.h"
#include "PlaneWithBoundaries.h"
#include "Line.h"
#include "Cube.h"

#include <iostream>
#include <string>
#include <GL/Gl.h>
#include <GL/Glu.h>
#include <GL/glut.h>

using namespace std;


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);				// set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);					// set the drawing color to black
	glPointSize(1.0);								// set the point size to 1 by 1 pixel
	glMatrixMode(GL_PROJECTION);					// set up appropriate matrices- to be explained
	glLoadIdentity();								// to be explained
	//gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	gluOrtho2D(0.0, 1000.0, 0.0, 800.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);					// clear the screen
	glBegin(GL_POINTS);


	Camera camera;
	camera.rayTrace();

	glEnd();
	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);								// initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);					// set the display mode
	//glutInitWindowSize(640,480);						// set the window size
	glutInitWindowSize(1000,800);						// set the window size
	//glutInitWindowPosition(400, 300);					// set the window position on the screen
	glutInitWindowPosition(0, 0);					// set the window position on the screen
	glutCreateWindow("3DEngine");						// open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);							// register the redraw function
	myInit();
	glutMainLoop();										// go into a perpetual loop
	return 0;
}
