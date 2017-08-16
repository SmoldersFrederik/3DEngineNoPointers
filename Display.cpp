/*
 * Display.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Display.h"

Display::Display() {
	// TODO Auto-generated constructor stub

}

Display::Display(double x, double y) {
	this->x = x;
	this->y = y;
}

Display::~Display() {
	// TODO Auto-generated destructor stub
}

double Display::getX() {
	return x;
}

double Display::getY() {
	return y;
}

