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






/*
	//Vector eye(320, 240 ,500, 1);
	Vector eye(500, 400 ,1000, 1);
	//Vector lookTo(320, 240, 0, 1);
	Vector up_vec(0, 1, 0, 1);
	//double screen_distance = 500;
	double screen_distance = 500;
	//Display display(640, 480);
	Display display(1000, 800);
*/


	FileReader filereader;
	string* figure = filereader.getFigure();
	int* number = filereader.getNumber();
	string* action = filereader.getAction();
	int* positionX = filereader.getPositionX();
	int* positionY = filereader.getPositionY();
	int* positionZ = filereader.getPositionZ();
	int* size = filereader.getSize();

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
			Cube cube(point[0], point[0+1], point[0+2], point[0+3], point[0+4], point[0+5], point[0+6], point[0+7]);
			cubes.push_back(cube);
		}
		if (figure[i] == "sphere") {
			sphereMiddle.setX(positionX[i]);
			sphereMiddle.setY(positionY[i]);
			sphereMiddle.setZ(positionZ[i]);
			sphereMiddle.setDot(1);
			Sphere sphere(size[i]/2, sphereMiddle);
			spheres.push_back(sphere);
		}
	}

/*
	Line primaryRay;			// line from pixel to eye
	primaryRay.setPointB(eye);
	Vector pixel(0, 0, 0, 1);			// the current pixel of the screen
	Vector right_vec;						// pixel that points to the right side of the eye
	Vector direction_vec;					// direction from the eye to current pixel of the screen
	Vector image_point;					// the pixel of the screen in 3d
	double normalized_x;
	double normalized_y;
*/
	Color color;


	Vector intersectionWithCube;
	Vector intersectionWithCube0;
	Vector intersectionWithCube1;
	Vector intersectionWithCube2;
	Vector intersectionWithCube3;
	Vector intersectionWithCube4;

	Vector intersectionWithSphere;

	//vector<Vector> intersectionWithCube;


	/*
	for (int x = 0; x < display.getX(); x++) {
		pixel.setX(x);
		for (int y = 0; y < display.getY(); y++) {
			pixel.setY(y);
			direction_vec = pixel.substractWithVector(eye);
			direction_vec.normalize();
			right_vec = direction_vec.crossProductWithVector(up_vec);
			normalized_x = (x / display.getX()) - 0.5;
			normalized_y = (y / display.getY()) - 0.5;
			image_point = right_vec.multiplyWithValue(normalized_x).sumWithVector(up_vec.multiplyWithValue(normalized_y).sumWithVector(eye.sumWithVector(direction_vec)));
			primaryRay.setPointA(image_point);

			for (int i = 0; i < cubes.size(); i++) {
				intersectionWithCube = cubes[i].getFirstIntersectionWithCube(primaryRay);
				if (intersectionWithCube.getDot() != 1000) {
					color.setHSV(180, 1, 1);
					glColor3f(color.getR(), color.getG(), color.getB());
					glVertex2i(x, y);
				}
			}

			for (int i = 0; i < spheres.size(); i++) {
				intersectionWithSphere = spheres[i].getFirstIntersectionWithSphere(primaryRay);
				if (intersectionWithSphere.getDot() != 1000) {
					color.setHSV(180, 1, 1);
					glColor3f(color.getR(), color.getG(), color.getB());
					glVertex2i(x, y);
				}
			}
		}
	}
	*/

	Line primaryRay;
	primaryRay.setPointB(camera_position_vec);
	Vector right_vec = direction_vec.crossProductWithVector(up_vec);
	for (int y = 0; y < display.getY(); y++) {
		for (int x = 0; x < display.getX(); x++) {
			Vector P_3d_y = up_vec.multiplyWithValue(-(y - (display.getY() / 2)));
			Vector P_3d_x = right_vec.multiplyWithValue(x - (display.getX() / 2));
			Vector P_3d = camera_position_vec.sumWithVector(direction_vec.multiplyWithValue(screen_distance)).sumWithVector(P_3d_y).sumWithVector(P_3d_x);
			primaryRay.setPointA(P_3d);

			for (int i = 0; i < cubes.size(); i++) {
				intersectionWithCube = cubes[i].getFirstIntersectionWithCube(primaryRay);
				if (intersectionWithCube.getDot() != 1000) {
					color.setHSV(180, 1, 1);
					cout << "Cube\n";
					glColor3f(color.getR(), color.getG(), color.getB());
					glVertex2i(x, y);
				}
			}

			for (int i = 0; i < spheres.size(); i++) {
				intersectionWithSphere = spheres[i].getFirstIntersectionWithSphere(primaryRay);
				if (intersectionWithSphere.getDot() != 1000) {
					color.setHSV(180, 1, 1);
					cout << "Sphere\n";
					glColor3f(color.getR(), color.getG(), color.getB());
					glVertex2i(x, y);
				}
			}
		}
	}

}

