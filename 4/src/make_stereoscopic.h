/*
 * =====================================================================================
 *
 *       Filename:  make_stereoscopic.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月11日 19时57分39秒
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

POINT_V_float_3D *Initialize_point_float_3D(GLfloat x[], GLfloat y[], GLfloat z[], GLint sum_points);
STEREOSCOPIC_float Initialize_stereoscopic_float(GLint sum_points, POINT_V_float_3D *point_v);
void quad(POINT_V_float_3D *point_v);
void make_stereoscopic_float(STEREOSCOPIC_float *stereoscopic, POINT_V_float_3D *point_v);
void make_stereoscopic_float(STEREOSCOPIC_float *stereoscopic, POINT_V_float_3D *point_v);
void do_gl_stereoscopics_float(void);
int test_make_stereoscopics(int argc, char ** argv);