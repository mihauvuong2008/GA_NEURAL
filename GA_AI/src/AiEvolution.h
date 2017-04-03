/*
 * AiEvolution.h
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#ifndef AI_GA_AIEVOLUTION_H_
#define AI_GA_AIEVOLUTION_H_
#include <vector>
using namespace std;
#include "GENE.h"
#include "EvaluatedCandidate.h"

namespace std {
class AiEvolution {
public:
	AiEvolution();
	void Phoingau(std::vector<GENE>& pop, int dotbienindex, int numOfChild2);
	vector<GENE> getFirstClass(double aver);
	vector<EvaluatedCandidate> value(vector<GENE> part);
	virtual ~AiEvolution();
};

} /* namespace std */

#endif /* AI_GA_AIEVOLUTION_H_ */
