
#ifndef APAYOFF
#define APAYOFF

#include "PayOff3.h"
#include "ArgList.h"
#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "RandomHighTree.h"
#include "RandomLowTree.h"


class PayOffBTCall : public PayOff{
public:
    PayOffBTCall(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffBTCall(){}
    virtual PayOff* clone() const;

private:
    double Expiry;
    double Strike;
    double Vol ;
    double r;
    double d;
    unsigned long Steps;
};

class PayOffBTPut : public PayOff{
public:
    PayOffBTPut(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffBTPut(){}
    virtual PayOff* clone() const;

private:
    double Expiry;
    double Strike;
    double Vol ;
    double r;
    double d;
    unsigned long Steps;
};

class PayOffRTPutH:public PayOff{
public:
    PayOffRTPutH(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffRTPutH(){}
    virtual PayOff* clone() const;

private:
    double Expiry;
    double Strike;
    double Vol ;
    double r;
    double d;
    unsigned long Steps;
    double b;
    unsigned long NumberOfPaths;
};

class PayOffRTCallH:public PayOff{
public:
    PayOffRTCallH(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffRTCallH(){}
    virtual PayOff* clone() const;

private:
    double Expiry;
    double Strike;
    double Vol ;
    double r;
    double d;
    unsigned long Steps;
    double b;
    unsigned long NumberOfPaths;
};

class PayOffRTCallL:public PayOff{
public:
    PayOffRTCallL(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffRTCallL(){}
    virtual PayOff* clone() const;

private:
    double Expiry;
    double Strike;
    double Vol ;
    double r;
    double d;
    unsigned long Steps;
    double b;
    unsigned long NumberOfPaths;
};

class PayOffRTPutL:public PayOff{
public:
    PayOffRTPutL(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffRTPutL(){}
    virtual PayOff* clone() const;

private:
    double Expiry;
    double Strike;
    double Vol ;
    double r;
    double d;
    unsigned long Steps;
    double b;
    unsigned long NumberOfPaths;
};

#endif 
