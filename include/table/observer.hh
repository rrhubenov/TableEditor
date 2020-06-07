#pragma once

#include <string>
#include <vector>

/*! \brief Interface that describes an observer class.

Used for the Observer pattern.

Whenever an event triggers on a Subject, update() is called
and the changes are received by the observers.
*/
class IObserver {
    public:
         virtual void update(std::vector<std::string> lines) = 0; /*!< Method for the subjects to notify the observers */
};

