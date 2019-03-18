#include "Individual.h"


Individual* vGenerateRandomCIndividual(KnapsackProblem* ckp) {
    bool bFoundValidCandidate = false;
    Individual* ciCandidate = NULL;
    while (!bFoundValidCandidate) {
        ciCandidate = new Individual(ckp);
        ciCandidate->pciSetToNewRandomCGenotype();
        if (ciCandidate->isValidCandidate()) {
            bFoundValidCandidate = true;
        }
        else {
            delete ciCandidate;
        }
    }
    return ciCandidate;
}


void initAPopulationOfCInd(KnapsackProblem* pckp, GeneticAlgorithm* pcga) {
    for (int i=0; i<pcga->getIPopSize(); i++) {
        pcga->vInitialPopulation.push_back(vGenerateRandomCIndividual(pckp));
    }
}
