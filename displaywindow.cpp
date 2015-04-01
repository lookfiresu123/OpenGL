#include<GL/glut.h>
#include<stdio.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);   /* set display-window color to white */
    glMatrixMode(GL_PROJECTION);     /* set projection parameters */
    gluOrtho2D(0.0,200.0,0.0,200.0);
}

void lineSegment(void){
    glClear(GL_COLOR_BUFFER_BIT);    /* clear display window to make what glClearColor() set come true*/
    glColor3f(139.0,0.0,255.0);          /* set line segment color to green */
    glBegin(GL_LINES);
    /*
    *      soecify line-segment geometry, the first parameter is x and the second parameter is y 
    *            --> < x , y > 
    *               
    */
       glVertex2i(20,180);
       glVertex2i(20,20);

       glVertex2i(20,180);
       glVertex2i(180,180);

       glVertex2i(180,180);
       glVertex2i(180,20);

       glVertex2i(180,20);
       glVertex2i(20,20);
    glEnd();
    glFlush();                       /* process all OpenGL routines as quickly as possable */
}

/*
 * deal with error
 *  */
GLenum errorCheck(){
    GLenum code;
    const GLubyte *string;
    code=glGetError();
    if (code!=GL_NO_ERROR)
    {
       string=gluErrorString(code);
       fprintf(stderr, "OpenGL error: %s\n", string);  
    }
}

int main(int argc, char ** argv){
    glutInit(&argc,argv);             /* initialize glut */
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    /* set display mode */
    //init(); 
    glutInitWindowPosition(50,100);   /* set top-left display-window position */
    glutInitWindowSize(400,300);      /* set display-window width and leight */
    glutCreateWindow("An Example OpenGL Program");    /* create display window */
        
    init();                           /* execute initialization procedure */
    glutDisplayFunc(lineSegment);     /* send graphics to display window */
    glutMainLoop();                   /* display everything and wait */
    errorCheck();
    return 0;
}
