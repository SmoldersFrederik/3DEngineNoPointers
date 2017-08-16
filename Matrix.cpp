/*
 * Matrix.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Matrix.h"
#include <math.h>

Matrix::Matrix() {
	rows = 4;
	cols = 4;
	c = 0;
	s = 0;
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++)
	    matrix[i] = new double[cols];
}

Matrix::Matrix(double p00, double p01, double p02, double p03, double p10,
		double p11, double p12, double p13, double p20, double p21, double p22,
		double p23, double p30, double p31, double p32, double p33) {
	rows = 4;
	cols = 4;
	c = 0;
	s = 0;
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++) {
	    matrix[i] = new double[cols];
	}

	matrix[0][0] = p00;
	matrix[0][1] = p01;
	matrix[0][2] = p02;
	matrix[0][3] = p03;
	matrix[1][0] = p10;
	matrix[1][1] = p11;
	matrix[1][2] = p12;
	matrix[1][3] = p13;
	matrix[2][0] = p20;
	matrix[2][1] = p21;
	matrix[2][2] = p22;
	matrix[2][3] = p23;
	matrix[3][0] = p30;
	matrix[3][1] = p31;
	matrix[3][2] = p32;
	matrix[3][3] = p33;
}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
}

void Matrix::translationMatrix(double m03, double m13, double m23) {
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = m03;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = m13;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = m23;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void Matrix::scalingMatrix(double m00, double m11, double m22) {
	matrix[0][0] = m00;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = m11;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = m22;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void Matrix::shearingMatrix(int row, int col, double value) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	matrix[row][col] = value;
}

void Matrix::xRollMatrix(double angle) {
	c = cos(angle);
	s = sin(angle);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	matrix[1][1] = c;
	matrix[1][2] = -s;
	matrix[2][1] = s;
	matrix[2][2] = c;
}

void Matrix::yRollMatrix(double angle) {
	c = cos(angle);
	s = sin(angle);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	matrix[0][0] = c;
	matrix[0][2] = s;
	matrix[2][0] = -s;
	matrix[2][2] = c;

}

void Matrix::zRollMatrix(double angle) {
	c = cos(angle);
	s = sin(angle);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	matrix[0][0] = c;
	matrix[0][1] = -s;
	matrix[1][0] = s;
	matrix[1][1] = c;

}

void Matrix::rollMatrix(Vector u, double angle) {
	c = cos(angle);
	s = sin(angle);

	matrix[0][0] = c+(1-c)*pow(u.getX(),2);
	matrix[0][1] = (1-c)*u.getY()*u.getX()-s*u.getZ();
	matrix[0][2] = (1-c)*u.getZ()*u.getX()+s*u.getY();
	matrix[0][3] = 0;
	matrix[1][0] = (1-c)*u.getX()*u.getY()+s*u.getZ();
	matrix[1][1] = c+(1-c)*pow(u.getY(),2);
	matrix[1][2] = (1-c)*u.getZ()*u.getY()-s*u.getX();
	matrix[1][3] = 0;
	matrix[2][0] = (1-c)*u.getX()*u.getZ()-s*u.getY();
	matrix[2][1] = (1-c)*u.getY()*u.getZ()+s*u.getX();
	matrix[2][2] = c+(1-c)*pow(u.getZ(),2);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

Vector Matrix::transformVector(Vector vector) {
	double xNew = matrix[0][0]*vector.getX() + matrix[0][1]*vector.getY() + matrix[0][2]*vector.getZ() + matrix[0][3]*vector.getDot();
	double yNew = matrix[1][0]*vector.getX() + matrix[1][1]*vector.getY() + matrix[1][2]*vector.getZ() + matrix[1][3]*vector.getDot();
	double zNew = matrix[2][0]*vector.getX() + matrix[2][1]*vector.getY() + matrix[2][2]*vector.getZ() + matrix[2][3]*vector.getDot();
	double dotNew = matrix[3][0]*vector.getX() + matrix[3][1]*vector.getY() + matrix[3][2]*vector.getZ() + matrix[3][3]*vector.getDot();
	Vector newVector(xNew,yNew,zNew,dotNew);
	return newVector;
}

