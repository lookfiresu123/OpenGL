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
#if 0
#include"make_line.h"
#include"make_polygon.h"
#include "make_triangles.h"
#include "make_quads.h"
#include "make_stereoscopic.h"
#include "make_bitmap.h"
#include "make_list.h"
#include "example_4_30.h"
#endif
#include "data_plot.h"



int main(int argc,char ** argv) {
#if 0
	test_make_line(argc,argv);
	test_make_polygon(argc,argv);
	test_make_triangles(argc,argv);
	test_make_quads(argc,argv);
	test_make_stereoscopics(argc,argv);
	test_make_bitmap(argc,argv);
	test_make_list(argc,argv);
	test_example_4_30(argc,argv);
#endif
	test_data_plot(argc,argv);
	return 0;
}