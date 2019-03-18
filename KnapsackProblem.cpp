#include "KnapsackProblem.h"


KnapsackProblem::KnapsackProblem(int iNoOfItems, int iWeightLimit, vector<int> &viWeights, vector<int> &viValues)
        : iNoOfItems(iNoOfItems), viWeights(viWeights), viValues(viValues) {
    this->iWeightLimit = iWeightLimit;
}


int KnapsackProblem::getINoOfItems()  {
    KnapsackProblem* c = new KnapsackProblem(5, 5, getViSizes(), getViValues());
    return iNoOfItems;
}

void KnapsackProblem::setINoOfItems(int iNoOfItems) {
    KnapsackProblem::iNoOfItems = iNoOfItems;
}

vector<int> &KnapsackProblem::getViSizes()  {
    return viWeights;
}

void KnapsackProblem::setViSizes(vector<int> &viSizes) {
    KnapsackProblem::viWeights = viSizes;
}

vector<int> &KnapsackProblem::getViValues()  {
    return viValues;
}

void KnapsackProblem::setViValues(vector<int> &viValues) {
    KnapsackProblem::viValues = viValues;
}


int KnapsackProblem::getIWeightLimit() {
    return iWeightLimit;
}

void KnapsackProblem::setIWeightLimit(int iWeightLimit) {
    KnapsackProblem::iWeightLimit = iWeightLimit;
}

KnapsackProblem::~KnapsackProblem() {

}

