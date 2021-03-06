/*
 * AiEvolution.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "AiEvolution.h"
#include "EvaluatedCandidate.h"
#include "Valuer.h"
#include "GENE.h"
#include <sys/time.h>

namespace std {
int lenOfGent;

AiEvolution::AiEvolution() {
	// TODO Auto-generated constructor stub
	lenOfGent = 27;
}

AiEvolution::~AiEvolution() {
	// TODO Auto-generated destructor stub
}

static bool first = true;
double getRandom(int max) {
	if (first) {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		struct timespec ts;
		srand(ts.tv_sec);
		first = false;
	}
	return rand() % max;
}

GENE Dotbien(GENE candidate) {
	int type = (int) getRandom(3);
	if (type == 1) {
		double *child = candidate.getGene();
		for (int i = 0; i < (int) 9; i++) {
			double tmp = child[i];
			child[i] = child[lenOfGent - i - 1];
			child[lenOfGent - i - 1] = tmp;
		}
		return candidate;
	} else {
		int genIdx = getRandom(lenOfGent);
		double NST = getRandom(2);
		candidate.getGene()[genIdx] = NST;
		return candidate;
	}
}

GENE getChild(GENE gene, GENE gene2, int dotbienindex) {
	double *NST1 = gene.getGene();
	double *NST2 = gene2.getGene();
	double *child = new double[lenOfGent];
	int randomChild = getRandom(4);
	if (randomChild == 0) {
		for (int i = 0; i < lenOfGent; i++) {
			if (i > 8) {
				child[i] = NST1[i];
			} else {
				child[i] = NST2[i];
			}
		}
	} else if (randomChild == 1) {
		for (int i = 0; i < lenOfGent; i++) {
			if (i > 8) {
				child[i] = NST2[i];
			} else {
				child[i] = NST1[i];
			}
		}
	} else if (randomChild == 2) {
		for (int i = 0; i < lenOfGent; i++) {
			if (i < 12) {
				child[i] = NST1[i];
			} else {
				child[i] = NST2[i];
			}
		}
	} else if (randomChild == 3) {
		for (int i = 0; i < lenOfGent; i++) {
			if (i < 12) {
				child[i] = NST2[i];
			} else {
				child[i] = NST1[i];
			}
		}
	}
	GENE candidate;
	candidate.setGene(child);
	int db = getRandom(dotbienindex);
	if (db == 1) {
		Dotbien(candidate);
	}
	return candidate;
}

vector<GENE> AiEvolution::getFirstClass(double aver) {
	vector<GENE> rs;
	for (int i = 0; i < aver; i++) {
		GENE gene;
		double *g = new double[lenOfGent];
		for (int j = 0; j < lenOfGent; j++) {
			g[j] = getRandom(2);
		}
		gene.setGene(g);
		rs.push_back(gene);
	}
	return rs;
}

vector<EvaluatedCandidate> AiEvolution::value(vector<GENE> part) {
	vector<EvaluatedCandidate> result;
	int size = part.size();
	for (int i = 0; i < size; i++) {
		EvaluatedCandidate ec;
		ec.setCandidate(part.at(i));
		Valuer *v = new Valuer();
		double vl = v->getValue(part.at(i));
		delete v;
		ec.setIndex(vl);
		result.push_back(ec);
	}
	return result;
}

void AiEvolution::Phoingau(vector<GENE>& pop, int dotbienindex,
		int numOfChild2) {
	int size = pop.size();
	for (int i = 0; i < size; i++) {
		int woman = getRandom(size);
		pop.push_back(pop.at(i));
		int numOfChild = getRandom(numOfChild2) + 1;
		for (int c = 0; c < numOfChild; c++) {
			pop.push_back(getChild(pop.at(i), pop.at(woman), dotbienindex));
		}
	}
}

}
/* namespace std */
