/*
 * =====================================================================================
 *
 *       Filename:  make_bitmap.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月12日 15时27分41秒
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
#include "type.h"

void init(void);
BITMAP_2D create_bitmap(GLubyte *bitshape, GLint sum_mappoint);
void do_gl_bitmap_2D(void);
int test_make_bitmap(int argc, char ** argv);