#include<GL/glut.h>
#include<stdio.h>

/*
initialization
 */
void init(void){
	glClearColor(1.0,1.0,1.0,0.0);  // set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200.0,0.0,200.0);
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

/*
make window color to gray
 */
void makewindowgray(void){
	glClearColor(0.5,0.5,0.5,0.0); // set display-window color to gray
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush(); // make "glClearColor" come true
}


/*
execute function
 */
int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(50,100);   /* set top-left display-window position */
	glutInitWindowSize(400,300);      /* set display-window width and leight */
	glutCreateWindow("");  /* create display window */

	init();
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(makewindowgray);
    glutMainLoop();
    errorCheck();
    return 0;
}