/*
 * RouletteWheelSelection.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include "RouletteWheelSelection.h"
#include <stdio.h>
#include <climits>
#include <string>
#include "GENE.h"
#include "EvaluatedCandidate.h"
#include <cstdlib>//random

namespace std {

RouletteWheelSelection::RouletteWheelSelection() {

}

int RouletteWheelSelection::WHEEL_BinnarySearch(double ele, double *arr, int size) {
	int t = INT_MAX;
	int idx = 0;
	for (int i = 0; i < size; i++) {
		if (ele <= arr[i]) {
			if (arr[i] <= t) {
				idx = i;
				t = arr[i];
			}
		}
	}
	return idx;
}

double getAdjustedFitness(double rawFitness, bool naturalFitness) {
	if (naturalFitness) {
		return rawFitness;
	} else {
		if (rawFitness == 0) {
			return 100000000;
		} else {
			return ((double) (1 / (rawFitness)));
		}
	}
}

string toString() {
	return "Roulette Wheel Selection";
}

double RouletteWheelSelection::fRand(double fMin, double fMax) {
	double f = (double) rand() / 32767;
	return fMin + f * (fMax - fMin);
}

vector<GENE> RouletteWheelSelection::select(
		vector<EvaluatedCandidate> population, bool naturalFitnessScores,
		int selectionSize) {
	int popSize = (int) population.size();
	double cumulativeFitnesses[popSize];
	cumulativeFitnesses[0] = getAdjustedFitness(population.at(0).getFitness(),
			naturalFitnessScores);
	for (int i = 1; i < popSize; i++) {
		double fitness = getAdjustedFitness(population.at(i).getFitness(),
				naturalFitnessScores);
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
	delete this;
}

} /* namespace std */
