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

	Vector lineDirection(
			line.getPointB().getX()-line.getPointA().getX(),
			line.getPointB().getY()-line.getPointA().getY(),
			line.getPointB().getZ()-line.getPointA().getZ(),
			1);
	double a = pow(lineDirection.getMagnitude(), 2);

	double b = lineDirection.multiplyWithValue(2).dotProductWithVector(line.getPointA().substractWithVector(middle));

	double c = pow((line.getPointA().substractWithVector(middle)).getMagnitude(), 2) - pow(r, 2);

	double d = pow(b, 2) - 4 * a * c;

	if (d > 0) {
		double u1 = (-b + sqrt(d))/(2*a);
		double u2 = (-b - sqrt(d))/(2*a);
		Vector intersection1 = line.getPointA().sumWithVector(lineDirection.multiplyWithValue(u1));
		Vector intersection2 = line.getPointA().sumWithVector(lineDirection.multiplyWithValue(u2));

		if (intersection1.distanceToPoint(line.getPointA()) < intersection2.distanceToPoint(line.getPointA())) {
			intersection1.setDot(1);
			return intersection1;
		}
		else {
			intersection2.setDot(1);
			return intersection2;
		}
	}

	else if (d == 0) {
		double u = (-b)/(2*a);
		Vector intersection = line.getPointA().sumWithVector(lineDirection.multiplyWithValue(u));
		return intersection;
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
