/*
 * RouletteWheelSelection.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 *
 */

#include "RouletteWheelSelection.h"
#include <stdio.h>
#include <climits>
#include <limits>
#include <string>
#include "GENE.h"
#include <cstdlib>//random
#include "EvaluatedCandidate.h"
#include <cstdlib>
#include <sys/time.h>

namespace std {

RouletteWheelSelection::RouletteWheelSelection() {

}
static bool first = true;

int RouletteWheelSelection::WHEEL_BinnarySearch(double eleSize, double *arr,
		int size) {
	if (eleSize < arr[0])
		return 0;
	int idx = 0;
//	int center = (int) size / 2;
//	if (eleSize > arr[center]) {
//		for (int i = 0; i < center - 1; i++) {
//			if (eleSize > arr[i]) {
//				idx = i + 1;
//			}
//		}
//	} else {
//		for (int i = center; i < size - 1; i++) {
//			if (eleSize > arr[i]) {
//				idx = i + 1;
//			}
//		}
//	}
	for (int i = 0; i < size - 1; i++) {
		if (eleSize > arr[i]) {
			idx = i + 1;
		}
	}
	return idx;
}

double getAdjustedFitness(double rawFitness, bool naturalFitness) {
	if (naturalFitness) {
		return rawFitness;
	} else {
		if (rawFitness == 0) {
			return std::numeric_limits<double>::infinity();
		} else {
			return ((double) (1 / (rawFitness)));
		}
	}
}

double RouletteWheelSelection::fRand(double fMin, double fMax) {
	if (first) {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		srand((time_t) tv.tv_sec);
		first = false;
	}
	double f = (double) rand() / RAND_MAX;
	double rs = fMin + f * (fMax - fMin);
	return rs;
}

vector<GENE> RouletteWheelSelection::select(
		vector<EvaluatedCandidate> population, bool naturalFitnessScores,
		int selectionSize) {
	int popSize = population.size();
	double cumulativeFitnesses[popSize];
	cumulativeFitnesses[0] = getAdjustedFitness(population.at(0).getFitness(),
			naturalFitnessScores);
	for (int i = 1; i < popSize; i++) {
		double fitness = getAdjustedFitness(population.at(i).getFitness(),
				naturalFitnessScores);
		// tao banh xe
		cumulativeFitnesses[i] = cumulativeFitnesses[i - 1] + fitness;
	}
	if (selectionSize >= popSize)
		selectionSize = popSize;

	vector<GENE> selection;
	for (int i = 0; i < selectionSize; i++) {
		double randomFitness = fRand(1E-5, 1)
				* cumulativeFitnesses[popSize - 1];
		int index = WHEEL_BinnarySearch(randomFitness, cumulativeFitnesses,
				popSize);
		GENE candidate = (GENE) population.at(index).getCandidate();
		selection.push_back(candidate);
	}
	return selection;
}

RouletteWheelSelection::~RouletteWheelSelection() {
// TODO Auto-generated destructor stub
}

} /* namespace std */
