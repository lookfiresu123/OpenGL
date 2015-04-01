#include<GL/glut.h>
#include<stdio.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,200.0);
}

void lineSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINES);
        glVertex2i(0.0,0.0);
        glVertex2i(100,100);
    glEnd();
    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("test");

    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
}
