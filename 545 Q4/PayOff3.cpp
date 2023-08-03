//
//  PayOff3.cpp
//  ch10_factory_pattern
//
//  Created by cheerzzh on 24/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "PayOff3.h"
#include "TreeAmerican.h"
#include <algorithm>


PayOffCall::PayOffCall(ArgumentList& args)
{
    Strike = args.GetDoubleArgumentValue("strike1");
}

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator() (double Spot) const
{
    return std::max(Spot - Strike,0.0);
}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this); // return a copy of current payoff class
}

PayOffPut::PayOffPut(ArgumentList& args)
{
    Strike = args.GetDoubleArgumentValue("strike1");
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot,0.0);
}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(* this);
}

/* BTCall */
BTCall::BTCall(ArgumentList& args, OptionPricingReportWriter& reporter)
    : Strike(args.GetDoubleArgumentValue("Strike")),
    Spot(args.GetDoubleArgumentValue("Spot")),
    r(ParametersConstant(args.GetDoubleArgumentValue("r"))),
    d(ParametersConstant(args.GetDoubleArgumentValue("d"))),
    Vol(args.GetDoubleArgumentValue("Vol")),
    Steps(args.GetULArgumentValue("Steps")),
    Expiry(args.GetDoubleArgumentValue("Expiry"))
{
    BTCallObservable = new SimpleBinomialTree(Spot, r, d, Vol, Steps, Expiry);
    BTCallObservable->ObservableID = "BTCall";
    pTreeObservable BTCallObservablePtr(BTCallObservable);
    reporter.add(BTCallObservablePtr);
}

double BTCall::operator() (double Spot) const
{
    PayOffCall thePayOffCall(Strike);
    TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
    return BTCallObservable->GetThePrice(TreeAmerCall);
}

PayOff* BTCall::clone() const
{
    return new BTCall(*this); // return a copy of current payoff class
}


/* BTPut */
BTPut::BTPut(ArgumentList& args, OptionPricingReportWriter& reporter)
    : Strike(args.GetDoubleArgumentValue("Strike")),
    Spot(args.GetDoubleArgumentValue("Spot")),
    r(ParametersConstant(args.GetDoubleArgumentValue("r"))),
    d(ParametersConstant(args.GetDoubleArgumentValue("d"))),
    Vol(args.GetDoubleArgumentValue("Vol")),
    Steps(args.GetULArgumentValue("Steps")),
    Expiry(args.GetDoubleArgumentValue("Expiry"))
{
    BTPutObservable = new SimpleBinomialTree(Spot, r, d, Vol, Steps, Expiry);
    BTPutObservable->ObservableID = "BTPut";
    pTreeObservable BTPutObservablePtr(BTPutObservable);
    reporter.add(BTPutObservablePtr);
}

double BTPut::operator() (double Spot) const
{
    PayOffPut thePayOffPut(Strike);
    TreeAmerican TreeAmerPut(Expiry, thePayOffPut);
    return BTPutObservable->GetThePrice(TreeAmerPut);
}

PayOff* BTPut::clone() const
{
    return new BTPut(*this); // return a copy of current payoff class
}

/* RTCallH */
RTCallH::RTCallH(ArgumentList& args, OptionPricingReportWriter& reporter)
    : Strike(args.GetDoubleArgumentValue("Strike")),
    Spot(args.GetDoubleArgumentValue("Spot")),
    r(ParametersConstant(args.GetDoubleArgumentValue("r"))),
    d(ParametersConstant(args.GetDoubleArgumentValue("d"))),
    Vol(args.GetDoubleArgumentValue("Vol")),
    Steps(args.GetULArgumentValue("Steps")),
    b(args.GetULArgumentValue("b")),
    Expiry(args.GetDoubleArgumentValue("Expiry")),
    n(args.GetULArgumentValue("n"))
{
    RTCallHObservable = new RandomHighTree(Spot, r, d, Vol, Steps, b, Expiry, n);
    RTCallHObservable->ObservableID = "RTCallH";
    pTreeObservable RTCallHObservablePtr(RTCallHObservable);
    reporter.add(RTCallHObservablePtr);
}

double RTCallH::operator() (double Spot) const
{
    PayOffCall thePayOffCall(Strike);
    TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
    return RTCallHObservable->GetThePrice(TreeAmerCall);
}

