/*
 * Display.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Vector.h"

class Display {
public:
	Display();
	Display(double x, double y);
	virtual ~Display();
	double getX();
	double getY();
private:
	double x;
	double y;
};

#endif /* DISPLAY_H_ */
