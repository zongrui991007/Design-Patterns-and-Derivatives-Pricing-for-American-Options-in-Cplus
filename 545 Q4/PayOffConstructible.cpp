//
//  PayOffConstructible.cpp
//  ch10_factory_pattern
//
//  Created by cheerzzh on 24/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "PayOffConstructible.h"
#include "BinomialTree.h"
#include "RandomHighTree.h"
#include "RandomLowTree.h"

namespace {
    /*
    PayOffHelper<PayOffCall> RegisterCall("call");
    PayOffHelper<PayOffPut> RegisterPut("put");
    PayOffHelper<PayOffDoubleDigital> RegisterDoubleDigital("double_digital");
    */

    PayOffHelper<BTCall> RegisterBTCall("BTCall");
    PayOffHelper<BTPut> RegisterBTPut("BTPut");

    PayOffHelper<RTCallH> RegisterRTCallH("RTCallH");
    PayOffHelper<RTPutH> RegisterRTPutH("RTPutH");

    PayOffHelper<RTCallL> RegisterRTCallL("RTCallL");
    PayOffHelper<RTPutL> RegisterRTPutL("RTPutL");
}


