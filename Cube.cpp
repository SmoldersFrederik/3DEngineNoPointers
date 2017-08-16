/*
 * Cube.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Cube.h"

#include <iostream>

Cube::Cube() {
	// TODO Auto-generated constructor stub

}

Cube::Cube(Vector point1, Vector point2, Vector point3, Vector point4,
		Vector point5, Vector point6, Vector point7, Vector point8, string color, int number) {
	this->point1 = point1;
	this->point2 = point2;
	this->point3 = point3;
	this->point4 = point4;
	this->point5 = point5;
	this->point6 = point6;
	this->point7 = point7;
	this->point8 = point8;
	this->plane1.setPlane(this->point1, this->point2, this->point4, this->point3);
	this->plane2.setPlane(this->point1, this->point3, this->point7, this->point5);
	this->plane3.setPlane(this->point1, this->point2, this->point6, this->point5);
	this->plane4.setPlane(this->point2, this->point4, this->point8, this->point6);
	this->plane5.setPlane(this->point5, this->point6, this->point8, this->point7);
	this->plane6.setPlane(this->point3, this->point4, this->point8, this->point7);
	this->planeLastIntersection = 0;
	this->active = true;
	this->color = color;
	this->number = number;
}

Cube::~Cube() {
	// TODO Auto-generated destructor stub
}

Vector Cube::getPoint1() {
	return point1;
}

Vector Cube::getPoint2() {
	return point2;
}

Vector Cube::getPoint3() {
	return point3;
}

Vector Cube::getPoint4() {
	return point4;
}

Vector Cube::getPoint5() {
	return point5;
}

Vector Cube::getPoint6() {
	return point6;
}

Vector Cube::getPoint7() {
	return point7;
}

Vector Cube::getPoint8() {
	return point8;
}

PlaneWithBoundaries Cube::getPlane1() {
	return plane1;
}

PlaneWithBoundaries Cube::getPlane2() {
	return plane2;
}

PlaneWithBoundaries Cube::getPlane3() {
	return plane3;
}

PlaneWithBoundaries Cube::getPlane4() {
	return plane4;
}

PlaneWithBoundaries Cube::getPlane5() {
	return plane5;
}

PlaneWithBoundaries Cube::getPlane6() {
	return plane6;
}

Vector Cube::getFirstIntersectionWithCube(Line line) {
	double distanceToIntersection1 = 0;
	double distanceToIntersection2 = 0;
	int counter1 = 0;
	int counter2 = 0;
	Vector noIntersection(0, 0, 0, 1000);
	Vector intersectionWithPlane1 = plane1.intersectionWithLine(line);
	Vector intersectionWithPlane2 = plane2.intersectionWithLine(line);
	Vector intersectionWithPlane3 = plane3.intersectionWithLine(line);
	Vector intersectionWithPlane4 = plane4.intersectionWithLine(line);
	Vector intersectionWithPlane5 = plane5.intersectionWithLine(line);
	Vector intersectionWithPlane6 = plane6.intersectionWithLine(line);
	if (plane1.intersectionBetweenBoundaries(intersectionWithPlane1)) {
		if (distanceToIntersection1 == 0) {
			distanceToIntersection1 = intersectionWithPlane1.distanceToPoint(line.getPointA());
			counter1 = 1;
		}
		else {
			distanceToIntersection2 = intersectionWithPlane1.distanceToPoint(line.getPointA());
			counter2 = 1;
		}
	}
	if (plane2.intersectionBetweenBoundaries(intersectionWithPlane2)) {
		if (distanceToIntersection1 == 0) {
			distanceToIntersection1 = intersectionWithPlane2.distanceToPoint(line.getPointA());
			counter1 = 2;
		}
		else {
			distanceToIntersection2 = intersectionWithPlane2.distanceToPoint(line.getPointA());
			counter2 = 2;
		}
	}
	if (plane3.intersectionBetweenBoundaries(intersectionWithPlane3)) {
		if (distanceToIntersection1 == 0) {
			distanceToIntersection1 = intersectionWithPlane3.distanceToPoint(line.getPointA());
			counter1 = 3;
		}
		else {
			distanceToIntersection2 = intersectionWithPlane3.distanceToPoint(line.getPointA());
			counter2 = 3;
		}
	}
	if (plane4.intersectionBetweenBoundaries(intersectionWithPlane4)) {
		if (distanceToIntersection1 == 0) {
			distanceToIntersection1 = intersectionWithPlane4.distanceToPoint(line.getPointA());
			counter1 = 4;
		}
		else {
			distanceToIntersection2 = intersectionWithPlane4.distanceToPoint(line.getPointA());
			counter2 = 4;
		}
	}
	if (plane5.intersectionBetweenBoundaries(intersectionWithPlane5)) {
		if (distanceToIntersection1 == 0) {
			distanceToIntersection1 = intersectionWithPlane5.distanceToPoint(line.getPointA());
			counter1 = 5;
		}
		else {
			distanceToIntersection2 = intersectionWithPlane5.distanceToPoint(line.getPointA());
			counter2 = 5;
		}
	}
	if (plane6.intersectionBetweenBoundaries(intersectionWithPlane6)) {
		if (distanceToIntersection1 == 0) {
			distanceToIntersection1 = intersectionWithPlane6.distanceToPoint(line.getPointA());
			counter1 = 6;
		}
		else {
			distanceToIntersection2 = intersectionWithPlane6.distanceToPoint(line.getPointA());
			counter2 = 6;
		}
	}

	if (distanceToIntersection1 <= distanceToIntersection2 && distanceToIntersection1 != 0) {
		if (counter1 == 1) {
			planeLastIntersection = 1;
			return intersectionWithPlane1;
		}
		else if (counter1 == 2) {
			planeLastIntersection = 2;
			return intersectionWithPlane2;
		}
		else if (counter1 == 3) {
			planeLastIntersection = 3;
			return intersectionWithPlane3;
		}
		else if (counter1 == 4) {
			planeLastIntersection = 4;
			return intersectionWithPlane4;
		}
		else if (counter1 == 5) {
			planeLastIntersection = 5;
			return intersectionWithPlane5;
		}
		else if (counter1 == 6) {
			planeLastIntersection = 6;
			return intersectionWithPlane6;
		}
		else {
			return noIntersection;
		}
	}
	else if (distanceToIntersection1 > distanceToIntersection2) {
		if (counter2 == 1) {
			planeLastIntersection = 1;
			return intersectionWithPlane1;
		}
		else if (counter2 == 2) {
			planeLastIntersection = 2;
			return intersectionWithPlane2;
		}
		else if (counter2 == 3) {
			planeLastIntersection = 3;
			return intersectionWithPlane3;
		}
		else if (counter2 == 4) {
			planeLastIntersection = 4;
			return intersectionWithPlane4;
		}
		else if (counter2 == 5) {
			planeLastIntersection = 5;
			return intersectionWithPlane5;
		}
		else if (counter2 == 6) {
			planeLastIntersection = 6;
			return intersectionWithPlane6;
		}
		else {
			return noIntersection;
		}
	}
	else {
		return noIntersection;
	}
}

int Cube::getPlaneLastIntersection() {
	return planeLastIntersection;
}

bool Cube::getActive() {
	return active;
}

string Cube::getColor() {
	return color;
}

int Cube::getNumber() {
	return number;
}

