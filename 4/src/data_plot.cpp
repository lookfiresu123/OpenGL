/*
 * =====================================================================================
 *
 *       Filename:  data_plot.cpp
 *
 *    Description:  create a data plot using line chart and bar chart
 *
 *        Version:  1.0
 *        Created:  2015年08月13日 15时28分25秒
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

#define DO_LINE_GRAPH 0
#define DO_BAR_CHART 1

GLsizei winWidth = 600;
GLsizei winHeight = 500;
GLint xRaster = 25;
GLint yRaster = 150;

GLubyte label[36] = {
    'J','a','n', 'F','e','b', 'M','a','r',
    'A','p','r', 'M','a','y', 'J','u','n',
    'J','u','l', 'A','u','g', 'S','e','p',
    'O','c','t', 'N','o','v', 'D','e','c'
};

GLint dataValue[12] = {
    420, 342, 324, 310, 262, 185,
    190, 196, 217, 240, 312, 438
};

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);//display window (background) color = white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void lineGraph(void) {
    GLint month, k;
    GLint x = 30;                   //initialize x position for chart

    glClear(GL_COLOR_BUFFER_BIT);   //clear display window
    glColor3f(0.0, 0.0, 1.0);       //set line color to blue

    glBegin(GL_LINE_STRIP);
        for(k = 0 ; k < 12 ; k++)
            glVertex2i(x + k * 50, dataValue[k]);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);       //set marker color to red
    for(k = 0 ; k < 12 ; k++) {
        glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);      //plot data as asterisk polymarkers
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
    }

    glColor3f(0.0, 0.0, 0.0);       //set text color to black
    xRaster = 20;
    for(month = 0 ; month < 12 ; month++) {
        glRasterPos2i(xRaster, yRaster);
        for(k = 3 * month ; k < 3 * month + 3 ; k++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
        xRaster += 50;
    }
    glFlush();
}

void barChart(void) {
    GLint month, k;

    glClear(GL_COLOR_BUFFER_BIT);   //clear display window

    glColor3f(1.0, 0.0, 0.0);       //set bar color to red
    for(k = 0 ; k < 12 ; k++)
        glRecti(20 + k * 50, 165, 40 + k * 50, dataValue[k]);

    glColor3f(0.0, 0.0, 0.0);       //set text color to black
    xRaster = 20;
    for(month = 0 ; month < 12 ; month++) {
        glRasterPos2i(xRaster, yRaster);
        for(k = 3 * month ; k < 3 * month + 3 ; k++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
        xRaster += 50;
    }
    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
    glClear(GL_COLOR_BUFFER_BIT);
}

void test_data_plot(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
#if DO_LINE_GRAPH
    glutCreateWindow("Line Chart Data Plot");
    init();
    glutDisplayFunc(lineGraph);
#endif
#if DO_BAR_CHART
    glutCreateWindow("bar Chart Data Plot");
    init();
    glutDisplayFunc(barChart);
#endif
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}
