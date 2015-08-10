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
#include"make_line.h"
//#include"type.h"

#define SIZE_POINT 5
#define DO_MAKE_LINE 0
#define DO_MAKE_LINE_STRIP 0
#define DO_MAKE_LINE_LOOP 1

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,400.0);
}


void make_line(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    POINT_int_2D point[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            point[i][j].x = 100 + j * 100;
            point[i][j].y = 300 - i * 100;
        }
    }

    glBegin(GL_LINES);   // GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP的区别是？  见书P41
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                glVertex2i(point[i][j].x,point[i][j].y);
                glVertex2i(point[i][j+1].x,point[i][j+1].y);
            }
        }
        for(int j=0;j<3;j++){
            for(int i=0;i<2;i++){
                glVertex2i(point[i][j].x,point[i][j].y);
                glVertex2i(point[i+1][j].x,point[i+1][j].y);
            }
        }
    glEnd();
    glFlush();
}

void make_line_strip(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    POINT_V_float_2D point[SIZE_POINT];
    point[0].vertex[0] = 400.0;
    point[0].vertex[1] = 200.0;
    point[1].vertex[0] = 0.0;
    point[1].vertex[1] = 0.0;
    point[2].vertex[0] = 200.0;
    point[2].vertex[1] = 400.0;
    point[3].vertex[0] = 400.0;
    point[3].vertex[1] = 0.0;
    point[4].vertex[0] = 0.0;
    point[4].vertex[1] = 200.0;

    glBegin(GL_LINE_STRIP);
    int i;
        for(i = 0 ; i < SIZE_POINT ; i++)
            glVertex2fv(point[i].vertex);
    glEnd();
    glFlush();
}

void make_line_loop(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    POINT_V_float_2D point[SIZE_POINT];
    point[0].vertex[0] = 400.0;
    point[0].vertex[1] = 200.0;
    point[1].vertex[0] = 0.0;
    point[1].vertex[1] = 0.0;
    point[2].vertex[0] = 200.0;
    point[2].vertex[1] = 400.0;
    point[3].vertex[0] = 400.0;
    point[3].vertex[1] = 0.0;
    point[4].vertex[0] = 0.0;
    point[4].vertex[1] = 200.0;

    glBegin(GL_LINE_LOOP);
    int i;
        for(i = 0 ; i < SIZE_POINT ; i++)
            glVertex2fv(point[i].vertex);
    glEnd();
    glFlush();
}

int test_make_line(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
#if DO_MAKE_LINE
    glutCreateWindow("make_line");
    init();
    glutDisplayFunc(make_line);
#endif
#if DO_MAKE_LINE_STRIP
    glutCreateWindow("make_line_strip");
    init();
    glutDisplayFunc(make_line_strip);
#endif
#if DO_MAKE_LINE_LOOP
    glutCreateWindow("make_line_loop");
    init();
    glutDisplayFunc(make_line_loop);
#endif
    glutMainLoop();
    return 0;
}
