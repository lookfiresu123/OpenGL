/*
 * =====================================================================================
 *
 *       Filename:  make_stereoscopic.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月11日 19时57分31秒
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
#include "make_stereoscopic.h"

#define DO_GL_STEREOSCOPIC 1
#define DO_GL_CUBE 1
#define SIZE_POINT 8

POINT_V_float_3D *Initialize_point_float_3D(GLfloat x[], GLfloat y[], GLfloat z[], GLint sum_points) {
	POINT_V_float_3D *point_v = (POINT_V_float_3D *)malloc(sum_points * sizeof(POINT_V_float_3D));
	int i;
	for(i = 0 ; i < sum_points ; i++) {
		point_v[i].vertex[0] = x[i];
		point_v[i].vertex[1] = y[i];
		point_v[i].vertex[2] = z[i];
	}
	return point_v;
}

STEREOSCOPIC_float Initialize_stereoscopic_float(GLint sum_points, POINT_V_float_3D *point_v) {
	STEREOSCOPIC_float stereoscopic;
	stereoscopic.sum_points = sum_points;
	stereoscopic.point_v = point_v;
	return stereoscopic;
}

void quad(POINT_V_float_3D *point_v) {
	glBegin(GL_QUADS);
		glVertex3fv(point_v[0].vertex);
		glVertex3fv(point_v[1].vertex);
		glVertex3fv(point_v[2].vertex);
		glVertex3fv(point_v[3].vertex);
	glEnd();
}

void make_stereoscopics_float(STEREOSCOPIC_float *stereoscopic, POINT_V_float_3D *point_v) {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    /*
     * 用图元常量GL_CUBE生成两个不相连的四边形
     */
#if DO_GL_CUBE
    /* build a primitive of cube */
    stereoscopic->sum_edges = 12;
	stereoscopic->sum_surfaces = 6;

    POINT_V_float_3D point_v_temp[6][4] = {
    	{ point_v[0], point_v[1], point_v[2], point_v[3] },
    	{ point_v[1], point_v[2], point_v[6], point_v[5] },
    	{ point_v[3], point_v[2], point_v[6], point_v[7] },
    	{ point_v[4], point_v[5], point_v[6], point_v[7] },
    	{ point_v[0], point_v[3], point_v[7], point_v[4] },
    	{ point_v[0], point_v[1], point_v[5], point_v[4] }
    };
    stereoscopic->surface = (SURFACE_float_3D *)malloc(6 * sizeof(SURFACE_float_3D));
    stereoscopic->surface[0].point_v = &point_v_temp[0][0];
    stereoscopic->surface[1].point_v = &point_v_temp[1][0];
    stereoscopic->surface[2].point_v = &point_v_temp[2][0];
    stereoscopic->surface[3].point_v = &point_v_temp[3][0];
    stereoscopic->surface[4].point_v = &point_v_temp[4][0];
    stereoscopic->surface[5].point_v = &point_v_temp[5][0];

    quad(stereoscopic->surface[0].point_v);
    quad(stereoscopic->surface[1].point_v);
    quad(stereoscopic->surface[2].point_v);
    quad(stereoscopic->surface[3].point_v);
    quad(stereoscopic->surface[4].point_v);
    quad(stereoscopic->surface[5].point_v);
    
#endif
    glFlush();
}

void do_gl_stereoscopics_float(void) {
	/* Initialize_point_float_3D */
	GLfloat x[] = { 300.0, 300.0, 100.0, 100.0, 300.0, 300.0, 100.0, 100.0 };
	GLfloat y[] = { 100.0, 300.0, 300.0, 100.0, 100.0, 300.0, 300.0, 100.0 };
	GLfloat z[] = { 100.0, 100.0, 100.0, 100.0, 300.0, 300.0, 300.0, 300.0 };
	GLint sum_points = SIZE_POINT;
	POINT_V_float_3D *point_v = Initialize_point_float_3D(x, y, z, sum_points);
	/* Initialize_STEREOSCOPIC_float */
	STEREOSCOPIC_float stereoscopic = Initialize_stereoscopic_float(sum_points, point_v);
	/* make_stereoscopics_float */
	make_stereoscopics_float(&stereoscopic, point_v);
}

int test_make_stereoscopics(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
#if DO_GL_STEREOSCOPIC
    glutCreateWindow("make_stereoscopic_float");
    init();
    glutDisplayFunc(do_gl_stereoscopics_float);
#endif
    glutMainLoop();
    return 0;
}
