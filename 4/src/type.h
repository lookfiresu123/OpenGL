/*
 * created by lookfiresu123 @ 2015/8/9
 */

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

/* default in 2D */
class Vector_int_2D {
public:
	GLint x, y;
};

/* in 3D */
class Vector_int_3D {
public:
	GLint x, y, z;
};

/*
 * point in 2D
 */
class POINT_int_2D {
public:
    GLint x,y;
};

/*
 * point in 2D
 */
class POINT_V_int_2D {
public:
    /*
     * @ vertex[0]: x coordinates
     * @ vertex[1]: y coordinates
     */
    GLint vertex[2];
};

/*
 * point in 3D
 */
class POINT_int_3D {
public:
    GLint x,y,z;
};

/*
 * point in 3D
 */
class POINT_V_int_3D {
public:
    /*
     * @ vertex[0]: x coordinates
     * @ vertex[1]: y coordinates
     */
    GLint vertex[3];
};

/* default in 2D */
class Vector_float_2D {
public:
	GLfloat x, y;
};

/* in 3D */
class Vector_float_3D {
public:
	GLfloat x, y, z;
};

/*
 * point in 2D
 */
class POINT_float_2D {
public:
    GLfloat x,y;
};

/*
 * point in 2D
 */
class POINT_V_float_2D {
public:
    /*
     * @ vertex[0]: x coordinates
     * @ vertex[1]: y coordinates
     */
    GLfloat vertex[2];
};

/*
 * point in 3D
 */
class POINT_float_3D {
public:
    GLfloat x,y,z;
};

/*
 * point in 3D
 */
class POINT_V_float_3D {
public:
    /*
     * @ vertex[0]: x coordinates
     * @ vertex[1]: y coordinates
     */
    GLfloat vertex[3];
};
