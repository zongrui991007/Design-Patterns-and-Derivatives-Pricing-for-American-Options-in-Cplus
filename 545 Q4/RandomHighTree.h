
#ifndef RandomHighTree_hpp
#define RandomHighTree_hpp

#pragma warning( disable : 4786 )

#include "TreeObservable.h"
#include "TreeProducts.h"
#include "Parameters.h"
#include "Arrays.h"
#include "Random.h"
#include <vector>

class RandomHighTree : public TreeObservable
{

public:
    RandomHighTree(double Spot_,
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
