/*
 * =====================================================================================
 *
 *       Filename:  make_triangles.cpp
 *
 *    Description:  make a primitive of triangle
 *
 *        Version:  1.0
 *        Created:  2015年08月11日 16时31分43秒
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
#include "make_triangles.h"

#define DO_GL_TRIANGLES 1
#define SIZE_POINT 6

void make_triangles_float_2D(POLYGON_float_2D polygon) {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    	int i;
    	for(i = 0 ; i < polygon.sum_points ; i++) {
    		glVertex2fv(polygon.point_v[i].vertex);
    	}
    glEnd();
    glFlush();
}

void do_gl_triangles_float_2D(void) {
	/* Initialize_point_float_2D */
	GLfloat x[] = { 0.0, 100.0, 300.0, 400.0, 300.0, 100.0 };
	GLfloat y[] = { 200.0, 400.0, 400.0, 200.0, 0.0, 0.0 };
	GLint sum_points = SIZE_POINT;
	POINT_V_float_2D *point_v = Initialize_point_float_2D(x, y, sum_points);
	/* Initialize_polygon_float_2D */
	POLYGON_float_2D polygon = Initialize_polygon_float_2D(sum_points, point_v);
	/* make_polygon_float_2D */
	make_triangles_float_2D(polygon);
}

int test_make_triangles(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
#if DO_GL_TRIANGLES
    glutCreateWindow("make_triangles_float_2D");
    init();
    glutDisplayFunc(do_gl_triangles_float_2D);
#endif
    glutMainLoop();
    return 0;
}