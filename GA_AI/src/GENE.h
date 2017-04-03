/*
 * GENE.h
 *
 *  Created on: Feb 21, 2017
 *      Author: NgocDong
 */

#ifndef AI_GA_CANDIDATE_GENE_H_
#define AI_GA_CANDIDATE_GENE_H_

namespace std {

class GENE {
public:
	GENE();
	virtual ~GENE();
	double * getGene();
	void setGene(double[]);

private:
	double *gene;

};

} /* namespace std */

#endif /* AI_GA_CANDIDATE_GENE_H_ */
