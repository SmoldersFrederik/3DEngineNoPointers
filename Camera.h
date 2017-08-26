/*
 * Camera.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector.h"
#include "Display.h"
#include "Cube.h"
#include "Matrix.h"
#include "Line.h"
#include "Color.h"
#include "FileReader.h"
#include "Sphere.h"

class Camera {
public:
	Camera();
	virtual ~Camera();
	void rayTrace();
	Line getReflectedLineOfSphere(Vector intersection, Line primaryRay, Sphere sphere);
	Line getReflectedLineOfCube(Vector intersection, Line primaryRay, Cube cube);
};

#endif /* CAMERA_H_ */
