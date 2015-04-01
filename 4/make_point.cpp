#include<GL/glut.h>
#include<stdio.h>

class POINT{
public:
    GLfloat x,y;
};

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,400.0);
}

void pointSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
   // int point1[] = {0,0};
   // int point2[] = {100,100};
   // int point3[] = {200,200};
   // int point4[] = {300,300};
   // int point5[] = {400,400};
    POINT point[5];
    for(int i=0;i<5;i++){
        point[i].x = i * 100;
        point[i].y = i * 100;
    }
    glBegin(GL_POINTS);
       /*
        glVertex2i(0.0,0.0);
        glVertex2i(100,100);
        glVertex2i(200,200);
        glVertex2i(300,300);
        glVertex2i(400,400);
        */
        /*
        glVertex2iv(point1);
        glVertex2iv(point2);
        glVertex2iv(point3);
        glVertex2iv(point4);
        glVertex2iv(point5);
        */
        for(int i=0;i<5;i++){
            glVertex2f(point[i].x,point[i].y);
        }
    glEnd();
    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("make_point");

    init();
    glutDisplayFunc(pointSegment);
    glutMainLoop();
}
