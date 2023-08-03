//
//  main.cpp
//  ch8_trees
//
//  Created by Steve Yang on 10/12/21.
//

/*
requires
    Arrays.cpp
    BinomialTree.cpp
    BlackScholesFormulas.cpp
    Normals.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffForward.cpp
    TreeAmerican.cpp
    TreeEuropean.cpp
    TreeMain.cpp
    TreeProducts.cpp
  */
#include <iostream>
#include "BinomialTree.h"
#include "RandomLowTree.h"
#include "RandomHighTree.h"

#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"

using namespace std;
#include <cmath>
int main()
{

    double Expiry = 1;
    double Strike = 50;
    double Spot = 50;
    double Vol = 0.3;
    double r = 0.05;
    double d = 0.08;
    double b = 3;
    double n = 100;
    unsigned long Steps;

    cout << "\nNumber of steps\n";
    cin >> Steps;

    // Create a PayOff objects for Call and Put Options
    PayOffCall thePayOffCall(Strike);
	PayOffPut thePayOffPut(Strike);

    // Create a risk free rate ParametersConstant
    ParametersConstant rParam(r);

    // Create a dividend ParametersConstant
    ParametersConstant dParam(d);

    // Create a TreeEuropean object
	TreeEuropean TreeEuroCall(Expiry,thePayOffCall);
	TreeEuropean TreeEuroPut(Expiry, thePayOffPut);

    // Create a TreeAmerican object
	TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
	TreeAmerican TreeAmerPut(Expiry, thePayOffPut);

    // Create one BinomialTree object
	SimpleBinomialTree BinomTree(Spot,rParam,dParam,Vol,Steps, Expiry);

    // Create one TrinomialTree object
    RandomHighTree1 RandomHighTree(Spot, r, d, Vol, Steps, Expiry, b, n);

    RandomLowTree RandomLowTree(Spot, r, d, Vol, Steps, Expiry, b, n);


    double americanCallPriceBi = 0.0;
    double americanPutPriceBi = 0.0;
    double americanCallPriceRandH = 0.0;
    double americanPutPriceRandH = 0.0;
    double americanCallPriceRandL = 0.0;
    double americanPutPriceRandL = 0.0;

    // Calculate American Option price
    americanCallPriceBi = BinomTree.GetThePrice(TreeAmerCall);
    americanPutPriceBi = BinomTree.GetThePrice(TreeAmerPut);
    americanCallPriceRandH = RandomHighTree.GetThePrice(TreeAmerCall);
    americanCallPriceRandL = RandomLowTree.GetThePrice(TreeAmerCall);


    americanPutPriceRandH = RandomHighTree.GetThePrice(TreeAmerPut);
    americanPutPriceRandL = RandomLowTree.GetThePrice(TreeAmerPut);


    std::cout << "Binomial Tree: " << "American Call Option Price =" << americanCallPriceBi << endl;
    std::cout << "Binomial Tree: " << "American Put Option Price =" << americanPutPriceBi << endl;

    std::cout << "Random High Tree: " << "American Call Option Price =" << americanCallPriceRandH<< endl;
    std::cout << "Random High Tree: " << "American Put Option Price =" << americanPutPriceRandH << endl;

    std::cout << "Random Low Tree: " << "American Call Option Price =" << americanCallPriceRandL << endl;
    std::cout << "Random Low Tree: " << "American Put Option Price =" << americanPutPriceRandL << endl;


}

