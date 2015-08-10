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

/*
 * describe the edge with int values in 2D
 */
class EDGE_int_2D {
public:
    POINT_int_2D vertex[2];
};

/*
 * describe the edge with int values in 3D
 */
class EDGE_int_3D {
public:
    POINT_int_3D vertex[2];
};

/*
 * describe the surface with int values in 2D
 */
class SURFACE_int_2D {
public:
    GLint sum_edges;
    EDGE_int_2D *edges_int;
};

/*
 * describe the surface with int values in 3D
 */
class SURFACE_int_3D {
public:
    GLint sum_edges;
    EDGE_int_3D *edges_int;
};

/*
 * describe the polygon with int values in 2D
 */
class POLYGON_int_2D {
public:
    GLint sum_points;
    GLint sum_edges;
    GLint sum_surfaces;
    POINT_int_2D *point;
    EDGE_int_2D *edge;
    SURFACE_int_2D *surface;
};

/*
 * describe the polygon with int values in 3D
 */
class POLYGON_int_3D {
public:
    GLint sum_points;
    GLint sum_edges;
    GLint sum_surfaces;
    POINT_int_3D *point;
    EDGE_int_3D *edge;
    SURFACE_int_3D *surface;
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

/*
 * describe the edge with float values in 2D
 */
class EDGE_float_2D {
public:
    POINT_float_2D vertex[2];
};

/*
 * describe the edge with float values in 3D
 */
class EDGE_float_3D {
public:
    POINT_float_3D vertex[2];
};

/*
 * describe the surface with float values in 2D
 */
class SURFACE_float_2D {
public:
    GLint sum_edges;
    EDGE_float_2D *edges_int;
};

/*
 * describe the surface with float values in 3D
 */
class SURFACE_float_3D {
public:
    GLint sum_edges;
    EDGE_float_3D *edges_int;
};

/*
 * describe the polygon with float values in 2D
 */
class POLYGON_float_2D {
public:
    GLint sum_points;
    GLint sum_edges;
    GLint sum_surfaces;
    POINT_float_2D *point;
    POINT_V_float_2D *point_v;
    EDGE_float_2D *edge;
    SURFACE_float_2D *surface;
};

/*
 * describe the polygon with float values in 3D
 */
class POLYGON_float_3D {
public:
    GLint sum_points;
    GLint sum_edges;
    GLint sum_surfaces;
    POINT_float_3D *point;
    POINT_V_float_3D *point_v;
    EDGE_float_3D *edge;
    SURFACE_float_3D *surface;
};
