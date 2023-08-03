

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include "PayOffFactory.h"
#include <iostream>
using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId,
                                   CreatePayOffFunction CreatorFunction)
{
    // add one map: sting <-> payoff
    TheCreatorFunctions.insert(pair<string,CreatePayOffFunction>
                               (PayOffId,CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId,
                                    ArgumentList& args,
                                    OptionPricingReportWriter& reporter)
{
    map<string, CreatePayOffFunction>::const_iterator
    i = TheCreatorFunctions.find(PayOffId); 
    if  (i == TheCreatorFunctions.end())
    {
        std::cout << PayOffId
        << " is an unknown payoff" << std::endl;
        return NULL;
    }
    return (i->second)(args, reporter); 
}



PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}


