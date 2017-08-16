/*
 * Cube.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "PlaneWithBoundaries.h"
#include "Vector.h"
#include "Line.h"

#include <iostream>

using namespace std;

class Cube {
public:
	Cube();
	Cube(Vector point1, Vector point2, Vector point3, Vector point4, Vector point5, Vector point6, Vector point7, Vector point8, string color, int number);
	virtual ~Cube();
	Vector getPoint1();
	Vector getPoint2();
	Vector getPoint3();
	Vector getPoint4();
	Vector getPoint5();
	Vector getPoint6();
	Vector getPoint7();
	Vector getPoint8();
	PlaneWithBoundaries getPlane1();
	PlaneWithBoundaries getPlane2();
	PlaneWithBoundaries getPlane3();
	PlaneWithBoundaries getPlane4();
	PlaneWithBoundaries getPlane5();
	PlaneWithBoundaries getPlane6();
	Vector getFirstIntersectionWithCube(Line line);
	int getPlaneLastIntersection();
	bool getActive();
	string getColor();
	int getNumber();
private:
	Vector point1;
	Vector point2;
	Vector point3;
	Vector point4;
	Vector point5;
	Vector point6;
	Vector point7;
	Vector point8;
	PlaneWithBoundaries plane1;
	PlaneWithBoundaries plane2;
	PlaneWithBoundaries plane3;
	PlaneWithBoundaries plane4;
	PlaneWithBoundaries plane5;
	PlaneWithBoundaries plane6;
	int planeLastIntersection;
	bool active;
	string color;
	int number;
};

#endif /* CUBE_H_ */
