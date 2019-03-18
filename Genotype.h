#ifndef EVO_GENOTYPE_H
#define EVO_GENOTYPE_H


using namespace std;

class Problem;

#include "vector"

class Genotype {
public:
    Genotype();
    Genotype(Problem* pCProblem);
    Genotype(Genotype& ciOther);

    Problem* pCProblem;
    vector<int> viGenotype;


    virtual int iFitnessFunc() = 0;
    virtual Genotype* vAttemptMutation(double iMutProb) = 0;
    virtual vector<Genotype*> vciCrossover(Genotype* ciOther) = 0;

    virtual bool isValidCandidate() = 0;
    virtual Genotype* pciSetToNewRandomCGenotype() = 0;

private:
};
#endif //EVO_GENOTYPE_H
