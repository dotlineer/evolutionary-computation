#include "Individual.h"

int Individual::iFitnessFunc() {
    int iScore = 0;
    for (int i=0; i<viGenotype.size(); i++) {
        iScore += viGenotype.at(i) * ckp->getViValues().at(i);
    }
    return iScore;
}


vector<Genotype *> Individual::vciCrossover(Genotype *ciOther) {
    int iGenotypeLength = this->viGenotype.size();

    Individual* pciNewFirstIndividual = new Individual(this->ckp);
    Individual* pciNewSecondIndividual = new Individual(this->ckp);

    bool bCrossoverResultsAreTwoValidCandidates = false;
    int iMaxAttemptsToGetACorrectCrossoverAllowed = 20;
    int iAttemptsToGetACorrectCrossoverAllowed = 0;

    while (!bCrossoverResultsAreTwoValidCandidates && iAttemptsToGetACorrectCrossoverAllowed < iMaxAttemptsToGetACorrectCrossoverAllowed) {
        int dRandomNum = ((double)rand()) / RAND_MAX * (iGenotypeLength-1); // indeks po ktorym nastepuje przeciecie. np. dla 4elementowego genotypu przyjmuje wartosci 0, 1, 2

        for (int i=0; i<=dRandomNum; i++) {
            pciNewFirstIndividual->viGenotype.at(i) = this->viGenotype.at(i);
            pciNewSecondIndividual->viGenotype.at(i) = ciOther->viGenotype.at(i);
        }

        for (int i=dRandomNum + 1; i<iGenotypeLength; i++) {
            pciNewFirstIndividual->viGenotype.at(i) = ciOther->viGenotype.at(i);
            pciNewSecondIndividual->viGenotype.at(i) = this->viGenotype.at(i);
        }

        if (pciNewFirstIndividual->isValidCandidate() && pciNewSecondIndividual->isValidCandidate()) {
            bCrossoverResultsAreTwoValidCandidates = true;
        };

        iAttemptsToGetACorrectCrossoverAllowed++;
    }

    vector<Genotype*> vResult(2);
    if (bCrossoverResultsAreTwoValidCandidates) {
        vResult.at(0) = pciNewFirstIndividual;
        vResult.at(1) = pciNewSecondIndividual;
    }
    else {
        vResult.at(0) = new Individual(*this);
        vResult.at(1) = new Individual(*((Individual*)ciOther));
        delete pciNewFirstIndividual;
        delete pciNewSecondIndividual;
    }

    return vResult;
}


Individual::Individual() {

}


Genotype* Individual::vAttemptMutation(double iMutProb) {
    bool bMutatedIndividualIsAValidCandidate = false;
    int iMaxNumberOfMutationAttempts = 10;
    int iNumberOfMutationAttempts = 0;

    Individual* pciCopyOfCurrentIndividual;

    while (!bMutatedIndividualIsAValidCandidate && iNumberOfMutationAttempts < iMaxNumberOfMutationAttempts) {
        pciCopyOfCurrentIndividual = new Individual(*this);

        for (int i=0; i<pciCopyOfCurrentIndividual->viGenotype.size(); i++) {
            double dMutateCurrentGene = ((double)rand()) / RAND_MAX;
            if (dMutateCurrentGene < iMutProb) {
                if (pciCopyOfCurrentIndividual->viGenotype.at(i) == 0) pciCopyOfCurrentIndividual->viGenotype.at(i) = 1;
                else pciCopyOfCurrentIndividual->viGenotype.at(i) = 0;
            }
        }

        if (pciCopyOfCurrentIndividual->isValidCandidate()) {
            bMutatedIndividualIsAValidCandidate = true;
        }
        else {
            delete pciCopyOfCurrentIndividual;
        }
        iNumberOfMutationAttempts++;
    }

    if (bMutatedIndividualIsAValidCandidate) {
        return pciCopyOfCurrentIndividual;
    }
    else {
        pciCopyOfCurrentIndividual = new Individual(*this);
        return pciCopyOfCurrentIndividual;
    }
}


Genotype* Individual::pciSetToNewRandomCGenotype() {
    for (int i=0; i < iGenotypeSize; i++) {
        int iGeneValue = (int)((((double)rand()) / RAND_MAX) * 2);
        viGenotype.at(i) = iGeneValue;
    }
}


Individual::Individual(KnapsackProblem *ckp) : ckp(ckp) {
    iGenotypeSize = ckp->getViSizes().size();
    viGenotype = vector<int>(iGenotypeSize);
}


bool Individual::isValidCandidate() {
    return iGetWeightOfItemsInGenotype() <= ckp->getIWeightLimit();
}


Individual::Individual(Individual &ciOther) {
    this->ckp = ciOther.ckp;
    this->iGenotypeSize = ciOther.iGenotypeSize;
    viGenotype = vector<int>(iGenotypeSize);

    for (int i=0; i<iGenotypeSize; i++) {
        viGenotype.at(i) = ciOther.viGenotype.at(i);
    }
}

int Individual::iGetWeightOfItemsInGenotype() {
    int iWeight = 0;
    for (int i=0; i<viGenotype.size(); i++) {
        iWeight += viGenotype.at(i) * ckp->getViSizes().at(i);
    }
    return iWeight;
}


void Individual::printIndividual() {
    for (int i : viGenotype) {
        cout << i << " ";
    }
    cout << endl;
}

Individual::~Individual() {

}


