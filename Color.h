/*
 * Color.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
	Color();
	Color(double H, double S, double V);
	virtual ~Color();
	void ConvertHSVtoRGB();
	void setHSV(double H, double S, double V);
	double getR();
	double getG();
	double getB();
private:
	double H, S, V;
	double R, G, B;
};

#endif /* COLOR_H_ */
