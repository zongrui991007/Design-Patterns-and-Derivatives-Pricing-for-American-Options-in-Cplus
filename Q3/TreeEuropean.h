

#ifndef TreeEuropean_hpp
#define TreeEuropean_hpp

#include "TreeProducts.h"
#include "PayOffBridge.h"

class TreeEuropean : public TreeProducts
{

public:

    TreeEuropean(double FinalTime,
                 const PayOffBridge& ThePayOff_);

    virtual TreeProducts* clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscountedFutureValue) const;
    virtual ~TreeEuropean(){}

private:

    PayOffBridge ThePayOff;

};

#endif /* TreeEuropean_hpp */
