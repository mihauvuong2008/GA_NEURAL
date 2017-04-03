//============================================================================
// Name        : GA_AI.cpp
// Author      : ngocdong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <climits>
#include <vector>
#include "GENE.h"
#include "RouletteWheelSelection.h"
#include "AiEvolution.h"
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <cstdio>
int Size = 500;

using namespace std;

static bool first = true;
double getRandom(int max) {
	if (first) {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		srand(tv.tv_sec);
		first = false;
	}
	return rand() % max; // min =0;
}

int decimal(int *array) {
	int decimal = 0;
	int size = 9;
	for (int i = 0; i < size; i++) {
		decimal = decimal << 1 | array[i];
	}
	return decimal;
}

void printGene(GENE g) {

	int *bin1 = new int[9];
	int *bin2 = new int[9];
	int *bin3 = new int[9];
	for (int i = 0; i < 27; i++) {
		if (i < 9) {
			bin1[i] = g.getGene()[i];
		} else if (i < 18) {
			bin2[i % 9] = g.getGene()[i];
		} else {
			bin3[i % 9] = g.getGene()[i];
		}
	}
	int a = decimal(bin1);
	int b = decimal(bin2);
	int c = decimal(bin3);
	cout << " a: " << a << ", b: " << b << ", c: " << c << endl;
}

int main() {
	vector<GENE> result;
	RouletteWheelSelection *r = new RouletteWheelSelection();
	AiEvolution AiE;
	result = AiE.getFirstClass(500.0);
	int i = 0;
	vector<EvaluatedCandidate> *ecl;
	while (i < 100 && !false) {
		int size = getRandom(500) + 1000;
		cout << "LOOP: i: " << i << " -- Size: " << size << " -- " << endl; // prints !!!Hello World!!!
		//vector<EvaluatedCandidate> ecl;
		ecl = new vector<EvaluatedCandidate>();
		*ecl = AiE.value(result);
		result = r->select(*ecl, true, size);
		AiE.Phoingau(result, 4, 4);
		i++;
	}
	delete ecl;
	vector<EvaluatedCandidate> final;
	final = AiE.value(result);
	int size = final.size();
	int Max = 0;
	EvaluatedCandidate rs;
	for (int i = 0; i < size; i++) {
		if (final.at(i).getFitness() >= Max) {
			rs = final.at(i);
			Max = final.at(i).getFitness();
		}
	}
	printf("best GENE: ");
	for (int i = 0; i < 27; i++) {
		cout << rs.getCandidate().getGene()[i];
	}
	printGene(rs.getCandidate());
	printf("Waiting for SIGINT. Press Ctrl+C to exit.\n");
	delete r;

}
