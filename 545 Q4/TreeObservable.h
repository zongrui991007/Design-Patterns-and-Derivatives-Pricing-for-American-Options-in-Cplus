#ifndef TreeObservable_hpp
#define TreeObservable_hpp

#include <stdio.h>
#include <ql/patterns/observable.hpp>
#include "TreeProducts.h"

class TreeObservable : public QuantLib::Observable {
public:
	std::string ObservableID;
	double TreePrice;

	virtual double GetThePrice(const TreeProducts& TheProduct) = 0;
};

#endif /* TreeObservable */
