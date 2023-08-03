
#ifndef __ch7_exotics_engine_and_template_pattern__PayOffBridge__
#define __ch7_exotics_engine_and_template_pattern__PayOffBridge__

#include "PayOff3.h"

class PayOffBridge
{
public:
    
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
private:
    
    PayOff* ThePayOffPtr;
    
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr->operator ()(Spot);
}

#endif /* defined(__ch7_exotics_engine_and_template_pattern__PayOffBridge__) */
