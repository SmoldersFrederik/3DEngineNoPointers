/*
 * Vector.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
public:
	Vector();
	Vector(const Vector& copy);
	Vector(double x, double y, double z, double dot);
	virtual ~Vector();
	double getX();
	double getY();
	double getZ();
	double getDot();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void setDot(double dot);
	void setValues(double x, double y, double z, double dot);
	double getMagnitude();
	Vector sumWithVector(Vector a);
	Vector substractWithVector(Vector a);
	double dotProductWithVector(Vector a);
	Vector crossProductWithVector(Vector a);
	double angleBetweenVector(Vector a);
	double distanceToPoint(Vector a);
	void normalize();
	Vector multiplyWithValue(double value);
private:
	double x;
	double y;
	double z;
	double dot;
};

#endif /* VECTOR_H_ */
