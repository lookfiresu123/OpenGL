#include<GL/glut.h>

class POINT{
public:
    GLfloat pos[3];
};

class LINE{
public:
    GLint line[2];
};



void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);
   // gluOrtho2D(0.0,500.0,0.0,500.0);
}

void lifangti(){
    glBegin(GL_LINES);
    POINT point[8];
    LINE line[12];
    float tempx,tempy,tempz;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                tempx = 0.5;
                tempy = 0.5;
                tempz = 0.5;
                point[i*4+j*2+k].pos[0] = i*1.0-tempx;
                point[i*4+j*2+k].pos[1] = j*1.0-tempy;
                point[i*4+j*2+k].pos[2] = k*1.0-tempz;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(k<1){
                    glVertex3fv(point[i*4+j*2+k].pos);
                    glVertex3fv(point[i*4+j*2+(k+1)].pos);
                }
                if(j<1){
                    glVertex3fv(point[i*4+j*2+k].pos);
                    glVertex3fv(point[i*4+(j+1)*2+k].pos);
                }
                if(i<1){
                    glVertex3fv(point[i*4+j*2+k].pos);
                    glVertex3fv(point[(i+1)*4+j*2+k].pos);
                }
                if(k>=1){
                    glVertex3fv(point[i*4+j*2+k].pos);
                    glVertex3fv(point[i*4+j*2+(k-1)].pos);
                }
                if(j>=1){
                    glVertex3fv(point[i*4+j*2+k].pos);
                    glVertex3fv(point[i*4+(j-1)*2+k].pos);
                }
                if(i>=1){
                    glVertex3fv(point[i*4+j*2+k].pos);
                    glVertex3fv(point[(i-1)*4+j*2+k].pos);
                }
            }
        }
    }
    glEnd();
}

static float rotate = 0;
static int times = 0;

void renderScene(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    glPushMatrix();
    times++;
    if(times >100){
        times =0;
    }
    if(times % 100 == 0){
        rotate += 0.3;
    }
    glRotatef(rotate, 0, 1, 0);
    glRotatef(rotate, 1, 0, 0);
    glColor3f(1,0,0);
    lifangti();
    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("difangti");
    
    init();
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutMainLoop();
    return 0;
}
