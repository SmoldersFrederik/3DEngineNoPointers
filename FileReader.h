/*
 * FileReader.h
 *
 *  Created on: 14 aug. 2017
 *      Author: Frederik Smolders
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <iostream>

using namespace std;

class FileReader {
public:
	FileReader();
	virtual ~FileReader();
	string* getFigure();
	int* getNumber();
	string* getAction();
	int* getPositionX();
	int* getPositionY();
	int* getPositionZ();
	int* getSize();
	string* getColor();



private:
	string figure[10];
	int number[10];
	string action[10];
	int positionX[10];
	int positionY[10];
	int positionZ[10];
	int size[10];
	string color[10];
};

#endif /* FILEREADER_H_ */
