

#ifndef PAYOFFCONSTRUCTIBLE
#define PAYOFFCONSTRUCTIBLE


#include <iostream>
#include "ArgList.h"
#include "PayOff3.h"
#include "PayOffFactory.h"
#include "APayOff.h"
#include <string>
#include <vector>

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(std::string);
    static PayOff* Create(ArgumentList& args);
};

template <class T>
PayOff* PayOffHelper<T>::Create(ArgumentList& args)
{
    return new T(args);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create);
}


#endif 