#include "GeneticAlgorithm.h"


void GeneticAlgorithm::vRun(int iIterLimit) {
    vciPopulation = vInitialPopulation;
    iPopSize = vInitialPopulation.size();
    vComputeFitnessScoresOfCurrentPopulation();



    for (int iterNumber = 0; iterNumber < iIterLimit; iterNumber++) {
        vector<Genotype*> vNewPopulation;
        for (int i=0; i<iPopSize/2; i++) {
            vector<Genotype*> vWinners = vSelectTwoSolutionsByTournament();
            vector<Genotype*> vCrossedOverWinners = vWinners.at(0)->vciCrossover(vWinners.at(1));

            vector<Genotype*> vOffspring(2);
            vOffspring.at(0) = vCrossedOverWinners.at(0)->vAttemptMutation(iMutProb);
            vOffspring.at(1) = vCrossedOverWinners.at(1)->vAttemptMutation(iMutProb);

            vNewPopulation.push_back(vOffspring.at(0));
            vNewPopulation.push_back(vOffspring.at(1));

            delete vCrossedOverWinners.at(0);
            delete vCrossedOverWinners.at(1);


        }


        int iRandomIndex = (int)((((double)rand()) / RAND_MAX) * iPopSize);
        int iRandomIndex2 = (int)((((double)rand()) / RAND_MAX) * iPopSize);

        Individual* firstCI = new Individual(*(Individual*)vciPopulation.at(iRandomIndex));
        Individual* secondCI = new Individual(*(Individual*)vciPopulation.at(iRandomIndex2));
        vector<Genotype*> newCrossedOverVector = firstCI->vciCrossover(secondCI);
        Individual* firstCrossedOver = (Individual*) newCrossedOverVector.at(0);
        Individual* secondCrossedOver = (Individual*) newCrossedOverVector.at(1);

        vNewPopulation.push_back(firstCrossedOver);
        vNewPopulation.push_back(secondCrossedOver);

        iPopSize += 2;


        for (int i=0; i<vciPopulation.size(); i++) delete vciPopulation.at(i);
        vciPopulation = vNewPopulation;

        cout << "After, iPopSize= " << iPopSize << endl;
        cout << "After, vciPopulation.size()= " << vciPopulation.size() << endl;

        vComputeFitnessScoresOfCurrentPopulation();

    }


    Genotype* pciBestSolution = pciGetBestSolution();
    cout << "Best solution value: " << pciBestSolution->iFitnessFunc() << endl;
}



GeneticAlgorithm::GeneticAlgorithm(int iPopSize, double iCrossProb, double iMutProb, Problem* pckpProblem) {
    this->iPopSize = iPopSize;
    this->iCrossProb = iCrossProb;
    this->iMutProb = iMutProb;
    this->pckpProblem = pckpProblem;
    viFitnessScoresOfCurrentPopulation = vector<int>(iPopSize);
}

GeneticAlgorithm::GeneticAlgorithm(int iPopSize, double iCrossProb, double iMutProb, Problem* pckpProblem, vector<Genotype*> vInitialPopulation) {
    this->iPopSize = iPopSize;
    this->iCrossProb = iCrossProb;
    this->iMutProb = iMutProb;
    this->pckpProblem = pckpProblem;
    viFitnessScoresOfCurrentPopulation = vector<int>(iPopSize);
    this->vInitialPopulation = vInitialPopulation;
}

void GeneticAlgorithm::vComputeFitnessScoresOfCurrentPopulation() {
    viFitnessScoresOfCurrentPopulation = vector<int>(iPopSize);
    for (int i=0; i<iPopSize; i++) {
        viFitnessScoresOfCurrentPopulation.at(i) = vciPopulation.at(i)->iFitnessFunc();
    }
}

vector<Genotype*> GeneticAlgorithm::vSelectTwoSolutionsByTournament() {
    vector<Genotype*> vciSelectedCGenotypes(2);

    int iTour1FirstCGenotypeIndex = (int)((((double)rand()) / RAND_MAX) * iPopSize);
    int iTour1SecondCGenotypeIndex = (int)((((double)rand()) / RAND_MAX) * iPopSize);

    Genotype* vc11 = vciPopulation.at(iTour1FirstCGenotypeIndex);
    Genotype* vc12 = vciPopulation.at(iTour1SecondCGenotypeIndex);

    if (vc11->iFitnessFunc() >= vc12->iFitnessFunc()) vciSelectedCGenotypes.at(0) = vc11;
    else vciSelectedCGenotypes.at(0) = vc12;

    int iTour2FirstCGenotypeIndex = (int)((((double)rand()) / RAND_MAX) * iPopSize);
    int iTour2SecondCGenotypeIndex = (int)((((double)rand()) / RAND_MAX) * iPopSize);

    Genotype* vc21 = vciPopulation.at(iTour2FirstCGenotypeIndex);
    Genotype* vc22 = vciPopulation.at(iTour2SecondCGenotypeIndex);

    if (vc21->iFitnessFunc() >= vc22->iFitnessFunc()) vciSelectedCGenotypes.at(1) = vc21;
    else vciSelectedCGenotypes.at(1) = vc22;

    return vciSelectedCGenotypes;
}


Genotype *GeneticAlgorithm::pciGetBestSolution() {
    int iBestScore = 0;
    int iIndexOfBestSolution = -1;

    for (int i=0; i<iPopSize; i++) {
        Genotype* pciCurrentSolution = vciPopulation.at(i);
        int iCurrentScore = pciCurrentSolution->iFitnessFunc();
        if (iCurrentScore >= iBestScore) {
            iBestScore = iCurrentScore;
            iIndexOfBestSolution = i;
        }
    }
    return vciPopulation.at(iIndexOfBestSolution);
}



int GeneticAlgorithm::getIPopSize() const {
    return iPopSize;
}


