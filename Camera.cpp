/*
 * Camera.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Camera.h"

#include <iostream>
#include <fstream>
#include <GL/Gl.h>
#include <GL/Glu.h>
#include <GL/glut.h>
#include <cmath>
#include <vector>

using namespace std;

Camera::Camera() {
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::rayTrace() {
	Vector camera_position_vec(500, 400, 1000, 1);
	//Vector camera_position_vec(1000, 500, 0, 1);
	Vector up_vec(0, 1, 0, 1);
	double screen_distance = 500;
	Vector look_at(0, 0, 0, 1);
	Vector direction_vec = look_at.substractWithVector(camera_position_vec);
	direction_vec.normalize();
	Display display(1000, 800);


	FileReader filereader;
	string* figure = filereader.getFigure();
	int* number = filereader.getNumber();
	string* action = filereader.getAction();
	int* positionX = filereader.getPositionX();
	int* positionY = filereader.getPositionY();
	int* positionZ = filereader.getPositionZ();
	int* size = filereader.getSize();
	string* color = filereader.getColor();

	Vector point[8];
	Vector sphereMiddle;

	vector<Cube> cubes;
	vector<Sphere> spheres;

	for (int i = 0; i < 10; i++) {
		if (figure[i] == "cube") {
			point[0].setValues(positionX[i] - size[i]/2, positionY[i] + size[i]/2, positionZ[i] + size[i]/2, 1);
			point[0+1].setValues(positionX[i] + size[i]/2, positionY[i] + size[i]/2, positionZ[i] + size[i]/2, 1);
			point[0+2].setValues(positionX[i] - size[i]/2, positionY[i] - size[i]/2, positionZ[i] + size[i]/2, 1);
			point[0+3].setValues(positionX[i] + size[i]/2, positionY[i] - size[i]/2, positionZ[i] + size[i]/2, 1);
			point[0+4].setValues(positionX[i] - size[i]/2, positionY[i] + size[i]/2, positionZ[i] - size[i]/2, 1);
			point[0+5].setValues(positionX[i] + size[i]/2, positionY[i] + size[i]/2, positionZ[i] - size[i]/2, 1);
			point[0+6].setValues(positionX[i] - size[i]/2, positionY[i] - size[i]/2, positionZ[i] - size[i]/2, 1);
			point[0+7].setValues(positionX[i] + size[i]/2, positionY[i] - size[i]/2, positionZ[i] - size[i]/2, 1);
			Cube cube(point[0], point[0+1], point[0+2], point[0+3], point[0+4], point[0+5], point[0+6], point[0+7], color[i], number[i]);
			cubes.push_back(cube);
		}
		if (figure[i] == "sphere") {
			sphereMiddle.setX(positionX[i]);
			sphereMiddle.setY(positionY[i]);
			sphereMiddle.setZ(positionZ[i]);
			sphereMiddle.setDot(1);
			Sphere sphere(size[i]/2, sphereMiddle, color[i], number[i]);
			spheres.push_back(sphere);
		}
	}


	Color objectColor;


	Vector intersectionWithCube;
	Vector intersectionWithCube0;
	Vector intersectionWithCube1;
	Vector intersectionWithCube2;
	Vector intersectionWithCube3;
	Vector intersectionWithCube4;

	Vector intersectionWithSphere;

	Vector intersections[10];
	vector<int> objectsFound;
	double distanceToEye = 0;
	int objectClosestIntersection = 1000;

	//vector<Vector> intersectionWithCube;

	Line primaryRay;
	primaryRay.setPointB(camera_position_vec);
	Vector right_vec = direction_vec.crossProductWithVector(up_vec);
	for (int y = 0; y < display.getY(); y++) {
		for (int x = 0; x < display.getX(); x++) {
			Vector P_3d_y = up_vec.multiplyWithValue(-(y - (display.getY() / 2)));
			Vector P_3d_x = right_vec.multiplyWithValue(x - (display.getX() / 2));
			Vector P_3d = camera_position_vec.sumWithVector(direction_vec.multiplyWithValue(screen_distance)).sumWithVector(P_3d_y).sumWithVector(P_3d_x);
			primaryRay.setPointA(P_3d);
			/*
			for (int i = 0; i < cubes.size(); i++) {
				intersectionWithCube = cubes[i].getFirstIntersectionWithCube(primaryRay);
				if (intersectionWithCube.getDot() != 1000) {
					if (cubes[i].getColor() == "red") {
						objectColor.setHSV(0, 1, 1);
					}
					else if (cubes[i].getColor() == "green") {
						objectColor.setHSV(120, 1, 1);
					}
					else if (cubes[i].getColor() == "lightblue") {
						objectColor.setHSV(180, 1, 1);
					}
					else if (cubes[i].getColor() == "blue") {
						objectColor.setHSV(251, 1, 1);
					}
					else if (cubes[i].getColor() == "yellow") {
						objectColor.setHSV(50, 1, 1);
					}
					//objectColor.setHSV(180, 1, 1);
					glColor3f(objectColor.getR(), objectColor.getG(), objectColor.getB());
					glVertex2i(x, y);
				}
			}

			for (int i = 0; i < spheres.size(); i++) {
				intersectionWithSphere = spheres[i].getFirstIntersectionWithSphere(primaryRay);
				if (intersectionWithSphere.getDot() != 1000) {
					if (spheres[i].getColor() == "red") {
						objectColor.setHSV(0, 1, 1);
					}
					else if (spheres[i].getColor() == "green") {
						objectColor.setHSV(120, 1, 1);
					}
					else if (spheres[i].getColor() == "lightblue") {
						objectColor.setHSV(180, 1, 1);
					}
					else if (spheres[i].getColor() == "blue") {
						objectColor.setHSV(251, 1, 1);
					}
					else if (spheres[i].getColor() == "yellow") {
						objectColor.setHSV(50, 1, 1);
					}
					glColor3f(objectColor.getR(), objectColor.getG(), objectColor.getB());
					glVertex2i(x, y);
				}
			}
			*/
			///*
			for (int i = 0; i < cubes.size(); i++) {
				intersectionWithCube = cubes[i].getFirstIntersectionWithCube(primaryRay);
				if (intersectionWithCube.getDot() != 1000) {
					intersections[cubes[i].getNumber()] = intersectionWithCube;
					objectsFound.push_back(cubes[i].getNumber());
				}
			}
			for (int i = 0; i < spheres.size(); i++) {
				intersectionWithSphere = spheres[i].getFirstIntersectionWithSphere(primaryRay);
				if (intersectionWithSphere.getDot() != 1000) {
					intersections[spheres[i].getNumber()] = intersectionWithSphere;
					objectsFound.push_back(spheres[i].getNumber());
				}
			}
			for (int i = 0; i < objectsFound.size(); i++) {
				if ((intersections[objectsFound[i]].distanceToPoint(camera_position_vec) < distanceToEye) || (distanceToEye == 0)) {
					distanceToEye = intersections[objectsFound[i]].distanceToPoint(camera_position_vec);
					objectClosestIntersection = objectsFound[i];
				}
			}
			if (objectClosestIntersection != 1000) {
				for (int i = 0; i < cubes.size(); i++) {
					if (objectClosestIntersection == cubes[i].getNumber()) {
						if (cubes[i].getColor() == "red") {
							objectColor.setHSV(0, 1, 1);
						}
						else if (cubes[i].getColor() == "green") {
							objectColor.setHSV(120, 1, 1);
						}
						else if (cubes[i].getColor() == "lightblue") {
							objectColor.setHSV(180, 1, 1);
						}
						else if (cubes[i].getColor() == "blue") {
							objectColor.setHSV(251, 1, 1);
						}
						else if (cubes[i].getColor() == "yellow") {
							objectColor.setHSV(50, 1, 1);
						}
						glColor3f(objectColor.getR(), objectColor.getG(), objectColor.getB());
						glVertex2i(x, y);
					}
				}
				for (int i = 0; i < spheres.size(); i++) {
					if (objectClosestIntersection == spheres[i].getNumber()) {
						if (spheres[i].getColor() == "red") {
							objectColor.setHSV(0, 1, 1);
						}
						else if (spheres[i].getColor() == "green") {
							objectColor.setHSV(120, 1, 1);
						}
						else if (spheres[i].getColor() == "lightblue") {
							objectColor.setHSV(180, 1, 1);
						}
						else if (spheres[i].getColor() == "blue") {
							objectColor.setHSV(251, 1, 1);
						}
						else if (spheres[i].getColor() == "yellow") {
							objectColor.setHSV(50, 1, 1);
						}

						glColor3f(objectColor.getR(), objectColor.getG(), objectColor.getB());
						glVertex2i(x, y);
					}
				}
			}
			objectsFound.clear();
			distanceToEye = 0;
			objectClosestIntersection = 1000;
			//*/
		}
	}
}

