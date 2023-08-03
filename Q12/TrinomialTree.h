//
//  TrinomialTree.hpp
//  ch8_trees
//
//  Created by Steve Yang on 10/12/21.
//

#ifndef TrinomialTree_hpp
#define TrinomialTree_hpp

#pragma warning( disable : 4786 )

#include "TreeProducts.h"
#include "Parameters.h"
#include "Arrays.h"
#include <vector>

class SimpleTrinomialTree
{

public:
    SimpleTrinomialTree(double Spot_,
                       const Parameters& r_,
                       const Parameters& d_,
                       double Volatility_,
                       unsigned long Steps,
                       double Time);
                  

    double GetThePrice(const TreeProducts& TheProduct);

protected:

    void BuildTree();

private:
  
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;

    std::vector<std::vector<std::pair<double, double> > > TheTree;
    MJArray Discounts;
};



#endif /* BinomialTree_hpp */
