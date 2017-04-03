/*
 * Valuer.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include "Valuer.h"

namespace std {

Valuer::Valuer() {
	// TODO Auto-generated constructor stub

}

Valuer::~Valuer() {
	// TODO Auto-generated destructor stub
}

double Valuer::getValue(GENE g) {
	double rs = g.getGene()[0] + g.getGene()[1];
	return rs;
}
}
/* namespace std */
