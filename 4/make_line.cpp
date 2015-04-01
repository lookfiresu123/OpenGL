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


void make_line(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    POINT point[3][3];
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

int main(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
    glutCreateWindow("make_line");

    init();
    glutDisplayFunc(make_line);
    glutMainLoop();
    return 0;
}
