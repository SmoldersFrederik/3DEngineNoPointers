/*
 * FileReader.cpp
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#include "FileReader.h"

#include <fstream>
#include <cmath>
#include <stdlib.h>

FileReader::FileReader() {
	// TODO Auto-generated constructor stub
	string line;
	ifstream myfile ("example2.txt");
	int counter = 0;

	while (getline (myfile, line)) {
		string delimiter = " ";
		size_t pos = 0;
		string token;
		string position;

		pos = line.find(delimiter);
		figure[counter] = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		pos = line.find(delimiter);
		number[counter] = atoi(line.substr(0, pos).c_str());
		line.erase(0, pos + delimiter.length());
		pos = line.find(delimiter);
		action[counter] = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());

		if (action[counter] == "define") {
			pos = line.find(delimiter);
			position = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			delimiter = ":";
			pos = position.find(delimiter);
			position.erase(0, pos + delimiter.length());
			delimiter = ",";
			pos = position.find(delimiter);
			positionX[counter] = atoi(position.substr(0, pos).c_str());
			position.erase(0, pos + delimiter.length());
			pos = position.find(delimiter);
			positionY[counter] = atoi(position.substr(0, pos).c_str());
			position.erase(0, pos + delimiter.length());
			positionZ[counter] = atoi(position.c_str());

			delimiter = " ";
			string sizeLine;
			pos = line.find(delimiter);
			sizeLine = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			delimiter = ":";
			pos = sizeLine.find(delimiter);
			size[counter] = atoi(sizeLine.erase(0, pos + delimiter.length()).c_str());
			color[counter] = line;
		}

		counter++;
	}


}

FileReader::~FileReader() {
	// TODO Auto-generated destructor stub
}

string* FileReader::getFigure() {
	return figure;
}

int* FileReader::getNumber() {
	return number;
}

string* FileReader::getAction() {
	return action;
}

int* FileReader::getPositionX() {
	return positionX;
}

int* FileReader::getPositionY() {
	return positionY;
}

int* FileReader::getPositionZ() {
	return positionZ;
}

int* FileReader::getSize() {
	return size;
}

string* FileReader::getColor() {
	return color;
}
