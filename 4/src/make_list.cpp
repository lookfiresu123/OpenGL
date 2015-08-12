/*
 * =====================================================================================
 *
 *       Filename:  make_list.cpp
 *
 *    Description:	make a primitive of list
 *
 *        Version:  1.0
 *        Created:  2015年08月12日 17时12分00秒
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
#include <iostream>
#include <math.h>
#include "make_list.h"

#define DO_MAKE_LIST 1

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);//set the color of background white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,400.0);
}

void do_gl_list(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);//set the current color black
	const double TWO_PI = 6.2831853;
	LIST list;
	GLdouble theta;
	GLint x, y, k;
	/* set up a display list for a regular hexagon
	 * vertices for the hexagon are six equally spaced
	 * points around the circumference of a circles
	 */
	list.reghex = glGenLists(1);//get an ID for the display list
	glNewList(list.reghex, GL_COMPILE);
		glBegin(GL_POLYGON);
			for(k = 0 ; k < 6 ; k++) {
				theta = TWO_PI * k / 6.0;
				x = 200 + 150 * cos(theta);
				y = 200 + 150 * sin(theta);
				glVertex2i(x, y);
			}
		glEnd();
	glEndList();
	glCallList(list.reghex);
	glFlush();

}

int test_make_list(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
#if DO_MAKE_LIST
    glutCreateWindow("make_list");
    init();
    glutDisplayFunc(do_gl_list);
#endif
    glutMainLoop();
    return 0;
}



