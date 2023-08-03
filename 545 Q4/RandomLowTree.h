
#ifndef RandomLowTree_hpp
#define RandomLowTree_hpp

#pragma warning( disable : 4786 )

#include "TreeObservable.h"
#include "TreeProducts.h"
#include "Parameters.h"
#include "Arrays.h"
#include "Random.h"
#include <vector>

class RandomLowTree : public TreeObservable
{

public:
    RandomLowTree(double Spot_,
        const Parameters& r_,
        const Parameters& d_,
        double Vol_,
        unsigned long Steps,
        unsigned long b,
        double Expiry,
        unsigned long n);


    double GetThePrice(const TreeProducts& TheProduct);

protected:

    void BuildTree();

private:

    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    unsigned long b;
    double Expiry;
    unsigned long n;
    bool TreeBuilt;

    std::vector<std::vector<std::pair<double, double> > > TheTree;
};



#endif /* BinomialTree_hpp */
