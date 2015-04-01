#include<GL/glut.h>
#include<stdio.h>

/*
initialization
 */
void init(void){
	glClearColor(1.0,1.0,1.0,0.0);  // set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,150.0,0.0,250.0);
}

/*
deal with error
 */
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

void makeline(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0); //set the color of line black
    glBegin(GL_LINES);
        glVertex2i(0.0,0.0);
        glVertex2i(150,250);
    glEnd();
    glFlush();
}

/*
execute function
 */
int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(50,100);   /* set top-left display-window position */
	glutInitWindowSize(150,250);      /* set display-window width and leight */
	glutCreateWindow("");  /* create display window */

	init();
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(makeline);
  glutMainLoop();
  errorCheck();
  return 0;
}
