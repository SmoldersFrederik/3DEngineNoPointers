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
	//Vector camera_position_vec(-1500, 0, 300, 1);
	Vector camera_position_vec(500, 400, 1000, 1);
	//Vector camera_position_vec(1000, 500, 0, 1);
	Vector up_vec(0, 1, 0, 1);
	double screen_distance = 500;
	Vector look_at(0, 0, 0, 1);
	Vector direction_vec = look_at.substractWithVector(camera_position_vec);
	direction_vec.normalize();
	Display display(1000, 800);
	Vector light_point(-1000, 2000, -400, 1);


	FileReader filereader;
	string* figure = filereader.getFigure();
	int* number = filereader.getNumber();
	string* action = filereader.getAction();
	int* positionX = filereader.getPositionX();
	int* positionY = filereader.getPositionY();
	int* positionZ = filereader.getPositionZ();
	int* size = filereader.getSize();
	string* color = filereader.getColor();
	int* translationDegrees = filereader.getTranslationDegrees();
	int* transformX = filereader.getTransformX();
	int* transformY = filereader.getTransformY();
	int* transformZ = filereader.getTransformZ();

	Vector point[8];
	Vector sphereMiddle;

	vector<Cube> cubes;
	vector<Sphere> spheres;

	for (int i = 0; i < 10; i++) {
		if (figure[i] == "cube") {
			if (action[i] == "define") {
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
			else if (action[i] == "translate") {
				for (int j = 0; j < 10; j++) {
					if ((number[i] == number[j]) &&  (action[j] == "define")) {
						Matrix xRollMatrix;
						Matrix yRollMatrix;
						Matrix zRollMatrix;
						Matrix translationMatrix;
						xRollMatrix.xRollMatrix(translationDegrees[i]);
						yRollMatrix.yRollMatrix(translationDegrees[i]);
						zRollMatrix.zRollMatrix(translationDegrees[i]);
						translationMatrix.translationMatrix(transformX[i], transformY[i], transformZ[i]);

						point[0].setValues(positionX[j] - size[j]/2, positionY[j] + size[j]/2, positionZ[j] + size[j]/2, 1);
						point[0+1].setValues(positionX[j] + size[j]/2, positionY[j] + size[j]/2, positionZ[j] + size[j]/2, 1);
						point[0+2].setValues(positionX[j] - size[j]/2, positionY[j] - size[j]/2, positionZ[j] + size[j]/2, 1);
						point[0+3].setValues(positionX[j] + size[j]/2, positionY[j] - size[j]/2, positionZ[j] + size[j]/2, 1);
						point[0+4].setValues(positionX[j] - size[j]/2, positionY[j] + size[j]/2, positionZ[j] - size[j]/2, 1);
						point[0+5].setValues(positionX[j] + size[j]/2, positionY[j] + size[j]/2, positionZ[j] - size[j]/2, 1);
						point[0+6].setValues(positionX[j] - size[j]/2, positionY[j] - size[j]/2, positionZ[j] - size[j]/2, 1);
						point[0+7].setValues(positionX[j] + size[j]/2, positionY[j] - size[j]/2, positionZ[j] - size[j]/2, 1);

						point[0] = xRollMatrix.transformVector(point[0]);
						point[0+1] = xRollMatrix.transformVector(point[0+1]);
						point[0+2] = xRollMatrix.transformVector(point[0+2]);
						point[0+3] = xRollMatrix.transformVector(point[0+3]);
						point[0+4] = xRollMatrix.transformVector(point[0+4]);
						point[0+5] = xRollMatrix.transformVector(point[0+5]);
						point[0+6] = xRollMatrix.transformVector(point[0+6]);
						point[0+7] = xRollMatrix.transformVector(point[0+7]);

						point[0] = yRollMatrix.transformVector(point[0]);
						point[0+1] = yRollMatrix.transformVector(point[0+1]);
						point[0+2] = yRollMatrix.transformVector(point[0+2]);
						point[0+3] = yRollMatrix.transformVector(point[0+3]);
						point[0+4] = yRollMatrix.transformVector(point[0+4]);
						point[0+5] = yRollMatrix.transformVector(point[0+5]);
						point[0+6] = yRollMatrix.transformVector(point[0+6]);
						point[0+7] = yRollMatrix.transformVector(point[0+7]);

						point[0] = zRollMatrix.transformVector(point[0]);
						point[0+1] = zRollMatrix.transformVector(point[0+1]);
						point[0+2] = zRollMatrix.transformVector(point[0+2]);
						point[0+3] = zRollMatrix.transformVector(point[0+3]);
						point[0+4] = zRollMatrix.transformVector(point[0+4]);
						point[0+5] = zRollMatrix.transformVector(point[0+5]);
						point[0+6] = zRollMatrix.transformVector(point[0+6]);
						point[0+7] = zRollMatrix.transformVector(point[0+7]);

						point[0] = translationMatrix.transformVector(point[0]);
						point[0+1] = translationMatrix.transformVector(point[0+1]);
						point[0+2] = translationMatrix.transformVector(point[0+2]);
						point[0+3] = translationMatrix.transformVector(point[0+3]);
						point[0+4] = translationMatrix.transformVector(point[0+4]);
						point[0+5] = translationMatrix.transformVector(point[0+5]);
						point[0+6] = translationMatrix.transformVector(point[0+6]);
						point[0+7] = translationMatrix.transformVector(point[0+7]);

						for (unsigned int k = 0; k < cubes.size(); k++) {
							if (cubes[k].getNumber() == number[i]) {
								cubes.erase(cubes.begin() + k);
							}
						}

						Cube cube(point[0], point[0+1], point[0+2], point[0+3], point[0+4], point[0+5], point[0+6], point[0+7], color[j], number[j]);
						cubes.push_back(cube);
					}
				}
			}
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
	Vector intersectionWithSphere;

	Vector intersections[10];
	vector<int> objectsFound;
	double distanceToEye = 0;
	int objectClosestIntersection = -1000;

	double closestIntersection = 0;
	double farestIntersection = 0;
	double differenceFarestClosestIntersection = 0;


	Vector validIntersection;
	Vector firstIntersectionShadowRay;
	int intersectionPlane;
	int intersectionPlaneShadowRay;
	Line shadowRay;
	shadowRay.setPointB(light_point);
	Vector intersectionBetweenLightAndObject;


	Line primaryRay;
	primaryRay.setPointB(camera_position_vec);
	Vector right_vec = direction_vec.crossProductWithVector(up_vec);
	for (int y = 0; y < display.getY(); y++) {
		for (int x = 0; x < display.getX(); x++) {
			Vector P_3d_y = up_vec.multiplyWithValue(y - (display.getY() / 2));
			Vector P_3d_x = right_vec.multiplyWithValue(x - (display.getX() / 2));
			Vector P_3d = camera_position_vec.sumWithVector(direction_vec.multiplyWithValue(screen_distance)).sumWithVector(P_3d_y).sumWithVector(P_3d_x);
			primaryRay.setPointA(P_3d);

			for (unsigned int i = 0; i < cubes.size(); i++) {
				intersectionWithCube = cubes[i].getFirstIntersectionWithCube(primaryRay);
				if (intersectionWithCube.getDot() != 1000) {
					if (intersectionWithCube.distanceToPoint(light_point) > farestIntersection || farestIntersection == 0) {
						farestIntersection = intersectionWithCube.distanceToPoint(light_point);
					}
					if (intersectionWithCube.distanceToPoint(light_point) < closestIntersection || closestIntersection == 0) {
						closestIntersection = intersectionWithCube.distanceToPoint(light_point);
					}
				}
			}
			for (unsigned int i = 0; i < spheres.size(); i++) {
				intersectionWithSphere = spheres[i].getFirstIntersectionWithSphere2(primaryRay);
				if (intersectionWithSphere.getDot() != 1000) {
					if (intersectionWithSphere.distanceToPoint(light_point) > farestIntersection || farestIntersection == 0) {
						farestIntersection = intersectionWithSphere.distanceToPoint(light_point);
					}
					if (intersectionWithSphere.distanceToPoint(light_point) < closestIntersection || closestIntersection == 0) {
						closestIntersection = intersectionWithSphere.distanceToPoint(light_point);
					}
				}
			}
			differenceFarestClosestIntersection = farestIntersection - closestIntersection;
		}
	}

	for (int y = 0; y < display.getY(); y++) {
		for (int x = 0; x < display.getX(); x++) {
			Vector P_3d_y = up_vec.multiplyWithValue(y - (display.getY() / 2));
			Vector P_3d_x = right_vec.multiplyWithValue(x - (display.getX() / 2));
			Vector P_3d = camera_position_vec.sumWithVector(direction_vec.multiplyWithValue(screen_distance)).sumWithVector(P_3d_y).sumWithVector(P_3d_x);
			primaryRay.setPointA(P_3d);

			for (unsigned int i = 0; i < cubes.size(); i++) {
				intersectionWithCube = cubes[i].getFirstIntersectionWithCube(primaryRay);
				if (intersectionWithCube.getDot() != 1000) {
					intersections[cubes[i].getNumber()] = intersectionWithCube;
					objectsFound.push_back(cubes[i].getNumber());
				}
			}
			for (unsigned int i = 0; i < spheres.size(); i++) {
				intersectionWithSphere = spheres[i].getFirstIntersectionWithSphere2(primaryRay);
				if (intersectionWithSphere.getDot() != 1000) {
					intersections[spheres[i].getNumber()] = intersectionWithSphere;
					objectsFound.push_back(spheres[i].getNumber());
				}
			}
			for (unsigned int i = 0; i < objectsFound.size(); i++) {
				if ((intersections[objectsFound[i]].distanceToPoint(camera_position_vec) < distanceToEye) || (distanceToEye == 0)) {
					distanceToEye = intersections[objectsFound[i]].distanceToPoint(camera_position_vec);
					objectClosestIntersection = objectsFound[i];
				}
			}
			if (objectClosestIntersection != -1000) {
				for (unsigned int i = 0; i < cubes.size(); i++) {
					if (objectClosestIntersection == cubes[i].getNumber()) {
						validIntersection = cubes[i].getFirstIntersectionWithCube(primaryRay);
						intersectionPlane = cubes[i].getPlaneLastIntersection();
						shadowRay.setPointA(validIntersection);
						firstIntersectionShadowRay = cubes[i].getFirstIntersectionWithCube(shadowRay);
						intersectionPlaneShadowRay = cubes[i].getPlaneLastIntersection();
						double v;
						if (intersectionPlane == intersectionPlaneShadowRay) {
							bool bool_intersectionBetweenLightAndObject = false;
							for (unsigned int j = 0; j < cubes.size(); j++) {
								if (cubes[i].getNumber() != cubes[j].getNumber()) {
									intersectionBetweenLightAndObject = cubes[j].getFirstIntersectionWithCube(shadowRay);
									if (intersectionBetweenLightAndObject.getDot() != 1000) {
										if (intersectionBetweenLightAndObject.distanceToPoint(light_point) < validIntersection.distanceToPoint(light_point)) {
											bool_intersectionBetweenLightAndObject = true;
											v = 0.4;
										}
										else if (bool_intersectionBetweenLightAndObject == false) {
											v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.4) + 0.6;
										}
									}
									else if (bool_intersectionBetweenLightAndObject == false) {
										v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.4) + 0.6;
									}
								}
								else if (bool_intersectionBetweenLightAndObject == false) {
									v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.4) + 0.6;
								}
							}
							for (unsigned int j = 0; j < spheres.size(); j++) {
								intersectionBetweenLightAndObject = spheres[j].getFirstIntersectionWithSphere2(shadowRay);
								if (intersectionBetweenLightAndObject.getDot() != 1000) {
									if (intersectionBetweenLightAndObject.distanceToPoint(light_point) < validIntersection.distanceToPoint(light_point)) {
										bool_intersectionBetweenLightAndObject = true;
										v = 0.4;
									}
									else if (bool_intersectionBetweenLightAndObject == false) {
										v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.4) + 0.6;
									}
								}
								else if (bool_intersectionBetweenLightAndObject == false) {
									v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.4) + 0.6;
								}
							}
						}
						else {
							v = 0.4;
						}

						if (cubes[i].getColor() == "red") {
							objectColor.setHSV(0, 1, v);
						}
						else if (cubes[i].getColor() == "green") {
							objectColor.setHSV(120, 1, v);
						}
						else if (cubes[i].getColor() == "lightblue") {
							objectColor.setHSV(180, 1, v);
						}
						else if (cubes[i].getColor() == "blue") {
							objectColor.setHSV(251, 1, v);
						}
						else if (cubes[i].getColor() == "yellow") {
							objectColor.setHSV(50, 1, v);
						}
						else if (cubes[i].getColor() == "chrome") {
							vector<int> reflectedObjectsFound;
							double distanceToObject = 0;
							int objectClosestIntersectionReflection = -1000;

							Vector reflectionIntersection;

							Line reflectionRay = getReflectedLineOfCube(validIntersection, primaryRay, cubes[i]);

							for (unsigned int j = 0; j < cubes.size(); j++) {
								if (i != j) {
									intersectionWithCube = cubes[j].getFirstIntersectionWithCube(reflectionRay);
									if (intersectionWithCube.getDot() != 1000) {
										intersections[cubes[j].getNumber()] = intersectionWithCube;
										reflectedObjectsFound.push_back(cubes[j].getNumber());
									}
								}
							}
							for (unsigned int j = 0; j < spheres.size(); j++) {
								intersectionWithSphere = spheres[j].getFirstIntersectionWithSphere2(reflectionRay);
								if (intersectionWithSphere.getDot() != 1000) {
									intersections[spheres[j].getNumber()] = intersectionWithSphere;
									reflectedObjectsFound.push_back(spheres[j].getNumber());
								}
							}
							for (unsigned int j = 0; j < reflectedObjectsFound.size(); j++) {
								if ((intersections[reflectedObjectsFound[j]].distanceToPoint(reflectionRay.getPointB()) < distanceToObject) || (distanceToObject == 0)) {
									distanceToObject = intersections[reflectedObjectsFound[j]].distanceToPoint(reflectionRay.getPointB());
									objectClosestIntersectionReflection = reflectedObjectsFound[j];
								}
							}
							if (objectClosestIntersectionReflection != -1000) {
								for (unsigned int j = 0; j < cubes.size(); j++) {
									if (objectClosestIntersectionReflection == cubes[j].getNumber()) {
										Vector validIntersectionReflectionRay = cubes[j].getFirstIntersectionWithCube(reflectionRay);
										Line oppositeReflectionRay(reflectionRay.getPointB(), validIntersectionReflectionRay);

										if (round(validIntersection.distanceToPoint(validIntersectionReflectionRay)) ==
												round(cubes[i].getFirstIntersectionWithCube(oppositeReflectionRay).distanceToPoint(validIntersectionReflectionRay))) {
											if (cubes[j].getColor() == "red") {
												objectColor.setHSV(0, 1, v);
											}
											else if (cubes[j].getColor() == "green") {
												objectColor.setHSV(120, 1, v);
											}
											else if (cubes[j].getColor() == "lightblue") {
												objectColor.setHSV(180, 1, v);
											}
											else if (cubes[j].getColor() == "blue") {
												objectColor.setHSV(251, 1, v);
											}
											else if (cubes[j].getColor() == "yellow") {
												objectColor.setHSV(50, 1, v);
											}
											else if (cubes[j].getColor() == "chrome") {
												objectColor.setHSV(0, 0, v);
											}
										}
										else {
											objectColor.setHSV(0, 0, v);
										}
									}
								}
								for (unsigned int j = 0; j < spheres.size(); j++) {
									if (objectClosestIntersectionReflection == spheres[j].getNumber()) {
										Vector validIntersectionReflectionRay = spheres[j].getFirstIntersectionWithSphere2(reflectionRay);
										Line oppositeReflectionRay(reflectionRay.getPointB(), validIntersectionReflectionRay);
										if (round(validIntersection.distanceToPoint(validIntersectionReflectionRay)*1) ==
												round(cubes[i].getFirstIntersectionWithCube(oppositeReflectionRay).distanceToPoint(validIntersectionReflectionRay))*1) {
											if (spheres[j].getColor() == "red") {
												objectColor.setHSV(0, 1, v);
											}
											else if (spheres[j].getColor() == "green") {
												objectColor.setHSV(120, 1, v);
											}
											else if (spheres[j].getColor() == "lightblue") {
												objectColor.setHSV(180, 1, v);
											}
											else if (spheres[j].getColor() == "blue") {
												objectColor.setHSV(251, 1, v);
											}
											else if (spheres[j].getColor() == "yellow") {
												objectColor.setHSV(50, 1, v);
											}
											else if (spheres[j].getColor() == "chrome") {
												objectColor.setHSV(0, 0, v);
											}
										}
										else {
											objectColor.setHSV(0, 0, v);
										}
									}
								}
							}
							else {
								objectColor.setHSV(0, 0, v);
							}

						}
						glColor3f(objectColor.getR(), objectColor.getG(), objectColor.getB());
						glVertex2i(x, y);
					}
				}
				for (unsigned int i = 0; i < spheres.size(); i++) {
					if (objectClosestIntersection == spheres[i].getNumber()) {
						validIntersection = spheres[i].getFirstIntersectionWithSphere2(primaryRay);
						shadowRay.setPointA(validIntersection);
						double v;
						Vector intersectionShadowRay = spheres[i].getFirstIntersectionWithSphere(shadowRay);
						if (round(spheres[i].getFirstIntersectionWithSphere2(shadowRay).distanceToPoint(shadowRay.getPointA())*100) ==
								round(validIntersection.distanceToPoint(shadowRay.getPointA())*100)) {
							bool bool_intersectionBetweenLightAndObject = false;
							for (unsigned int j = 0; j < spheres.size(); j++) {
								if (spheres[i].getNumber() != spheres[j].getNumber()) {
									intersectionBetweenLightAndObject = spheres[j].getFirstIntersectionWithSphere2(shadowRay);
									if (intersectionBetweenLightAndObject.getDot() != 1000) {
										if (intersectionBetweenLightAndObject.distanceToPoint(light_point) < validIntersection.distanceToPoint(light_point)) {
											bool_intersectionBetweenLightAndObject = true;
											v = 0.4;
										}
										else if (bool_intersectionBetweenLightAndObject == false) {
											v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.6) + 0.4;
										}
									}
									else if (bool_intersectionBetweenLightAndObject == false) {
										v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.6) + 0.4;
									}
								}
								else if (bool_intersectionBetweenLightAndObject == false) {
									v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.6) + 0.4;
								}
							}
							for (unsigned int j = 0; j < cubes.size(); j ++) {
								intersectionBetweenLightAndObject = cubes[j].getFirstIntersectionWithCube(shadowRay);
								if (intersectionBetweenLightAndObject.getDot() != 1000) {
									if (intersectionBetweenLightAndObject.distanceToPoint(light_point) < validIntersection.distanceToPoint(light_point)) {
										bool_intersectionBetweenLightAndObject = true;
										v = 0.4;
									}
									else if (bool_intersectionBetweenLightAndObject == false) {
										v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.6) + 0.4;
									}
								}
								else if (bool_intersectionBetweenLightAndObject == false) {
									v = ((1 - ((validIntersection.distanceToPoint(light_point) - closestIntersection) / differenceFarestClosestIntersection)) * 0.6) + 0.4;
								}
							}
						}
						else {
							v = 0.4;
						}
						if (spheres[i].getColor() == "red") {
							objectColor.setHSV(0, 1, v);
						}
						else if (spheres[i].getColor() == "green") {
							objectColor.setHSV(120, 1, v);
						}
						else if (spheres[i].getColor() == "lightblue") {
							objectColor.setHSV(180, 1, v);
						}
						else if (spheres[i].getColor() == "blue") {
							objectColor.setHSV(251, 1, v);
						}
						else if (spheres[i].getColor() == "yellow") {
							objectColor.setHSV(50, 1, v);
						}
						else if (spheres[i].getColor() == "chrome") {
							vector<int> reflectedObjectsFound;
							double distanceToObject = 0;
							int objectClosestIntersectionReflection = -1000;

							Vector reflectionIntersection;

							Line reflectionRay = getReflectedLineOfSphere(validIntersection, primaryRay, spheres[i]);

							for (unsigned int j = 0; j < cubes.size(); j++) {
								intersectionWithCube = cubes[j].getFirstIntersectionWithCube(reflectionRay);
								if (intersectionWithCube.getDot() != 1000) {
									intersections[cubes[j].getNumber()] = intersectionWithCube;
									reflectedObjectsFound.push_back(cubes[j].getNumber());
								}
							}
							for (unsigned int j = 0; j < spheres.size(); j++) {
								if (i != j) {
									intersectionWithSphere = spheres[j].getFirstIntersectionWithSphere2(reflectionRay);
									if (intersectionWithSphere.getDot() != 1000) {
										intersections[spheres[j].getNumber()] = intersectionWithSphere;
										reflectedObjectsFound.push_back(spheres[j].getNumber());
									}
								}
							}
							for (unsigned int j = 0; j < reflectedObjectsFound.size(); j++) {
								if ((intersections[reflectedObjectsFound[j]].distanceToPoint(reflectionRay.getPointB()) < distanceToObject) || (distanceToObject == 0)) {
									distanceToObject = intersections[reflectedObjectsFound[j]].distanceToPoint(reflectionRay.getPointB());
									objectClosestIntersectionReflection = reflectedObjectsFound[j];
								}
							}
							if (objectClosestIntersectionReflection != -1000) {
								for (unsigned int j = 0; j < cubes.size(); j++) {
									if (objectClosestIntersectionReflection == cubes[j].getNumber()) {
										Vector validIntersectionReflectionRay = cubes[j].getFirstIntersectionWithCube(reflectionRay);
										Line oppositeReflectionRay(reflectionRay.getPointB(), validIntersectionReflectionRay);
										if (round(validIntersection.distanceToPoint(validIntersectionReflectionRay)*1) ==
												round(spheres[i].getFirstIntersectionWithSphere2(oppositeReflectionRay).distanceToPoint(validIntersectionReflectionRay))*1) {
											if (cubes[j].getColor() == "red") {
												objectColor.setHSV(0, 1, v);
											}
											else if (cubes[j].getColor() == "green") {
												objectColor.setHSV(120, 1, v);
											}
											else if (cubes[j].getColor() == "lightblue") {
												objectColor.setHSV(180, 1, v);
											}
											else if (cubes[j].getColor() == "blue") {
												objectColor.setHSV(251, 1, v);
											}
											else if (cubes[j].getColor() == "yellow") {
												objectColor.setHSV(50, 1, v);
											}
											else if (cubes[j].getColor() == "chrome") {
												objectColor.setHSV(0, 0, v);
											}
										}
										else {
											objectColor.setHSV(0, 0, v);
										}
									}
								}
								for (unsigned int j = 0; j < spheres.size(); j++) {
									if (objectClosestIntersectionReflection == spheres[j].getNumber()) {
										Vector validIntersectionReflectionRay = spheres[j].getFirstIntersectionWithSphere2(reflectionRay);
										Line oppositeReflectionRay(reflectionRay.getPointB(), validIntersectionReflectionRay);
										if (round(validIntersection.distanceToPoint(validIntersectionReflectionRay)*1) ==
												round(spheres[i].getFirstIntersectionWithSphere2(oppositeReflectionRay).distanceToPoint(validIntersectionReflectionRay))*1) {
											if (spheres[j].getColor() == "red") {
												objectColor.setHSV(0, 1, v);
											}
											else if (spheres[j].getColor() == "green") {
												objectColor.setHSV(120, 1, v);
											}
											else if (spheres[j].getColor() == "lightblue") {
												objectColor.setHSV(180, 1, v);
											}
											else if (spheres[j].getColor() == "blue") {
												objectColor.setHSV(251, 1, v);
											}
											else if (spheres[j].getColor() == "yellow") {
												objectColor.setHSV(50, 1, v);
											}
											else if (spheres[j].getColor() == "chrome") {
												objectColor.setHSV(0, 0, v);
											}
										}
										else {
											objectColor.setHSV(0, 0, v);
										}
									}
								}
							}
							else {
								objectColor.setHSV(0, 0, v);
							}

						}

						glColor3f(objectColor.getR(), objectColor.getG(), objectColor.getB());
						glVertex2i(x, y);
					}
				}
			}
			objectsFound.clear();
			distanceToEye = 0;
			objectClosestIntersection = -1000;
		}
	}
}


