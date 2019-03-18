#ifndef EVO_GENETICALGORITHM_H
#define EVO_GENETICALGORITHM_H

#include "vector"
using namespace std;

#include "Problem.h"
#include "Genotype.h"
#include "Individual.h"
#include <iostream>

class GeneticAlgorithm {
public:
    void vRun(int iIterLimit);
    GeneticAlgorithm(int iPopSize, double iCrossProb, double iMutProb, Problem* pckpProblem);
    GeneticAlgorithm(int iPopSize, double iCrossProb, double iMutProb, Problem* pckpProblem, vector<Genotype*> vInitialPopulation);

    int getIPopSize() const;

    vector<Genotype*> vInitialPopulation;


private:
    double iCrossProb;
    double iMutProb;
    int iPopSize;

    Problem* pckpProblem;
    vector<Genotype*> vciPopulation;
    vector<int> viFitnessScoresOfCurrentPopulation;

    void vComputeFitnessScoresOfCurrentPopulation();
    vector<Genotype*> vSelectTwoSolutionsByTournament();

    Genotype* pciGetBestSolution();
};


#endif //EVO_GENETICALGORITHM_H
