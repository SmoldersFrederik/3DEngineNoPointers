/*
 * Color.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "Color.h"

#include <stdlib.h>

Color::Color() {
	// TODO Auto-generated constructor stub

}

Color::Color(double H, double S, double V) {
	this->H = H;
	this->S = S;
	this->V = V;
	ConvertHSVtoRGB();

}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

void Color::ConvertHSVtoRGB() {
	double C = V * S;
	double X = C * (1 - abs(((int)(H/60))%2 - 1));
	double m = V - C;
	double R_, G_, B_;

	if (H >= 0 && H < 60) {
		R_ = C;
		G_ = X;
		B_ = 0;
	}
	else if (H >= 60 && H < 120) {
		R_ = X;
		G_ = C;
		B_ = 0;
	}
	else if (H >= 120 && H < 180) {
		R_ = 0;
		G_ = C;
		B_ = X;
	}
	else if (H >= 180 && H < 240) {
		R_ = 0;
		G_ = X;
		B_ = C;
	}
	else if (H >= 240 && H < 300) {
		R_ = X;
		G_ = 0;
		B_ = C;
	}
	else if (H >= 300 && H < 360) {
		R_ = C;
		G_ = 0;
		B_ = X;
	}

	R = (R_ + m);
	G = (G_ + m);
	B = (B_ + m);
}

void Color::setHSV(double H, double S, double V) {
	this->H = H;
	this->S = S;
	this->V = V;
	ConvertHSVtoRGB();
}

double Color::getR() {
	return R;
}

double Color::getG() {
	return G;
}

double Color::getB() {
	return B;
}

