/*
 * =====================================================================================
 *
 *       Filename:  make_bitmap.cpp
 *
 *    Description:	make a primitive of bitmap
 *
 *        Version:  1.0
 *        Created:  2015年08月12日 15时27分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include "make_bitmap.h"

#define DO_GL_BITMAP 1

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,400.0);
}

BITMAP_2D create_bitmap(GLubyte *bitshape, GLint sum_mappoint) {
	BITMAP_2D bitmap;
	bitmap.sum_mappoint = sum_mappoint;
	bitmap.bitshape = bitshape;
	return bitmap;
}

void do_gl_bitmap_2D(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	//glFlush();
    glColor3f(193.0, 255.0,  193.0);//set the current color
    glBegin(GL_POLYGON);
		GLint sum_mappoint = 20;
		GLubyte bitshape[20] = {
			0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00,
			0xff, 0x80, 0x7f, 0x00, 0x3e, 0x00, 0x1c, 0x00, 0x80, 0x00
		};
		BITMAP_2D bitmap = create_bitmap(bitshape, sum_mappoint);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//set pixel storage mode
		glRasterPos2i(30, 40);
		glBitmap(9, 10, 0.0, 0.0, 20.0, 15.0, bitmap.bitshape);
	glEnd();
	glFlush();
}

int test_make_bitmap(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,400);
#if DO_GL_BITMAP
    glutCreateWindow("make_gl_bitmap_2D");
    init();
    glutDisplayFunc(do_gl_bitmap_2D);
#endif
    glutMainLoop();
    return 0;
}


