/*
 * =====================================================================================
 *
 *       Filename:  make_polygon.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月10日 21时19分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
#include"calculation.h"

void init(void);
POINT_V_float_2D *Initialize_point_float_2D(GLfloat x[], GLfloat y[], GLint sum_points);
void free_point_float_2D(POINT_V_float_2D *point_v);
POLYGON_float_2D Initialize_polygon_float_2D(GLint sum_points, POINT_V_float_2D *point);
void make_polygon_float_2D(POLYGON_float_2D polygon);
void do_gl_polygon_float_2D(void);
int test_make_polygon(int argc, char ** argv);
