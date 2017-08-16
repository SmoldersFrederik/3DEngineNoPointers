/*
 * PlaneWithBoundaries.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik
 */

#ifndef PLANEWITHBOUNDARIES_H_
#define PLANEWITHBOUNDARIES_H_

#include "Plane.h"

class PlaneWithBoundaries: public Plane {
public:
	PlaneWithBoundaries();
	PlaneWithBoundaries(Vector pointA, Vector pointB, Vector pointC, Vector pointD);
	virtual ~PlaneWithBoundaries();
	Vector getPointD();
	bool intersectionBetweenBoundaries(Vector intersection);
	void setPlane(Vector pointA, Vector pointB, Vector pointC, Vector pointD);
private:
	Vector pointD;
	double PI;
};

#endif /* PLANEWITHBOUNDARIES_H_ */
