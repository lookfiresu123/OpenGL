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
//#include"make_line.h"
//#include"make_polygon.h"
#include "make_triangles.h"

int main(int argc,char ** argv) {
	//test_make_line(argc,argv);
	//test_make_polygon(argc,argv);
	test_make_triangles(argc,argv);
	return 0;
}