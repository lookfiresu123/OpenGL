/*
 * created by lookfiresu123 @ 2015/8/9
 */

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include"type.h"

/* 初始化一个GLint类型的2维向量  */
void Initialize_vector_int_2D(Vector_int_2D *p, GLint x, GLint y) {
	p->x = x;
	p->y = y;
}

/* 初始化一个GLfloat类型的2维向量  */
void Initialize_vector_float_2D(Vector_float_2D *p, GLfloat x, GLfloat y) {
	p->x = x;
	p->y = y;
}

/* 初始化一个GLint类型的三维向量  */
void Initialize_vector_int_3D(Vector_int_3D *p, GLint x, GLint y, GLint z) {
	p->x = x;
	p->y = y;
	p->z = z;
}

/* 初始化一个GLfloat类型的三维向量  */
void Initialize_vector_float_3D(Vector_float_3D *p, GLfloat x, GLfloat y, GLfloat z) {
	p->x = x;
	p->y = y;
	p->z = z;
}

/* 计算两个Vector_int类型的向量的叉积 */
Vector_int_3D Calculate_vector_product_int_3D(Vector_int_3D factor_1, Vector_int_3D factor_2) {
	Vector_int_3D result;
	result.x =  factor_1.y * factor_2.z - factor_1.z * factor_2.y;
	result.y = factor_1.z * factor_2.x - factor_1.x * factor_2.z;
	result.z = factor_1.x * factor_2.y - factor_1.y * factor_2.x;
	return result;
}

/* 计算两个Vector_float类型的向量的叉积 */
Vector_float_3D Calculate_vector_product_float_3D(Vector_float_3D factor_1, Vector_float_3D factor_2) {
	Vector_float_3D result;
	result.x =  factor_1.y * factor_2.z - factor_1.z * factor_2.y;
	result.y = factor_1.z * factor_2.x - factor_1.x * factor_2.z;
	result.z = factor_1.x * factor_2.y - factor_1.y * factor_2.x;
	return result;
}

/* 给定两个点，计算向量，类型为int, in 2D */
Vector_int_2D Calculate_vector_int_2D(POINT_int_2D source, POINT_int_2D dest) {
	Vector_int_2D vector;
	vector.x = dest.x - source.x;
	vector.y = dest.y - source.y;
	return vector;
}

/* 给定两个点，计算向量，类型为int, in 3D */
Vector_int_3D Calculate_vector_int_3D(POINT_int_3D source, POINT_int_3D dest) {
	Vector_int_3D vector;
	vector.x = dest.x - source.x;
	vector.y = dest.y - source.y;
	vector.z = dest.z - source.z;
	return vector;
}

/* 给定两个点，计算向量，类型为float, in 2D */
Vector_float_2D Calculate_vector_float_2D(POINT_float_2D source, POINT_float_2D dest) {
	Vector_float_2D vector;
	vector.x = dest.x - source.x;
	vector.y = dest.y - source.y;
	return vector;
}

/* 给定两个点，计算向量，类型为float, in 3D */
Vector_float_3D Calculate_vector_float_3D(POINT_float_3D source, POINT_float_3D dest) {
	Vector_float_3D vector;
	vector.x = dest.x - source.x;
	vector.y = dest.y - source.y;
	vector.z = dest.z - source.z;
	return vector;
}

