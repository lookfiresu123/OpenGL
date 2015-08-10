/*
 * build : g++ -g -Wall make_line.cpp -o test -lGL -lglut -lGLU
 *
 * author : created by lookfiresu123 @ 2015/8/9
 *
 * email : lookfiresu123@gmail.com
 */

#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
#include"calculation.h"

void init(void);
void make_line(void);
void make_line_strip(void);
void make_line_loop(void);
int test_make_line(int argc,char ** argv);