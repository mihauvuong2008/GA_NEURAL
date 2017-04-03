/*
 * EvaluatedCandidate.h
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#ifndef AI_GA_CANDIDATE_EVALUATEDCANDIDATE_H_
#define AI_GA_CANDIDATE_EVALUATEDCANDIDATE_H_

#include "GENE.h"

namespace std {

class EvaluatedCandidate {
public:
	EvaluatedCandidate();
	virtual ~EvaluatedCandidate();
	void setCandidate(GENE candidate_);
	GENE getCandidate();
	void setIndex(double index_);
	double getFitness();
	GENE candidate;
	double index = 0;
};

} /* namespace std */

#endif /* AI_GA_CANDIDATE_EVALUATEDCANDIDATE_H_ */
