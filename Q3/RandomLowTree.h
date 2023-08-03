

#ifndef RANDOMLOWTREE
#define RANDOMLOWTREE

#pragma warning( disable : 4786 )

#include "TreeProducts.h"
#include <vector>
#include"Random.h"

class RandomLowTree {
public:
    RandomLowTree(double Spot_,
                   double r_,
                   double d_,
                   double Volatility_,
                   unsigned long Steps_,
                   double Time_,
                   double b_,
                   unsigned long NumberOfPaths_);


    double GetThePrice(const TreeProducts& TheProduct);
    std::vector<std::vector<std::pair<double, double> > > TheTree;

protected:

    void BuildTree();


private:

    double Spot;
    double r;
    double d;
    double Volatility;
    unsigned long Steps;
    double Time;
    double b;
    unsigned long NumberOfPaths;
    bool TreeBuilt;

};


#endif //RANDOMLOWTREE
