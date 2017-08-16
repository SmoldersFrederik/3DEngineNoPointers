/*
 * Vector.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Vector.h"
#include <cmath>

Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
	dot = 0;
}

Vector::Vector(const Vector& copy) {
	x = copy.x;
	y = copy.y;
	z = copy.z;
	dot = copy.dot;
}

Vector::Vector(double x, double y, double z, double dot) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->dot = dot;
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

double Vector::getX() {
	return x;
}

double Vector::getY() {
	return y;
}

double Vector::getZ() {
	return z;
}

double Vector::getDot() {
	return dot;
}

void Vector::setX(double x) {
	this->x = x;
}

void Vector::setY(double y) {
	this->y = y;
}

void Vector::setZ(double z) {
	this->z = z;
}

void Vector::setDot(double dot) {
	this->dot = dot;
}

void Vector::setValues(double x, double y, double z, double dot) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->dot = dot;
}

double Vector::getMagnitude() {
	if (dot != 1) {
		return (sqrt(pow(x,2) + pow(y,2) + pow(z,2)));
	}
	else {
		return 0;
	}
}

Vector Vector::sumWithVector(Vector a) {
	double xNew = this->x + a.getX();
	double yNew = this->y + a.getY();
	double zNew = this->z + a.getZ();
	double dotNew = this->dot + a.getDot();
	if (dotNew > 1) {
		dotNew = 0;
	}
	Vector vector(xNew, yNew, zNew, dotNew);
	return vector;
}

Vector Vector::substractWithVector(Vector a) {
	double xNew = this->x - a.getX();
	double yNew = this->y - a.getY();
	double zNew = this->z - a.getZ();
	double dotNew = this->dot - a.getDot();
	Vector vector(xNew, yNew, zNew, dotNew);
	return vector;
}

double Vector::dotProductWithVector(Vector a) {
	return this->x * a.getX() + this->y * a.getY() + this->z * a.getZ();
}

Vector Vector::crossProductWithVector(Vector a) {
	double xNew = this->y * a.getZ() - this->z * a.getY();
	double yNew = this->z * a.getX() - this->x * a.getZ();
	double zNew = this->x * a.getY() - this->y * a.getX();
	Vector vector(xNew, yNew, zNew, 0);
	return vector;
}

double Vector::angleBetweenVector(Vector a) {
	Vector vector(this->x, this->y, this->z, 0);
	return acos(vector.dotProductWithVector(a) / (vector.getMagnitude() * a.getMagnitude()));
}

double Vector::distanceToPoint(Vector a) {
	return sqrt(pow((this->x - a.getX()),2)
			+ pow((this->y - a.getY()),2)
			+ pow((this->z - a.getZ()),2));
}

void Vector::normalize() {
	double magnitude = sqrt(pow(this->x,2) + pow(this->y,2) + pow(this->z,2));
	this->x = this->x / magnitude;
	this->y = this->y / magnitude;
	this->z = this->z / magnitude;
}

Vector Vector::multiplyWithValue(double value) {
	Vector vector(this->x * value, this->y * value, this->z * value, this->dot);
	return vector;
}

