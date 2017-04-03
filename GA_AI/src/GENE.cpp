/*
 * GENE.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include "GENE.h"

namespace std {

GENE::GENE() {
}

double * GENE::getGene() {
	return GENE::gene;
}

void GENE::setGene(double gene_[]) {
	gene = gene_;
}

GENE::~GENE() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
