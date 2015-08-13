/*
 * =====================================================================================
 *
 *       Filename:  example_4_30.cpp
 *
 *    Description:  the example 4.30 in page 66, the polygon will be changed to adapt to
 *                  the display-window size which we have changed, so that polygon_area / window_area
 *                  will be changed.
 *
 *        Version:  1.0
 *        Created:  2015年08月12日 20时13分38秒
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
#include <math.h>

const double TWO_PI = 6.2831853;

/*
 * Initial display-window size
 */
GLsizei winWidth = 400;
GLsizei winHeight = 400;

GLuint regHex;

class screenPt {
private:
    GLint x;
    GLint y;
public:
    /*
     * Default Constructor: initializes coordinate position to (0, 0)
     */
    screenPt() {
        x = y = 0;
    }

    void setCoords(GLint xCoord, GLint yCoord) {
        x = xCoord;
        y = yCoord;
    }

    GLint getx() const {
        return x;
    }

    GLint gety() const {
        return y;
    }
};

static void init(void) {
    screenPt hexVertex;
    screenPt circCtr;
    GLdouble theta;
    GLint k;

    /*
     * set circle center coordinates
     */
    circCtr.setCoords(winWidth / 2, winHeight / 2);
    glClearColor(1.0, 1.0, 1.0, 0.0); //display-window color = white
    /*
     * set up a display list for a red regular hexagon
     * vertice for the hexagon are six equally spaced
     * points around the circumference of a circle.
     */
    regHex = glGenLists(1);//get an ID for the display list
    glNewList(regHex, GL_COMPILE);
        glColor3f(1.0, 0.0, 0.0);//set fill color hexagon to red
        glBegin(GL_POLYGON);
            for(k = 0 ; k < 6 ; k++) {
                theta = TWO_PI * k / 6.0;
                hexVertex.setCoords(circCtr.getx() + 150 * cos(theta), circCtr.gety() + 150 * sin(theta));
                glVertex2i(hexVertex.getx(), hexVertex.gety());
            }
        glEnd();
    glEndList();
}

void regHexagon(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(regHex);
    glFlush();
}

void winReshapeFcn(int newWidth, int newHeight) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
    glClear(GL_COLOR_BUFFER_BIT);
}

void test_example_4_30(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Reshape-Function & Display-List Example");
    init();
    glutDisplayFunc(regHexagon);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}

