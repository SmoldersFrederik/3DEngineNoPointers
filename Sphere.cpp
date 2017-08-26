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

Sphere::Sphere(double r, Vector middle, string color, int number) {
	this->r = r;
	this->middle = middle;
	this->color = color;
	this->number = number;
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

	a = pow((line.getPointA().getX() - line.getPointB().getX()), 2) +
			pow((line.getPointA().getY() - line.getPointB().getY()), 2) +
			pow((line.getPointA().getZ() - line.getPointB().getZ()), 2);
	b = 2 * ((line.getPointA().getX() - line.getPointB().getX()) * (line.getPointB().getX() - middle.getX()) +
			(line.getPointA().getY() - line.getPointB().getY()) * (line.getPointB().getY() - middle.getY()) +
			(line.getPointA().getZ() - line.getPointB().getZ()) * (line.getPointB().getZ() - middle.getZ()));
	c = pow(middle.getX(), 2) + pow(middle.getY(), 2) + pow(middle.getZ(), 2) +
			pow(line.getPointB().getX(), 2) + pow(line.getPointB().getY(), 2) + pow(line.getPointB().getZ(), 2) -
			2 * (middle.getX() * line.getPointB().getX() + middle.getY() * line.getPointB().getY() + middle.getZ() * line.getPointB().getZ()) -
			pow(r, 2);

	distanceLineToMiddle = line.distanceToPoint(middle);

	if (distanceLineToMiddle == r) {
		t = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		Vector intersection1(
				line.getPointB().getX() + (line.getPointA().getX() - line.getPointB().getX()) * t,
				line.getPointB().getY() + (line.getPointA().getY() - line.getPointB().getY()) * t,
				line.getPointB().getZ() + (line.getPointA().getZ() - line.getPointB().getZ()) * t,
				1);
		return intersection1;
	}
	else if (distanceLineToMiddle < r) {
		t = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		Vector intersection1(
				line.getPointB().getX() + (line.getPointA().getX() - line.getPointB().getX()) * t,
				line.getPointB().getY() + (line.getPointA().getY() - line.getPointB().getY()) * t,
				line.getPointB().getZ() + (line.getPointA().getZ() - line.getPointB().getZ()) * t,
				1);
		t = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		Vector intersection2(
				line.getPointB().getX() + (line.getPointA().getX() - line.getPointB().getX()) * t,
				line.getPointB().getY() + (line.getPointA().getY() - line.getPointB().getY()) * t,
				line.getPointB().getZ() + (line.getPointA().getZ() - line.getPointB().getZ()) * t,
				1);
		if (intersection1.distanceToPoint(line.getPointB()) < intersection2.distanceToPoint(line.getPointB())) {
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

Vector Sphere::getFirstIntersectionWithSphere2(Line line) {
	Vector noIntersection(0, 0, 0, 1000);

	double a = pow((line.getPointB().getX() - line.getPointA().getX()), 2) + pow((line.getPointB().getY() - line.getPointA().getY()), 2) + pow((line.getPointB().getZ() - line.getPointA().getZ()), 2);
	double b = 2 * ((line.getPointB().getX() - line.getPointA().getX()) * (line.getPointA().getX() - middle.getX()) + (line.getPointB().getY() - line.getPointA().getY()) * (line.getPointA().getY() - middle.getY()) + (line.getPointB().getZ() - line.getPointA().getZ()) * (line.getPointA().getZ() - middle.getZ()));
	double c = pow(middle.getX(), 2) + pow(middle.getY(), 2) + pow(middle.getZ(), 2) + pow(line.getPointA().getX(), 2) + pow(line.getPointA().getY(), 2) + pow(line.getPointA().getZ(), 2) - 2 * (middle.getX() * line.getPointA().getX() + middle.getY() * line.getPointA().getY() + middle.getZ() * line.getPointA().getZ()) - pow(r, 2);

	double discriminant = pow(b, 2) - 4 * a * c;

	if (discriminant > 0) {
		double t1 = (-b + sqrt(discriminant)) / (2 * a);
		double t2 = (-b - sqrt(discriminant)) / (2 * a);

		double x1 = line.getPointA().getX() + ((line.getPointB().getX() - line.getPointA().getX()) * t1);
		double y1 = line.getPointA().getY() + ((line.getPointB().getY() - line.getPointA().getY()) * t1);
		double z1 = line.getPointA().getZ() + ((line.getPointB().getZ() - line.getPointA().getZ()) * t1);

		double x2 = line.getPointA().getX() + ((line.getPointB().getX() - line.getPointA().getX()) * t2);
		double y2 = line.getPointA().getY() + ((line.getPointB().getY() - line.getPointA().getY()) * t2);
		double z2 = line.getPointA().getZ() + ((line.getPointB().getZ() - line.getPointA().getZ()) * t2);

		Vector intersection1(x1, y1, z1, 1);
		Vector intersection2(x2, y2, z2, 1);

		if (intersection1.distanceToPoint(line.getPointB()) < intersection2.distanceToPoint(line.getPointB())) {
			return intersection1;
		}
		else {
			return intersection2;
		}
	}
	else if (discriminant == 0) {
		double t = (-b) / (2 * a);

		double x = line.getPointA().getX() + ((line.getPointB().getX() - line.getPointA().getX()) * t);
		double y = line.getPointA().getY() + ((line.getPointB().getY() - line.getPointA().getY()) * t);
		double z = line.getPointA().getZ() + ((line.getPointB().getZ() - line.getPointA().getZ()) * t);

		Vector intersection(x, y, z, 1);
	}
	else {
		return noIntersection;
	}
}

string Sphere::getColor(){
	return color;
}

int Sphere::getNumber() {
	return number;
}
