#include "RandomLowTree.h"
#include "Arrays.h"
#include <cmath>

// the basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

RandomLowTree::RandomLowTree(double Spot_,
    const Parameters& r_,
    const Parameters& d_,
    double Vol_,
    unsigned long Steps_,
    unsigned long b_,
    double Expiry_,
    unsigned long n_)
    : Spot(Spot_),
    r(r_),
    d(d_),
    Vol(Vol_),
    Steps(Steps_),
    b(b_),
    Expiry(Expiry_),
    n(n_)
{
    TreePrice = -1;
    TreeBuilt = false;
}



void RandomLowTree::BuildTree()
{
    TreeBuilt = true;
    TheTree.resize(Steps + 1);
    TheTree[0].resize(1);
    TheTree[0][0].first = Spot;

    for (unsigned long i = 1; i <= Steps; i++)
    {
        TheTree[i].resize(pow(b, i));

        for (unsigned long j = 0; j < pow(b, i); j++)
        {
            TheTree[i][j].first = GetGBMNextPrice(TheTree[i - 1][j / b].first, r.Integral(0, 1), d.Integral(0, 1), Vol, Expiry/ Steps);
        }
    }
}

double RandomLowTree::GetThePrice(const TreeProducts& TheProduct)
{
    double sum = 0;
    for (unsigned long iter = 0; iter < n; iter++) {
        if (!TreeBuilt)
            BuildTree();

        if (TheProduct.GetFinalTime() != Expiry)
            throw("mismatched product in RandomLowTree");

        for (unsigned long j = 0; j < pow(b, Steps); j++)
            TheTree[Steps][j].second = TheProduct.FinalPayOff(TheTree[Steps][j].first);

        for (int i = Steps - 1; i >= 0; i--)
        {
            double ThisTime = Expiry/ Steps;

            for (long j = 0; j < pow(3, i); j++)
            {
                double h = TheProduct.FinalPayOff(TheTree[i][j].first);

                double future_sum = 0;
                for (int k = 0; k < 3; k++) {
                    future_sum += TheTree[i + 1][3 * j + k].second;
                }
                
                TheTree[i][j].second = 0;
                for (int k = 0; k < 3; k++) {
                    double vj = TheTree[i + 1][3 * j + k].second;
                    TheTree[i][j].second += h > (future_sum - vj) / 3 ? h : vj;
                }
                
                TheTree[i][j].second /= 3;
            }
        }
        sum += TheTree[0][0].second;
        TreeBuilt = false;
    }
    TreePrice = sum / n;
    notifyObservers();
    return TreePrice;
}
