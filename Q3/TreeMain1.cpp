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
#include "ArgList.h"
#include "PayOffFactory.h"
#include "PayOffConstructible.h"
#include <string>


using namespace std;
#include <cmath>
int main()
{

    double Expiry = 1;
    double Strike = 50;
    double Spot=50;
    double Vol = 0.3;
    double r = 0.05;
    double d = 0.08;
    double b = 3;
    unsigned long n = 100;
    unsigned long Steps=3;
   
    
   
    cout << "\nFE545 Number of steps Input\n";
    cin >> Steps;

    std::string name;
    ArgumentList args("myArgs");
    args.add("strike", Strike);
    args.add("expiry",Expiry);
    args.add("vol",Vol);
    args.add("r",r);
    args.add("d",d);
    args.add("steps",Steps);
    args.add("b",b);
    args.add("number_of_paths",n);

    cout << "\npay-off name (BTCall,BTPut,RTCallH,RTCallL,RTPutH,RTPutL)\n";
    cin >> name;

    PayOff* PayOffPtr =
            PayOffFactory::Instance().CreatePayOff(name,args);

    if (PayOffPtr != NULL)
    {
        
        cout << "\n" << PayOffPtr->operator ()(Spot) << "\n";
        delete PayOffPtr;
    }


    double tmp;
    cin >> tmp;

    return 0;
    

}
