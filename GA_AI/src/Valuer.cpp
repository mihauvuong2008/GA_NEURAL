/*
 * Valuer.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include "Valuer.h"
#include <iostream>

namespace std {

Valuer::Valuer() {
	// TODO Auto-generated constructor stub

}

Valuer::~Valuer() {
	// TODO Auto-generated destructor stub
}

double Valuer::getValue(GENE g) {
	int a = 0;
	int b = 0;
	int c = 0;
	int decima = 0;
	for (int i = 0; i < 27; i++) {
		if (i < 9) {
			decima = decima << 1 | (int) g.getGene()[i];
		} else if (i < 18) {
			if (i == 9) {
				a = decima;
				decima = 0;
			}
			decima = decima << 1 | (int) g.getGene()[i];
		} else {
			if (i == 18) {
				b = decima;
				decima = 0;
			}
			decima = decima << 1 | (int) g.getGene()[i];
		}
		c = decima;
	}
//	if (a == 0)
//		return -1;
//	double x = -1 * b / (2 * a);
	return a + b + c; //500 - (a * x * x + b * x + c);
}

int Valuer::decimal(int *array) {
	int decimal = 0;
	int size = 9;
	for (int i = 0; i < size; i++)
		decimal = decimal << 1 | array[i];
	return decimal;
}

int* printBinaryform(int numericalValue) {
	int *bitarray = new int[15];
	for (int i = 0; i < 15; i++) {
		bitarray[i] = numericalValue & 0x1;
		numericalValue = numericalValue >> 1;
	}
	return bitarray;
}

}
/* namespace std */
