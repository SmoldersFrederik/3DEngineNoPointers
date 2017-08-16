/*
 * Line.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: frede
 */

#include "Line.h"

Line::Line() {
	// TODO Auto-generated constructor stub

}

Line::Line(Vector pointA, Vector pointB) {
	this->pointA = pointA;
	this->pointB = pointB;
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

Vector Line::getPointA() {
	return pointA;
}

Vector Line::getPointB() {
	return pointB;
}

void Line::setPointA(Vector pointA) {
	this->pointA = pointA;
}

void Line::setPointB(Vector pointB) {
	this->pointB = pointB;
}

double Line::distanceToPoint(Vector point) {
	Vector directionLine;
	Vector directionPointToPointFromLine;
	Vector crossProduct;
	double distance;

	directionLine = pointA.substractWithVector(pointB);
	directionPointToPointFromLine = pointA.substractWithVector(point);
	crossProduct = directionPointToPointFromLine.crossProductWithVector(directionLine);

	distance = crossProduct.getMagnitude() / directionLine.getMagnitude();

	return distance;
}

