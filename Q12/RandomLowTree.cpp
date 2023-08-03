
#include "RandomLowTree.h"
#include "Arrays.h"
#include <cmath>

// the basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

RandomLowTree::RandomLowTree(double Spot_,
                               double r_,
                               double d_,
                               double Volatility_,
                               unsigned long Steps_,
                               double Time_,
                               double b_,
                               unsigned long NumberOfPaths_)
        :Spot(Spot_),
         r(r_),
         d(d_),
         Volatility(Volatility_),
         Steps(Steps_),
         Time(Time_),
         b(b_),
         NumberOfPaths(NumberOfPaths_){
    TreeBuilt=false;
}

void RandomLowTree::BuildTree() {
    TreeBuilt = true;
    TheTree.resize(Steps+1);
    TheTree[0].resize(1);
    TheTree[0][0].first = Spot;

    double delta_t = Time / Steps;

    for (unsigned long i=1; i <=Steps; i++){

        TheTree[i].resize(pow(b,i));
        for (unsigned long j = 0; j < pow(b,i); j++ ){
            unsigned long index = j / static_cast<unsigned long>(b);
            TheTree[i][j].first = GetGBMNextPrice(TheTree[i-1][index].first,r,d,Volatility,delta_t);
        }
    }
}
double RandomLowTree::GetThePrice(const TreeProducts& TheProduct) {

    double Sum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; ++i) {
        if (!TreeBuilt)
            BuildTree();

        if (TheProduct.GetFinalTime() != Time)
            throw("mismatched product in SimpleTrinomialTree");

        if (b != 3)
            throw("b has to be 3");

        for (unsigned long k = 0; k < pow(b, Steps); ++k) {
            TheTree[Steps][k].second = TheProduct.FinalPayOff(TheTree[Steps][k].first);
        }

        for (unsigned long j = 1; j <= Steps; ++j) {
            unsigned long x = Steps - j;
            double ThisTime = x * Time / Steps;

            for (unsigned long k = 0; k < pow(b, x); k++) {
                double h = TheProduct.FinalPayOff(TheTree[x][k].first);
                double V_u = TheTree[x + 1][3 * k].second;
                double V_m = TheTree[x + 1][3 * k + 1].second;
                double V_l = TheTree[x + 1][3 * k + 2].second;
                double U = h >= 0.5 * (V_m + V_l) ? h : V_u;
                double M = h >= 0.5 * (V_u + V_l) ? h : V_m;
                double L = h >= 0.5 * (V_u + V_m) ? h : V_l;

                TheTree[x][k].second = (U + M + L) / b;
            }
        }
        Sum += TheTree[0][0].second;
        TreeBuilt = false;
    }
    return Sum / NumberOfPaths;
}
