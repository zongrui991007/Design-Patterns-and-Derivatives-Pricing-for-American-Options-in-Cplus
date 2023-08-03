
#ifndef OptionPricingReportWriter_hpp
#define OptionPricingReportWriter_hpp

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <ql/patterns/observable.hpp>
#include "TreeObservable.h"

typedef boost::shared_ptr<TreeObservable> pTreeObservable;

class OptionPricingReportWriter : public QuantLib::Observer {
private:
    pTreeObservable observable;
    std::string name;
public:
    OptionPricingReportWriter(std::string n) : name(n) {}

    OptionPricingReportWriter(pTreeObservable obs, std::string n)
        : observable(obs), name(n)
    {
        this->registerWith(observable);
    }

    OptionPricingReportWriter(const OptionPricingReportWriter& observer)
        : Observer(observer),
        observable(observer.observable),
        name("Copy of " + observer.name)
    {}

    void add(pTreeObservable obs) {
        observable = obs;
        this->registerWith(obs);
    }

    void update() {
        std::cout << "Option ID:"<<observable->ObservableID << ",Option Price: " << observable->TreePrice << std::endl;
    }
};
#endif /* MyObserver_hpp */

