/*
 * Matrix.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vector.h"

class Matrix {
public:
	Matrix();
	Matrix(double p00, double p01, double p02, double p03,
			double p10, double p11, double p12, double p13,
			double p20, double p21, double p22, double p23,
			double p30, double p31, double p32, double p33);
	virtual ~Matrix();
	void translationMatrix(double m14, double m24, double m34);
	void scalingMatrix(double m11, double m22, double m33);
	void shearingMatrix(int row, int col, double value);
	void xRollMatrix(double angle);
	void yRollMatrix(double angle);
	void zRollMatrix(double angle);
	void rollMatrix(Vector u, double angle);
	Vector transformVector(Vector vector);
private:
	int rows;
	int cols;
	double** matrix;
	double c;
	double s;
};

#endif /* MATRIX_H_ */
