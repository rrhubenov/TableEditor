#pragma once

#include <vector>
#include <string>
#include "../table/observer.hh"

class ISubject {
    protected:
        std::vector<IObserver*> observers;

    public:
        virtual void attach(IObserver* observer) = 0;

        virtual void notify() = 0;
};

