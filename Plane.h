/*
 * Plane.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Vector.h"
#include "Line.h"

class Plane {
public:
public:
	Plane();
	Plane(Vector pointA, Vector pointB, Vector pointC);
	virtual ~Plane();
	Vector getPointA();
	Vector getPointB();
	Vector getPointC();
	Vector calculateNormalOfPlane();
	Vector intersectionWithLine(Line line);
protected:
	Vector pointA;
	Vector pointB;
	Vector pointC;
};

#endif /* PLANE_H_ */
