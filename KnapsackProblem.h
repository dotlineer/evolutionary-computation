#ifndef EVO_KNAPSACKPROBLEM_H
#define EVO_KNAPSACKPROBLEM_H

#include "Problem.h"
#include "vector"

using namespace std;


class KnapsackProblem : public Problem {
public:
    KnapsackProblem(int iNoOfItems, int iWeightLimit, vector<int> &viWeights, vector<int> &viValues);
    ~KnapsackProblem();

    int getIWeightLimit();
    void setIWeightLimit(int iWeightLimit);
    int getINoOfItems();
    void setINoOfItems(int iNoOfItems);
    vector<int> &getViSizes();
    void setViSizes(vector<int> &viSizes);
    vector<int> &getViValues();
    void setViValues(vector<int> &viValues);
    Genotype* constructNewGenotype();

private:
    vector<int> viValues;
    vector<int> viWeights;
    int iNoOfItems;
    int iWeightLimit;

};



#endif //EVO_KNAPSACKPROBLEM_H
