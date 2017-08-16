/*
 * PlaneWithBoundaries.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik
 */

#include "PlaneWithBoundaries.h"

PlaneWithBoundaries::PlaneWithBoundaries() {
	// TODO Auto-generated constructor stub

}

PlaneWithBoundaries::PlaneWithBoundaries(Vector pointA, Vector pointB,
		Vector pointC, Vector pointD) {
	this->pointA = pointA;
	this->pointB = pointB;
	this->pointC = pointC;
	this->pointD = pointD;
	PI = 3.14159265358979323846;
}

PlaneWithBoundaries::~PlaneWithBoundaries() {
	// TODO Auto-generated destructor stub
}

Vector PlaneWithBoundaries::getPointD() {
	return pointD;
}

bool PlaneWithBoundaries::intersectionBetweenBoundaries(Vector intersection) {
	/*
	double area1, area2, area3, area4, areaPlane, totalArea;
	area1 = abs((0.5) *
			intersection->distanceToPoint(pointA) *
			intersection->distanceToPoint(pointB) *
			sin(intersection->sumWithVector(pointA)->angleBetweenVector(intersection->sumWithVector(pointB))/(2*PI)*360));
	area2 = abs((0.5) *
			intersection->distanceToPoint(pointB) *
			intersection->distanceToPoint(pointC) *
			sin(intersection->sumWithVector(pointB)->angleBetweenVector(intersection->sumWithVector(pointC))/(2*PI)*360));
	area3 = abs((0.5) *
			intersection->distanceToPoint(pointC) *
			intersection->distanceToPoint(pointD) *
			sin(intersection->sumWithVector(pointC)->angleBetweenVector(intersection->sumWithVector(pointD))/(2*PI)*360));
	area4 = abs((0.5) *
			intersection->distanceToPoint(pointA) *
			intersection->distanceToPoint(pointD) *
			sin(intersection->sumWithVector(pointA)->angleBetweenVector(intersection->sumWithVector(pointD))/(2*PI)*360));
	totalArea = area1 + area2 + area3 + area4;
	areaPlane = pointA->distanceToPoint(pointB) * pointA->distanceToPoint(pointD);
	if (totalArea > areaPlane || totalArea != totalArea) {
		return false;
	}
	else {
		return true;
	}
	*/

	if (
			pointA.dotProductWithVector(pointB.substractWithVector(pointA)) <= intersection.dotProductWithVector(pointB.substractWithVector(pointA)) &&
			intersection.dotProductWithVector(pointB.substractWithVector(pointA)) <= pointB.dotProductWithVector(pointB.substractWithVector(pointA)) &&
			pointA.dotProductWithVector(pointD.substractWithVector(pointA)) <= intersection.dotProductWithVector(pointD.substractWithVector(pointA)) &&
			intersection.dotProductWithVector(pointD.substractWithVector(pointA)) <= pointD.dotProductWithVector(pointD.substractWithVector(pointA))
			) {
		return true;
	}
	else
		return false;

}

void PlaneWithBoundaries::setPlane(Vector pointA, Vector pointB, Vector pointC, Vector pointD) {
	this->pointA = pointA;
	this->pointB = pointB;
	this->pointC = pointC;
	this->pointD = pointD;
}

