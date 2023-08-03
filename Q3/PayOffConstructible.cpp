
#include "PayOffConstructible.h"

namespace {
    PayOffHelper<PayOffBTCall> RegisterBTCall("BTCall");
    PayOffHelper<PayOffBTPut> RegisterBTPut("BTPut");
    PayOffHelper<PayOffRTCallH> RegisterRTCallH("RTCallH");
    PayOffHelper<PayOffRTPutH> RegisterRTPutH("RTPutH");
    PayOffHelper<PayOffRTCallL> RegisterRTCallL("RTCallL");
    PayOffHelper<PayOffRTPutL> RegisterPayOffRTPutL("RTPutL");
}

