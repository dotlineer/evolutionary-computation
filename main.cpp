#include <iostream>
#include "vector"
using namespace std;

#include "KnapsackProblem.h"
#include "Individual.h"
#include "GeneticAlgorithm.h"
#include "IndividualBridge.h"


void vDemo0() {
    srand(time(NULL));

    vector<int> viWeights = {70, 73, 77, 80, 82, 87, 90, 94, 98, 106, 110, 113, 115, 118, 120};
    vector<int> viValues = {135, 139, 149, 150, 156, 163, 173, 184, 192, 201, 210, 214, 221, 229, 240};
    KnapsackProblem* ckp0 = new KnapsackProblem(15, 750, viWeights, viValues); // 1458


    GeneticAlgorithm* cga0 = new GeneticAlgorithm(10, 0.6, 0.1, ckp0);
    initAPopulationOfCInd(ckp0, cga0);


    cout << "Running..." << endl;
    cga0->vRun(100);
    delete ckp0;
    delete cga0;
}



int main() {
    vDemo0();
    return 0;
}