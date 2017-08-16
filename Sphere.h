/*
 * Sphere.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Vector.h"
#include "Line.h"

class Sphere {
public:
	Sphere();
	Sphere(double r, Vector middle);
	virtual ~Sphere();
	Vector getMiddle();
	Vector getFirstIntersectionWithSphere(Line line);
private:
	double r;
	Vector middle;
};

#endif /* SPHERE_H_ */
