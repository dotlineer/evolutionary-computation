#ifndef EVO_INDIVIDUAL_H
#define EVO_INDIVIDUAL_H


#include "Genotype.h"
#include "KnapsackProblem.h"
#include <iostream>


using namespace std;

class KnapsackProblem;

class Individual : public Genotype {
public:
    Individual();
    Individual(KnapsackProblem *ckp);
    Individual(Individual& ciOther);
    ~Individual();

    KnapsackProblem* ckp;
    int iGenotypeSize;


    int iGetWeightOfItemsInGenotype();

    int iFitnessFunc();
    Genotype* vAttemptMutation(double iMutProb);
    vector<Genotype*> vciCrossover(Genotype *ciOther);

    bool isValidCandidate();
    Genotype* pciSetToNewRandomCGenotype();

    void printIndividual();

private:

};


#endif //EVO_INDIVIDUAL_H
