/*
 * created by lookfiresu123 @ 2015/8/9
 */

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include"calculation.h"

/* 初始化一个GLint类型的三维向量  */
void Initialize_vector_int(Vector_int *p, GLint x, GLint y, GLint z) {
	p->x = x;
	p->y = y;
	p->z = z;
}

/* 初始化一个GLfloat类型的三维向量  */
void Initialize_vector_float(Vector_float *p, GLfloat x, GLfloat y, GLfloat z) {
	p->x = x;
	p->y = y;
	p->z = z;
}

/* 计算两个Vector_int类型的向量的叉积 */
Vector_int Calculate_vector_product_int(Vector_int factor_1, Vector_int factor_2) {
	Vector_int result;
	result.x =  factor_1.y * factor_2.z - factor_1.z * factor_2.y;
	result.y = factor_1.z * factor_2.x - factor_1.x * factor_2.z;
	result.z = factor_1.x * factor_2.y - factor_1.y * factor_2.x;
	return result;
}

/* 计算两个Vector_float类型的向量的叉积 */
Vector_float Calculate_vector_product_float(Vector_float factor_1, Vector_float factor_2) {
	Vector_float result;
	result.x =  factor_1.y * factor_2.z - factor_1.z * factor_2.y;
	result.y = factor_1.z * factor_2.x - factor_1.x * factor_2.z;
	result.z = factor_1.x * factor_2.y - factor_1.y * factor_2.x;
	return result;
}
