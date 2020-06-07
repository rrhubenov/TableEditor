#pragma once

#include <vector>
#include <string>
#include "../table/observer.hh"

/*! \brief Interface for designating a class as a subject.

Hold a list of observers and notifies them for changes
based on the implementation of the child classes.
*/
class ISubject {
    protected:
        std::vector<IObserver*> observers; /*!< List of attached observers */

    public:
        virtual void attach(IObserver* observer) = 0; /*!< Add observer to the list */

        virtual void notify() = 0; /*!< Notify all observers about certain events */
};