PayOff* RTCallH::clone() const
{
    return new RTCallH(*this); // return a copy of current payoff class
}

/* RTPutH */
RTPutH::RTPutH(ArgumentList& args, OptionPricingReportWriter& reporter)
    : Strike(args.GetDoubleArgumentValue("Strike")),
    Spot(args.GetDoubleArgumentValue("Spot")),
    r(ParametersConstant(args.GetDoubleArgumentValue("r"))),
    d(ParametersConstant(args.GetDoubleArgumentValue("d"))),
    Vol(args.GetDoubleArgumentValue("Vol")),
    Steps(args.GetULArgumentValue("Steps")),
    b(args.GetULArgumentValue("b")),
    Expiry(args.GetDoubleArgumentValue("Expiry")),
    n(args.GetULArgumentValue("n"))
{
    RTPutHObservable = new RandomHighTree(Spot, r, d, Vol, Steps, b, Expiry, n);
    RTPutHObservable->ObservableID = "RTPutH";
    pTreeObservable RTPutHObservablePtr(RTPutHObservable);
    reporter.add(RTPutHObservablePtr);
}

double RTPutH::operator() (double Spot) const
{
    PayOffPut thePayOffPut(Strike);
    TreeAmerican TreeAmerPut(Expiry, thePayOffPut);
    return RTPutHObservable->GetThePrice(TreeAmerPut);
}

PayOff* RTPutH::clone() const
{
    return new RTPutH(*this); // return a copy of current payoff class
}

/* RTCallL */
RTCallL::RTCallL(ArgumentList& args, OptionPricingReportWriter& reporter)
    : Strike(args.GetDoubleArgumentValue("Strike")),
    Spot(args.GetDoubleArgumentValue("Spot")),
    r(ParametersConstant(args.GetDoubleArgumentValue("r"))),
    d(ParametersConstant(args.GetDoubleArgumentValue("d"))),
    Vol(args.GetDoubleArgumentValue("Vol")),
    Steps(args.GetULArgumentValue("Steps")),
    b(args.GetULArgumentValue("b")),
    Expiry(args.GetDoubleArgumentValue("Expiry")),
    n(args.GetULArgumentValue("n"))
{
    RTCallLObservable = new RandomLowTree(Spot, r, d, Vol, Steps, b, Expiry, n);
    RTCallLObservable->ObservableID = "RTCallL";
    pTreeObservable RTCallLObservablePtr(RTCallLObservable);
    reporter.add(RTCallLObservablePtr);
}

double RTCallL::operator() (double Spot) const
{
    PayOffCall thePayOffCall(Strike);
    TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
    return RTCallLObservable->GetThePrice(TreeAmerCall);
}

PayOff* RTCallL::clone() const
{
    return new RTCallL(*this); // return a copy of current payoff class
}

/* RTPutL */
RTPutL::RTPutL(ArgumentList& args, OptionPricingReportWriter& reporter)
    : Strike(args.GetDoubleArgumentValue("Strike")),
    Spot(args.GetDoubleArgumentValue("Spot")),
    r(ParametersConstant(args.GetDoubleArgumentValue("r"))),
    d(ParametersConstant(args.GetDoubleArgumentValue("d"))),
    Vol(args.GetDoubleArgumentValue("Vol")),
    Steps(args.GetULArgumentValue("Steps")),
    b(args.GetULArgumentValue("b")),
    Expiry(args.GetDoubleArgumentValue("Expiry")),
    n(args.GetULArgumentValue("n"))
{
    RTPutLObservable = new RandomLowTree(Spot, r, d, Vol, Steps, b, Expiry, n);
    RTPutLObservable->ObservableID = "RTPutL";
    pTreeObservable RTPutLObservablePtr(RTPutLObservable);
    reporter.add(RTPutLObservablePtr);
}

double RTPutL::operator() (double Spot) const
{
    PayOffPut thePayOffPut(Strike);
    TreeAmerican TreeAmerPut(Expiry, thePayOffPut);
    return RTPutLObservable->GetThePrice(TreeAmerPut);
}

PayOff* RTPutL::clone() const
{
    return new RTPutL(*this); // return a copy of current payoff class
}