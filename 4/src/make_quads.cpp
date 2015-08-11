/*
 * =====================================================================================
 *
 *       Filename:  make_quads.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月11日 18时53分35秒
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
#include "make_quads.h"

#define DO_GL_QUADS 1
#define DO_GL_QUAD_STRIP 0
#define SIZE_POINT 8
#define DO_GL_QUADS_ANYTHING 1

void make_quads_float_2D(POLYGON_float_2D polygon) {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    /*
     * 用图元常量GL_QUADS生成两个不相连的四边形
     */
#if DO_GL_QUADS
    glBegin(GL_QUADS);
    	int i;
    	for(i = 0 ; i < polygon.sum_points ; i++) {
    		glVertex2fv(polygon.point_v[i].vertex);
    	}
    glEnd();
#endif
    /*
     * 用图元常量GL_QUAD_STRIP生成三个相连的四边形
     * 其中若点序列为：p1, p2, p3, p4, p5, p6, p7, p8
     * 则生成的四边形分别为：{p1, p2, p3, p4}, {p3, p4, p5, p6}, {p5, p6, p7, p8}
     */
#if DO_GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);
        int i;
        for(i = 0 ; i < polygon.sum_points ; i++) {
            glVertex2fv(polygon.point_v[i].vertex);
        }
    glEnd();
#endif
    glFlush();
}

void do_gl_quads_float_2D(void) {
	/* Initialize_point_float_2D */
	GLfloat x[] = { 50.0, 50.0, 150.0, 150.0, 200.0, 200.0, 300.0, 300.0 };
	GLfloat y[] = { 300.0, 100.0, 100.0, 300.0, 300.0, 100.0, 100.0, 300.0 };
	GLint sum_points = SIZE_POINT;
	POINT_V_float_2D *point_v = Initialize_point_float_2D(x, y, sum_points);
	/* Initialize_polygon_float_2D */
	POLYGON_float_2D polygon = Initialize_polygon_float_2D(sum_points, point_v);
	/* make_polygon_float_2D */
	make_quads_float_2D(polygon);
}

int test_make_quads(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
#if DO_GL_QUADS_ANYTHING
    glutCreateWindow("make_quads_float_2D");
    init();
    glutDisplayFunc(do_gl_quads_float_2D);
#endif
    glutMainLoop();
    return 0;
}
