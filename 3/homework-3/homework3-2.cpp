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


int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    
    glutInitWindowPosition(75,50);
	glutInitWindowSize(200,150);
	init();

	glutCreateWindow("");
	glutMainLoop();
	return 0;
}