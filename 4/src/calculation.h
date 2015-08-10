/*
 * created by lookfiresu123 @ 2015/8/9
 */

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include"type.h"

void Initialize_vector_int_2D(Vector_int_2D *p, GLint x, GLint y);
void Initialize_vector_float_2D(Vector_float_2D *p, GLfloat x, GLfloat y);
void Initialize_vector_int_3D(Vector_int_3D *p, GLint x, GLint y, GLint z);
void Initialize_vector_int_3D(Vector_int_3D *p, GLint x, GLint y, GLint z);
void Initialize_vector_float_3D(Vector_float_3D *p, GLfloat x, GLfloat y, GLfloat z);
Vector_int_3D Calculate_vector_product_int_3D(Vector_int_3D factor_1, Vector_int_3D factor_2);
Vector_float_3D Calculate_vector_product_float_3D(Vector_float_3D factor_1, Vector_float_3D factor_2);
Vector_int_2D Calculate_vector_int_2D(POINT_int_2D source, POINT_int_2D dest);
Vector_int_3D Calculate_vector_int_3D(POINT_int_3D source, POINT_int_3D dest);
Vector_float_2D Calculate_vector_float_2D(POINT_float_2D source, POINT_float_2D dest);
Vector_float_3D Calculate_vector_float_3D(POINT_float_3D source, POINT_float_3D dest);