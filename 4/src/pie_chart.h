/*
 * =====================================================================================
 *
 *       Filename:  pie_chart.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月15日 19时21分30秒
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
#include <math.h>
#include <iostream>

void init(void);
void pieChart(void);
void displayFcn(void);
void winReshapeFcn(GLint newWidth, GLint newHeight);
void test_piechart(int argc, char **argv);