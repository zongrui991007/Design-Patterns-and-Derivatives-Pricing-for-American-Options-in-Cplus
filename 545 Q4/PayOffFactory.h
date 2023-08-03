

#ifndef __ch10_factory_pattern__PayOffFactory__
#define __ch10_factory_pattern__PayOffFactory__

#include "PayOff3.h"

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include "ArgList.h"
#include "OptionPricingReportWriter.h"
#include <map>
#include <string>
#include <vector>

class PayOffFactory
{
public:
    typedef PayOff*  (*CreatePayOffFunction)(ArgumentList& args, OptionPricingReportWriter& reporter);
    
    static PayOffFactory& Instance();
    void RegisterPayOff(std::string, CreatePayOffFunction);
   
    PayOff* CreatePayOff(std::string PayOffID, ArgumentList& args, OptionPricingReportWriter& reporter);
    ~PayOffFactory(){};
    
private:
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator = (const PayOffFactory&){return *this;}
};

#endif /* defined(__ch10_factory_pattern__PayOffFactory__) */
