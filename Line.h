/*
 * Line.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef LINE_H_
#define LINE_H_

#include "Vector.h"

class Line {
public:
	Line();
	Line(Vector pointA, Vector pointB);
	virtual ~Line();
	Vector getPointA();
	Vector getPointB();
	void setPointA(Vector pointA);
	void setPointB(Vector pointB);
	double distanceToPoint(Vector point);
private:
	Vector pointA;
	Vector pointB;
};

#endif /* LINE_H_ */
