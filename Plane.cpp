/*
 * Plane.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: frede
 */

#include "Plane.h"

Plane::Plane() {
	// TODO Auto-generated constructor stub

}

Plane::Plane(Vector pointA, Vector pointB, Vector pointC) {
	this->pointA = pointA;
	this->pointB = pointB;
	this->pointC = pointC;
}

Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

Vector Plane::getPointA() {
	return pointA;
}

Vector Plane::getPointB() {
	return pointB;
}

Vector Plane::getPointC() {
	return pointC;
}

Vector Plane::calculateNormalOfPlane() {
	Vector x(
			pointB.getX() - pointA.getX(),
			pointB.getY() - pointA.getY(),
			pointB.getZ() - pointA.getZ(),
			pointB.getDot() - pointA.getDot());
	Vector y(
			pointC.getX() - pointA.getX(),
			pointC.getY() - pointA.getY(),
			pointC.getZ() - pointA.getZ(),
			pointC.getDot() - pointA.getDot());
	Vector normal = x.crossProductWithVector(y);
	return normal;
}

Vector Plane::intersectionWithLine(Line line) {
	Plane plane(pointA, pointB, pointC);
	Vector u = line.getPointB().substractWithVector(line.getPointA());
	Vector w = line.getPointA().substractWithVector(plane.getPointA());

	double D = plane.calculateNormalOfPlane().dotProductWithVector(u);
	double N = -plane.calculateNormalOfPlane().dotProductWithVector(w);

	Vector intersection;

	double sI = N/D;
	if (sI > 0 || sI < 1) {
		//intersection = line.pointA + sI * u;
		u.setX(u.getX() * sI);
		u.setY(u.getY() * sI);
		u.setZ(u.getZ() * sI);
		u.setDot(0);
		intersection = line.getPointA().sumWithVector(u);
	}

	return intersection;
}

