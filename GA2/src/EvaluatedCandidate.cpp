/*
 * EvaluatedCandidate.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include "EvaluatedCandidate.h"
#include "GENE.h"

namespace std {

EvaluatedCandidate::EvaluatedCandidate() {
}

GENE EvaluatedCandidate::getCandidate() {
	return EvaluatedCandidate::candidate;
}

void EvaluatedCandidate::setIndex(double index_) {
	EvaluatedCandidate::index = index_;
}

void EvaluatedCandidate::setCandidate(GENE candidate) {
	EvaluatedCandidate::candidate = candidate;
}

double EvaluatedCandidate::getFitness() {
	return EvaluatedCandidate::index;
}

EvaluatedCandidate::~EvaluatedCandidate() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
