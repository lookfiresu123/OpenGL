/*
 * =====================================================================================
 *
 *       Filename:  pie_chart.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月15日 19时21分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <iostream>

const GLdouble twoPi = 6.283186;
int num = 1000;

class scrPt {
public:
	GLint x, y;
};

/* initial display window size */
GLsizei winWidth = 400;
GLsizei winHeight = 300;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void pieChart(void) {
	scrPt circCtr, piePt;
	GLint radius = winWidth / 4;	//circle radius
	GLdouble sliceAngle, previousSliceAngle = 0.0;

	GLint k, nSlices = 12;
	GLfloat dataValue[12] = {
		10.0, 7.0, 13.0, 5.0, 13.0, 14.0,
		3.0, 16.0, 5.0, 3.0, 17.0, 8.0
	};
	GLfloat dataSum = 0.0;

	circCtr.x = winWidth / 2;  //circle center positon
	circCtr.y = winHeight / 2;
	//circleMidpoint(circCtr, radius);	//call a midpoint circle plot routine
	glBegin(GL_LINE_LOOP);
    for(k=0; k<num; k++)
         glVertex2f(circCtr.x + radius * cos(twoPi / num * k), circCtr.y + radius * sin(twoPi / num * k));
     glEnd();

	for(k = 0 ; k < nSlices; k++) {
		dataSum += dataValue[k];
	}

	for(k = 0 ; k < nSlices ; k++) {
		sliceAngle = twoPi * dataValue[k] / dataSum + previousSliceAngle;
		piePt.x = circCtr.x + radius * cos(sliceAngle);
		piePt.y = circCtr.y + radius * sin(sliceAngle);
		glBegin(GL_LINES);
			glVertex2i(circCtr.x, circCtr.y);	//draw the center point
			glVertex2i(piePt.x, piePt.y);		//draw the destination point
		glEnd();
		previousSliceAngle = sliceAngle;
	}
}

void displayFcn(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	pieChart();
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
	/* reset display-window size parameters */
	winWidth = newWidth;
	winHeight = newHeight;
}

void test_piechart(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("pie chart");

	init();
	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFcn);
	
	glutMainLoop();
}


