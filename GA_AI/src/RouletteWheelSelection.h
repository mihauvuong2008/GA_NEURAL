/*
 * RouletteWheelSelection.h
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#ifndef AI_GA_WHEEL_ROULETTEWHEELSELECTION_H_
#define AI_GA_WHEEL_ROULETTEWHEELSELECTION_H_
#include <vector>  //for std::vector
#include <functional>
#include <string>
#include "GENE.h"
#include "EvaluatedCandidate.h"

namespace std {

class RouletteWheelSelection {
public:
	RouletteWheelSelection();
	vector<GENE> select(vector<EvaluatedCandidate> population,
			bool naturalFitnessScores, int selectionSize);
	string toString();
	double fRand(double fMin, double fMax);
	int WHEEL_BinnarySearch(double ele, double *arr, int size);
	virtual ~RouletteWheelSelection();
private:
};
} /* namespace std */

#endif /* AI_GA_WHEEL_ROULETTEWHEELSELECTION_H_ */
