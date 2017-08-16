/*
 * Sphere.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Sphere.h"

#include <cmath>
#include <iostream>

Sphere::Sphere() {
	// TODO Auto-generated constructor stub

}

Sphere::Sphere(double r, Vector middle) {
	this->r = r;
	this->middle = middle;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

Vector Sphere::getMiddle() {
	return middle;
}

Vector Sphere::getFirstIntersectionWithSphere(Line line) {
	double distanceLineToMiddle;
	double a, b, c, t;
	double x, y, z;
	Vector noIntersection(0, 0, 0, 1000);

	a = pow((line.getPointB().getX() - line.getPointA().getX()), 2) +
			pow((line.getPointB().getY() - line.getPointA().getY()), 2) +
			pow((line.getPointB().getZ() - line.getPointA().getZ()), 2);
	b = 2 * ((line.getPointB().getX() - line.getPointA().getX()) * (line.getPointA().getX() - middle.getX()) +
			(line.getPointB().getY() - line.getPointA().getY()) * (line.getPointA().getY() - middle.getY()) +
			(line.getPointB().getZ() - line.getPointA().getZ()) * (line.getPointA().getZ() - middle.getZ()));
	c = pow(middle.getX(), 2) + pow(middle.getY(), 2) + pow(middle.getZ(), 2) +
			pow(line.getPointA().getX(), 2) + pow(line.getPointA().getY(), 2) + pow(line.getPointA().getZ(), 2) -
			2 * (middle.getX() * line.getPointA().getX() + middle.getY() * line.getPointA().getY() + middle.getZ() * line.getPointA().getZ()) -
			pow(r, 2);

	distanceLineToMiddle = line.distanceToPoint(middle);

	if (distanceLineToMiddle == r) {
		t = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		Vector intersection1(
				line.getPointA().getX() + (line.getPointB().getX() - line.getPointA().getX()) * t,
				line.getPointA().getY() + (line.getPointB().getY() - line.getPointA().getY()) * t,
				line.getPointA().getZ() + (line.getPointB().getZ() - line.getPointA().getZ()) * t,
				1);
		return intersection1;
	}
	else if (distanceLineToMiddle < r) {
		t = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		Vector intersection1(
				line.getPointA().getX() + (line.getPointB().getX() - line.getPointA().getX()) * t,
				line.getPointA().getY() + (line.getPointB().getY() - line.getPointA().getY()) * t,
				line.getPointA().getZ() + (line.getPointB().getZ() - line.getPointA().getZ()) * t,
				1);
		t = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		Vector intersection2(
				line.getPointA().getX() + (line.getPointB().getX() - line.getPointA().getX()) * t,
				line.getPointA().getY() + (line.getPointB().getY() - line.getPointA().getY()) * t,
				line.getPointA().getZ() + (line.getPointB().getZ() - line.getPointA().getZ()) * t,
				1);
		if (intersection1.distanceToPoint(line.getPointA()) < intersection2.distanceToPoint(line.getPointA())) {
			return intersection1;
		}
		else {
			return intersection2;
		}
	}
	else {
		return noIntersection;
	}
}

