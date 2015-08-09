/*
 * created by lookfiresu123 @ 2015/8/9
 */

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

class Vector_int {
	GLint x, y, z;
};

class Vector_float {
	GLfloat x, y, z;
};

void Initialize_vector_int(Vector_int *p, GLint x, GLint y, GLint z);
void Initialize_vector_int(Vector_float *p, GLfloat x, GLfloat y, GLfloat z);
Vector_int Calculate_vector_product_int(Vector_int factor_1, Vector_int factor_2);
Vector_float Calculate_vector_product_float(Vector_float factor_1, Vector_float factor_2);