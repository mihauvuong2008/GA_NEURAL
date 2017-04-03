/*
 * Valuer.h
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include "GENE.h"

#ifndef AI_GA_VALUER_H_
#define AI_GA_VALUER_H_

namespace std {

class Valuer {
public:
	Valuer();
	virtual ~Valuer();
	double getValue(GENE g);
};

} /* namespace std */

#endif /* AI_GA_VALUER_H_ */
