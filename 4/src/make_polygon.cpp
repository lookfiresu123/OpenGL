/*
 * =====================================================================================
 *
 *       Filename:  make_polygon.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月10日 21时16分00秒
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
#include "make_polygon.h"

#define DO_GL_POLYGON 1
#define SIZE_POINT 6

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,400.0);
}

POINT_V_float_2D *Initialize_point_float_2D(GLfloat x[], GLfloat y[], GLint sum_points) {
	POINT_V_float_2D *point_v = (POINT_V_float_2D *)malloc(sum_points * sizeof(POINT_V_float_2D));
	int i;
	for(i = 0 ; i < sum_points ; i++) {
		point_v[i].vertex[0] = x[i];
		point_v[i].vertex[1] = y[i];
	}
	return point_v;
}

void free_point_float_2D(POINT_V_float_2D *point_v) {
	free(point_v);
}

POLYGON_float_2D Initialize_polygon_float_2D(GLint sum_points, POINT_V_float_2D *point_v) {
	POLYGON_float_2D polygon;
	polygon.sum_points = sum_points;
	polygon.point_v = point_v;
	return polygon;
}

void make_polygon_float_2D(POLYGON_float_2D polygon) {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    	int i;
    	for(i = 0 ; i < polygon.sum_points ; i++) {
    		glVertex2fv(polygon.point_v[i].vertex);
    	}
    glEnd();
    glFlush();
}

void do_gl_polygon_float_2D(void) {
	/* Initialize_point_float_2D */
	GLfloat x[] = { 0.0, 100.0, 300.0, 400.0, 300.0, 100.0 };
	GLfloat y[] = { 200.0, 400.0, 400.0, 200.0, 0.0, 0.0 };
	GLint sum_points = SIZE_POINT;
	POINT_V_float_2D *point_v = Initialize_point_float_2D(x, y, sum_points);
	/* Initialize_polygon_float_2D */
	POLYGON_float_2D polygon = Initialize_polygon_float_2D(sum_points, point_v);
	/* make_polygon_float_2D */
	make_polygon_float_2D(polygon);
}

int test_make_polygon(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
#if DO_GL_POLYGON
    glutCreateWindow("make_polygon_float_2D");
    init();
    glutDisplayFunc(do_gl_polygon_float_2D);
#endif    
    glutMainLoop();
    return 0;
}
