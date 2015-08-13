/*
 * =====================================================================================
 *
 *       Filename:  data_plot.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月13日 15时29分20秒
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

void init(void);
void lineGraph(void);
void barChart(void);
void winReshapeFcn(GLint newWidth, GLint newHeight);
void test_data_plot(int argc, char **argv);