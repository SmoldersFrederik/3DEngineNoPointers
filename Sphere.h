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

#include <iostream>

using namespace std;

class Sphere {
public:
	Sphere();
	Sphere(double r, Vector middle, string color, int number);
	virtual ~Sphere();
	Vector getMiddle();
	Vector getFirstIntersectionWithSphere(Line line);
	string getColor();
	int getNumber();
private:
	double r;
	Vector middle;
	string color;
	int number;
};

#endif /* SPHERE_H_ */