Line Camera::getReflectedLineOfSphere(Vector intersection, Line primaryRay, Sphere sphere) {
	Vector normalOfPlane = sphere.getMiddle().substractWithVector(intersection);
	normalOfPlane.normalize();
	//Vector directionVector = primaryRay.getPointB().substractWithVector(intersection);
	Vector directionVector = intersection.substractWithVector(primaryRay.getPointB());
	Vector reflectedVector = directionVector.substractWithVector(normalOfPlane.multiplyWithValue(2 * directionVector.dotProductWithVector(normalOfPlane)));
	Line reflectedLine(intersection.sumWithVector(reflectedVector), intersection);
	return reflectedLine;
}


Line Camera::getReflectedLineOfCube(Vector intersection, Line primaryRay, Cube cube) {
	Vector normalOfPlane;
	switch(cube.getPlaneLastIntersection()) {
		case 1:
			normalOfPlane = cube.getPlane1().calculateNormalOfPlane();
			break;
		case 2:
			normalOfPlane = cube.getPlane2().calculateNormalOfPlane();
			break;
		case 3:
			normalOfPlane = cube.getPlane3().calculateNormalOfPlane();
			break;
		case 4:
			normalOfPlane = cube.getPlane4().calculateNormalOfPlane();
			break;
		case 5:
			normalOfPlane = cube.getPlane5().calculateNormalOfPlane();
			break;
		case 6:
			normalOfPlane = cube.getPlane6().calculateNormalOfPlane();
			break;
	}
	normalOfPlane.normalize();
	//Vector directionVector = primaryRay.getPointB().substractWithVector(intersection);
	Vector directionVector = intersection.substractWithVector(primaryRay.getPointB());
	Vector reflectedVector = directionVector.substractWithVector(normalOfPlane.multiplyWithValue(2 * directionVector.dotProductWithVector(normalOfPlane)));
	Line reflectedLine(intersection.sumWithVector(reflectedVector), intersection);
	return reflectedLine;
}

