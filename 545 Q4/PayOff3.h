
#include "ArgList.h"
#include "BinomialTree.h"
#include "RandomHighTree.h"
#include "RandomLowTree.h"
#include "Parameters.h"
#include "OptionPricingReportWriter.h"

#ifndef __ch10_factory_pattern__PayOff3__
#define __ch10_factory_pattern__PayOff3__
class PayOff
{
public:
    
    PayOff(){};
    
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff() {}
    virtual PayOff* clone() const=0;
    
private:
    
};

class PayOffCall : public PayOff
{
public:
    
    PayOffCall(ArgumentList& args);
    PayOffCall(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall() {}
    virtual PayOff* clone() const;
    
private:
    
    double Strike;
    
};


class PayOffPut : public PayOff
{
public:
    
    PayOffPut(ArgumentList& args);
    PayOffPut(double Strike_);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut() {}
    virtual PayOff* clone() const;
    
private:
    
    double Strike;
    
};


class BTCall : public PayOff
{
public:

    BTCall(ArgumentList& args_, OptionPricingReportWriter& reporter);

    virtual double operator()(double Spot) const;
    virtual ~BTCall() {};
    virtual PayOff* clone() const;

private:
    double Strike;
    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    double Expiry;

    SimpleBinomialTree* BTCallObservable;

};

class BTPut : public PayOff
{
public:

    BTPut(ArgumentList& args_, OptionPricingReportWriter& reporter);

    virtual double operator()(double Spot) const;
    virtual ~BTPut() {};
    virtual PayOff* clone() const;

private:
    double Strike;
    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    double Expiry;

    SimpleBinomialTree* BTPutObservable;

};

class RTCallH : public PayOff
{
public:

    RTCallH(ArgumentList& args_, OptionPricingReportWriter& reporter);

    virtual double operator()(double Spot) const;
    virtual ~RTCallH() {};
    virtual PayOff* clone() const;

private:
    double Strike;
    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    unsigned long b;
    double Expiry;
    unsigned long n;

    RandomHighTree* RTCallHObservable;
};

class RTPutH : public PayOff
{
public:

    RTPutH(ArgumentList& args_, OptionPricingReportWriter& reporter);

    virtual double operator()(double Spot) const;
    virtual ~RTPutH() {};
    virtual PayOff* clone() const;

private:
    double Strike;
    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    unsigned long b;
    double Expiry;
    unsigned long n;

    RandomHighTree* RTPutHObservable;

};

class RTCallL : public PayOff
{
public:

    RTCallL(ArgumentList& args_, OptionPricingReportWriter& reporter);

    virtual double operator()(double Spot) const;
    virtual ~RTCallL() {}
    virtual PayOff* clone() const;

private:
    double Strike;
    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    unsigned long b;
    double Expiry;
    unsigned long n;

    RandomLowTree* RTCallLObservable;

};

class RTPutL : public PayOff
{
public:

    RTPutL(ArgumentList& args_, OptionPricingReportWriter& reporter);

    virtual double operator()(double Spot) const;
    virtual ~RTPutL() {}
    virtual PayOff* clone() const;

private:
    double Strike;
    double Spot;
    Parameters r;
    Parameters d;
    double Vol;
    unsigned long Steps;
    unsigned long b;
    double Expiry;
    unsigned long n;

    RandomLowTree* RTPutLObservable;

};

#endif /* defined(__ch10_factory_pattern__PayOff3__) */
