
#include <ql/quantlib.hpp>

#include "ArgList.h"
#include "PayOff3.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include "RandomHighTree.h"
#include "RandomLowTree.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{

    double Expiry = 1;
    double Strike = 50;
    double Spot = 50;
    double Vol = 0.3;
    double r = 0.05;
    double d = 0.08;
    double b = 3;
    double  n= 100;
    double Steps = 3;

    ArgumentList args("my_args");
    args.add("Expiry", Expiry);
    args.add("Strike", Strike);
    args.add("Spot", Spot);
    args.add("Vol", Vol);
    args.add("r", r);
    args.add("d", d);
    args.add("b", b);
    args.add("n", n);
    args.add("Steps", Steps);

    OptionPricingReportWriter reporter("Option Price Reporter");

    vector<string> names = { "BTCall", "BTPut" , "RTCallH", "RTPutH", "RTCallL", "RTPutL"};

    for (string name : names) {
        
        boost::shared_ptr<PayOff> PayOffPtr(PayOffFactory::Instance().CreatePayOff(name, args, reporter));

        if (PayOffPtr != NULL)
        {
            PayOffPtr->operator ()(Spot);
        }
    }
 
    return 0;
}
