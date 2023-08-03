
#include "RandomHighTree.h"
#include "Arrays.h"
#include <cmath>
#if !defined(_MSC_VER)
using namespace std;
#endif
RandomHighTree1::RandomHighTree1(double Spot_,
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
void RandomHighTree1::BuildTree() {
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
double RandomHighTree1::GetThePrice(const TreeProducts &TheProduct) {

    double Sum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; ++i) {
        if (!TreeBuilt)
            BuildTree();

        for (unsigned long j = 0; j < pow(b,Steps); ++j) {
            TheTree[Steps][j].second = TheProduct.FinalPayOff(TheTree[Steps][j].first);
        }

        for (unsigned long j = 1; j <= Steps ; ++j) {
            unsigned long x = Steps-j;
            double RHTtime = x*Time/Steps;

            for (unsigned long k = 0; k < pow(b,x); k++ ){
                double Spot = TheTree[x][k].first;
                double current_sum = 0;
                for (int p = 0; p < b; p++) {
                    current_sum += (TheTree[x + 1][b * k + p]).second;

                }
                   
                double mean = (1.0 / b) * current_sum;
                TheTree[x][k].second = TheProduct.PreFinalValue(Spot,RHTtime,mean);
            }
        }
        Sum += TheTree[0][0].second;
        TreeBuilt = false;
    }
    return Sum/NumberOfPaths;
}
