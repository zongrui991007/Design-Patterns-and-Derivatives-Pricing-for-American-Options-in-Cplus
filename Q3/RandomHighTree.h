

#ifndef RANDOMHIGHTREE_H
#define RANDOMHIGHTREE_H

#pragma warning( disable : 4786 )

#include "TreeProducts.h"
#include <vector>
#include"Random.h"

class RandomHighTree {
public:
    RandomHighTree(double Spot_,
                        double r_,
                        double d_,
                        double Volatility_,
                        unsigned long Steps_,
                        double Time_,
                        double b_,
                        unsigned long NumberOfPaths_);


    double GetThePrice(const TreeProducts& TheProduct);

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
    std::vector<std::vector<std::pair<double, double> > > TheTree;

};


#endif 